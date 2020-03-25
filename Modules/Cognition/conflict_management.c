
#include "cognition_core.h"

extern cognition_t cog;

static bool CheckSafeToTurn(double fromHeading, double toHeading);

void SetGuidanceVelCmd(double track,double gs,double vs){
      double vn = gs*cos(track* M_PI/180);
      double ve = gs*sin(track* M_PI/180);
      double vu = vs;
      cog.guidanceCommand = cVECTOR;
      cog.cmdparams[0] = vn;
      cog.cmdparams[1] = ve;
      cog.cmdparams[2] = vu;
      cog.sendCommand = true;
 }

void SetGuidanceFlightPlan(char name[],int nextWP){
  cog.Plan0 = false;
  cog.Plan1 = false;
  cog.sendCommand = true;
  if(strcmp(name,"Plan0") == 0){
     cog.guidanceCommand = cPRIMARY_FLIGHTPLAN;
     cog.nextPrimaryWP = nextWP;
     cog.Plan0 = true;
  }else if(strcmp(name,"Plan1") == 0){
     cog.guidanceCommand = cSECONDARY_FLIGHTPLAN;
     cog.nextSecondaryWP = nextWP;
     cog.Plan1 = true;
  }
  cog.nextWP = nextWP;
  strcpy(cog.currentPlanID,name);
}

void SetGuidanceP2P(double lat,double lon,double alt,double speed){
   cog.guidanceCommand = cPOINT2POINT;
   cog.cmdparams[0] = lat;
   cog.cmdparams[1] = lon;
   cog.cmdparams[2] = alt;
   cog.cmdparams[3] = speed; 
   cog.sendCommand = true;
}

void SendStatus(char buffer[],uint8_t severity){
   strcpy(cog.statusBuf,buffer); 
   cog.sendStatusTxt = true;
   cog.statusSeverity = severity;
}

bool GeofenceConflictManagement(){
   bool geofenceConflict = (cog.keepInConflict || cog.keepOutConflict) && !cog.trafficConflict;
   switch(cog.geofenceConflictState){

      case NOOPC:{
         if(geofenceConflict){
            SendStatus("IC: Geofence conflict detected",1);
            cog.geofenceConflictState = INITIALIZE;
            cog.requestGuidance2NextWP = -1;
            cog.return2NextWPState = NOOPC;
           break;
         }
         return false;
      }

      case INITIALIZE:{
         //TODO: Get recovery position
         SetGuidanceP2P(cog.recoveryPosition[0],cog.recoveryPosition[1],cog.recoveryPosition[2],cog.resolutionSpeed);
         cog.geofenceConflictState = RESOLVE;
         cog.p2pcomplete = false;
         break;
      }

      case RESOLVE:{
         // Wait for confirmation
         bool val = cog.p2pcomplete;

         if(val){
            cog.geofenceConflictState = COMPLETE;
         }
         break;
      }

      case COMPLETE:{
         // TODO: Fly to next waypoint
         cog.requestGuidance2NextWP = 1;
         cog.geofenceConflictState = NOOPC;
         cog.return2NextWPState = NOOPC;
         SendStatus("IC:Geofence resolution complete",6);
         break;
      }

      case COMPUTE:{
         break;
      }
   } 

   return true;
}

bool XtrackManagement(){

   bool XtrackConflict,XtrackConflict1, XtrackConflict2;

   double offset1[2];
   double offset2[2];
   cog.xtrackDeviation1 = ComputeXtrackDistance(cog.wpPrev1,cog.wpNext1,cog.position,offset1);
   cog.xtrackDeviation2 = ComputeXtrackDistance(cog.wpPrev2,cog.wpNext2,cog.position,offset2);

   XtrackConflict1 = (fabs(cog.xtrackDeviation1) > cog.allowedXtrackDev1);
   XtrackConflict2 = (fabs(cog.xtrackDeviation2) > cog.allowedXtrackDev2);

   double interceptManeuver[3];
   if(cog.Plan0){
      XtrackConflict = XtrackConflict1;
      ManueverToIntercept(cog.wpPrev1,cog.wpNext1,cog.position,interceptManeuver,cog.xtrkGain,cog.resolutionSpeed,cog.allowedXtrackDev1);
   }else if(cog.Plan1){
      XtrackConflict = XtrackConflict2;
      ManueverToIntercept(cog.wpPrev1,cog.wpNext1,cog.position,interceptManeuver,cog.xtrkGain,cog.resolutionSpeed,cog.allowedXtrackDev2);
   }

   bool conflict = XtrackConflict && (cog.trafficConflictState == NOOPC) && (cog.requestGuidance2NextWP == 0);

   switch (cog.XtrackConflictState) {
      case NOOPC:{
         if(conflict){
            SendStatus("IC:xtrack conflict",1);
            cog.XtrackConflictState = INITIALIZE;
            break;
         }
         return false;
      }

      case INITIALIZE:{
         // Send appropriate mode change command to guidance module
         cog.XtrackConflictState = RESOLVE;
         break;
      }

      case RESOLVE:{
         // Send velocity command to guidance
         SetGuidanceVelCmd(interceptManeuver[0],interceptManeuver[1],interceptManeuver[2]);
         if(!XtrackConflict){
            cog.XtrackConflictState = COMPLETE;
         }
         break;
      }

      case COMPLETE:{
         //Continue on with current mission
         cog.XtrackConflictState = NOOPC;
         cog.return2NextWPState = NOOPC;
         if(cog.Plan0){
            SetGuidanceFlightPlan("Plan0",cog.nextPrimaryWP);
         }else if(cog.Plan1){
            SetGuidanceFlightPlan("Plan1",cog.nextSecondaryWP);
         }
         SendStatus("IC:xtrack conflict resolved",6);
         
         break;
      }

      case COMPUTE:{
         break;
      }
   }

   return true;
}

bool TrafficConflictManagement(){

   // Check for traffic conflict 
   cog.trafficConflict = cog.trafficSpeedConflict |
                                cog.trafficAltConflict |
                                cog.trafficTrackConflict;

   switch(cog.trafficConflictState){
      case NOOPC:{
         if(cog.trafficConflict){
            SendStatus("IC:traffic conflict",1);
            cog.trafficConflictState = INITIALIZE;             
            cog.requestGuidance2NextWP = -1;
            break;
         }
         return false;
      } 

      case INITIALIZE:{
         cog.trafficConflictState = RESOLVE;        
         GetResolutionType();

         // Use this only for search based resolution
         if(cog.resolutionTypeCmd == SEARCH_RESOLUTION){
            cog.return2NextWPState = INITIALIZE;
         }
         break;
      }

      case RESOLVE:{
         if(cog.resolutionTypeCmd == SEARCH_RESOLUTION){
            // Only for search based resolution
            if(cog.return2NextWPState != NOOPC){
               ReturnToNextWP();
            }else{
               cog.trafficConflictState = NOOPC;
            }
         }else{
            if(!RunTrafficResolution()){
               cog.trafficConflictState = COMPLETE;
            }
         }

         break;
      }

      case COMPLETE:{
         cog.requestGuidance2NextWP = 1;
         if(cog.requestGuidance2NextWP == 0 && cog.Plan0 && cog.fp1ClosestPointFeasible){
            cog.trafficConflictState = NOOPC;
         }else if(cog.requestGuidance2NextWP == 0 && cog.Plan1 && cog.fp2ClosestPointFeasible){
            cog.trafficConflictState = NOOPC;
         }else if(cog.requestGuidance2NextWP == 1){
            cog.trafficConflictState = NOOPC;
         }else{
            cog.requestGuidance2NextWP = -1;
         }
         SendStatus("IC:traffic conflict resolved",6);
         cog.return2NextWPState = NOOPC;
         break;
      }

      case COMPUTE:{
         break;
      }
   }

   return true;
}

bool RunTrafficResolution(){
   switch(cog.resolutionTypeCmd){

      case SPEED_RESOLUTION:{
         double speedPref = cog.preferredSpeed;

         //printf("resolution speed = %f\n",speedPref);
         if(speedPref >= 0){
            SetGuidanceVelCmd(cog.hdg,speedPref,0);
            cog.prevResSpeed = speedPref;
         }else{
            SetGuidanceVelCmd(cog.hdg,cog.prevResSpeed,0);
         }

         bool val;
         if(cog.Plan0){
            val = cog.nextWPFeasibility1;
         }else if(cog.Plan1){
            val = cog.nextWPFeasibility2;
         }
         cog.returnSafe = val;
         break;
      }

      case ALTITUDE_RESOLUTION:{
         double climbRate = 0.0;
         double diff;

         double currentAlt = cog.position[2];
         double altPref = cog.preferredAlt;

         diff = altPref - currentAlt;
         //printf("preferred altitude: %f\n",altPref);
         if(diff > -1e2 && diff < 1e2){

            if(diff > 50){
               diff = 50;  
            }else if(diff < -50){
               diff = -50;
            }

            climbRate = -0.1*diff;
            double speed = cog.resolutionSpeed;
            SetGuidanceVelCmd(cog.hdg,speed,climbRate);
            cog.prevResVspeed = climbRate;
            //printf("climb rate = %f,diff = %f\n",climbRate,diff);
         }else if(altPref > -1000 && altPref < 0){
            double speed = cog.resolutionSpeed; 
            SetGuidanceVelCmd(cog.hdg,speed,0);
         }else{

         }


         bool val;
         if(cog.Plan0){
            val = cog.nextWPFeasibility1;
         }else if(cog.Plan1){
            val = cog.nextWPFeasibility2;
         }
         cog.returnSafe = val;
         break;
      }

      case TRACK_RESOLUTION:{
         //printf("executing traffic resolution\n");
         double prefTrack = cog.preferredTrack;
         double speed = cog.resolutionSpeed;
         double climbrate = 0;
         if(prefTrack > 0){
            SetGuidanceVelCmd(prefTrack,speed,climbrate);
            cog.prevResTrack = prefTrack;
         }else if(prefTrack > -10000){
            SetGuidanceVelCmd(cog.prevResTrack,speed,climbrate);
         }else{

         }

         if(cog.Plan0){
            double interceptHeadingToPlan = GetInterceptHeadingToPlan(cog.wpPrev1,cog.wpNext1,cog.position);
            cog.returnSafe = CheckSafeToTurn(cog.hdg,interceptHeadingToPlan);
         }else if(cog.Plan1){
            double interceptHeadingToPlan = GetInterceptHeadingToPlan(cog.wpPrev2,cog.wpNext2,cog.position);
            cog.returnSafe = CheckSafeToTurn(cog.hdg,interceptHeadingToPlan);
         }

         if(!cog.returnSafe){
            SetGuidanceVelCmd(cog.prevResTrack,speed,0);
         }else{
            //printf("return safe\n");
         }

         break;
      }

      case VERTICALSPEED_RESOLUTION:{
         double speed = cog.resolutionSpeed;
         double resUp = cog.resVUp;
         double resDown = cog.resVDown;
         // If there is a valid up resolution, execute up resolution.
         // else execute the down resolution. If 0 vertical speed is possible,
         // that is preferred over the up or down resolutions.
         if(!isinf(resUp) && !isnan(resUp)){
            if(resUp >= 1e-3){
                  SetGuidanceVelCmd(cog.hdg,speed,-resUp);
                  cog.prevResVspeed = resUp;
                  printf("preferred vspeed: %f\n",-resUp);
            }else{
               SetGuidanceVelCmd(cog.hdg,speed,0.0);
               cog.prevResVspeed = 0.0;
               printf("preferred vspeed: %f\n",0.0);
            }
         }else if(!isinf(resDown) && !isnan(resDown)){
            if(resDown <= -1e-3){
                  SetGuidanceVelCmd(cog.hdg,speed,-resDown);
                  cog.prevResVspeed = resDown;
                  printf("preferred vspeed: %f\n",-resDown);
            }else{
               SetGuidanceVelCmd(cog.hdg,speed,0.0);
               cog.prevResVspeed = 0.0;
               printf("preferred vspeed: %f\n",0.0);
            }
         }else{
            SetGuidanceVelCmd(cog.hdg,speed,cog.prevResVspeed);
         }
         
         uint8_t val;
         if(cog.vsBandsNum > 0){
            val = 0;
         }else{
            val = 1;
         }

         //printf("Return safe: %d\n\n",val);
         cog.returnSafe = (bool) val;
         break;
      }

      default:{

         break;
      }
   }    
   cog.trafficConflict |= (!cog.returnSafe);
   return cog.trafficConflict;
}

bool ReturnToNextWP(){

   //Set this as the current mission wp
   switch(cog.return2NextWPState){

      case NOOPC:{

         if (cog.keepInConflict || cog.keepOutConflict || cog.trafficConflict){
            return false;
         }

         if(cog.requestGuidance2NextWP == 1){
            cog.return2NextWPState = INITIALIZE;
            break;
         }
         return false;
      }

      case INITIALIZE:{

         int nextWP;
         bool directPath;
         cog.fp2complete = false;
         nextWP = cog.nextFeasibleWP1;
         cog.return2NextWPState = COMPUTE;
         cog.request = REQUEST_NIL;
         break;
      }

      case COMPUTE:
      {
         if (cog.request == REQUEST_NIL)
         {
            // Compute a secondary path
            int nextWP;
            double positionB[3];
            if(cog.Plan0){
               nextWP = cog.nextFeasibleWP1;
               memcpy(positionB,cog.wpNextFb1,sizeof(double)*3);
            }else if(cog.Plan1){
               nextWP = cog.nextFeasibleWP2;
               memcpy(positionB,cog.wpNextFb2,sizeof(double)*3);
            }

            double positionA[3] = {cog.position[0],
                                   cog.position[1],
                                   cog.position[2]};

            double Trk, Gs, Vs;
            ConvertVnedToTrkGsVs(cog.velocity[0], 
                                 cog.velocity[1],
                                 cog.velocity[2], 
                                 &Trk, &Gs, &Vs);

            double velocityA[3] = {Trk,Gs,Vs};

            
            FindNewPath(cog.searchType, positionA, velocityA, positionB);
            cog.request = REQUEST_PROCESSING;
            SendStatus("IC:Computing secondary path",6);
         }
         else if (cog.request == REQUEST_RESPONDED)
         {
            cog.request = REQUEST_NIL;
            cog.return2NextWPState = RESOLVE;
            cog.fp2complete = false;
            SetGuidanceFlightPlan("Plan1",1);  
         }else{

         }
         break;
      }

      case RESOLVE:{
         // Execute the secondary path

         bool val = cog.fp2complete;
         if(val){
            cog.return2NextWPState = COMPLETE;
         }
         break;
      }

      case COMPLETE:{

         cog.return2NextWPState = NOOPC;
         cog.requestGuidance2NextWP = -1;
         if(cog.nextFeasibleWP1 + 1 < cog.num_waypoints){
            SetGuidanceFlightPlan("Plan0",cog.nextFeasibleWP1+1);
         }else{
            cog.nextPrimaryWP = cog.nextFeasibleWP1 + 1;  
         }
         SendStatus("IC:Resuming mission",6);
         break;
      }
   }
   return true;
}

static bool CheckSafeToTurn(double fromHeading, double toHeading) {
   bool conflict = false;
   for (int i = 0; i < cog.trkBandNum; i++)
   {
      bool val;
      val = CheckTurnConflict(cog.trkBandMin[i],
                              cog.trkBandMax[i],
                              fromHeading, toHeading);
      conflict |= val;
   }

   if(cog.Plan0)
      conflict |= !cog.nextWPFeasibility1;
   else if(cog.Plan1)
      conflict |= !cog.nextWPFeasibility2;

   return !conflict;
}

void FindNewPath(uint8_t searchType, double positionA[],double velocityA[],double positionB[]){
    cog.pathRequest = true;
    cog.searchType = searchType;
    memcpy(cog.startPosition,positionA,sizeof(double)*3);
    memcpy(cog.startVelocity,velocityA,sizeof(double)*3);
    memcpy(cog.stopPosition,positionB,sizeof(double)*3);
}

void GetResolutionType(){
   //
}


bool TimeManagement(){

   size_t nextWP = cog.nextWP;
   if(!cog.wpMetricTime){
      return false;
   }
   double currPosition[3],nextPosition[3];
   memcpy(currPosition,cog.position,sizeof(double)*3);
   memcpy(nextPosition,cog.wpNext1,sizeof(double)*3);

   double dist2NextWP = ComputeDistance(currPosition,nextPosition);
   double currentSpeed = sqrt(cog.velocity[0]*cog.velocity[0] + 
                              cog.velocity[1]*cog.velocity[1] + 
                              cog.velocity[2]*cog.velocity[2]);
   time_t currTime = time(NULL);
   time_t scenarioTime = cog.scenarioTime;
   time_t nextWP_STA = scenarioTime + (long)cog.refWPTime;
   time_t nextWP_ETA = currTime + dist2NextWP/currentSpeed;
   double arrTolerance = 3; //TODO: Make this a user defined parameter
   double maxSpeed = 7;     //TODO: Make parameter
   double minSpeed = 0.5;   //TODO: Make parameter
   double newSpeed;

   if (labs(nextWP_STA - nextWP_ETA) > arrTolerance){
      newSpeed = dist2NextWP/(nextWP_STA - currTime);
      if (newSpeed > maxSpeed){
         newSpeed = maxSpeed;
      }else{
         if(newSpeed < minSpeed){
            newSpeed = minSpeed;
         }
      }


      cog.guidanceCommand = cSPEED_CHANGE;
      cog.cmdparams[0] = newSpeed;
      cog.sendCommand = true;
      
      return true;
   }
   return false;
}