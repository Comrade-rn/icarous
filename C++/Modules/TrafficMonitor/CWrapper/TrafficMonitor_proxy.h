/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.6
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */
#ifndef _TrafficMonitor_proxy_H_
#define _TrafficMonitor_proxy_H_

/* -----------------------------------------------------------------------------
 * cproxy.swg
 *
 * Definitions of C specific preprocessor symbols for proxies.
 * ----------------------------------------------------------------------------- */

#ifndef SWIGIMPORT
# ifndef __GNUC__
#   define __DLL_IMPORT __declspec(dllimport)
# else
#   define __DLL_IMPORT __attribute__((dllimport)) extern
# endif
# if !defined (__WIN32__)
#   define SWIGIMPORT extern
# else
#   define SWIGIMPORT __DLL_IMPORT
# endif
#endif

#include <stdio.h>

typedef struct {
  void *obj;
  const char **typenames;
} SwigObj;


// special value indicating any type of exception like 'catch(...)'
#define SWIG_AnyException "SWIG_AnyException"

#include <setjmp.h>

SWIGIMPORT jmp_buf SWIG_rt_env;

SWIGIMPORT struct SWIG_exc_struct {
  int code;
  char *msg;
  SwigObj *klass;
} SWIG_exc;

SWIGIMPORT void SWIG_rt_try();
SWIGIMPORT int SWIG_rt_catch(const char *type);
SWIGIMPORT void SWIG_rt_throw(SwigObj *klass, const char * msg);
SWIGIMPORT int SWIG_rt_unhandled();
SWIGIMPORT void SWIG_rt_endtry();
SWIGIMPORT int SWIG_exit(int code);

#define SWIG_try \
  SWIG_rt_try(); \
  if ((SWIG_exc.code = setjmp(SWIG_rt_env)) == 0) 
#define SWIG_catch(type) else if (SWIG_rt_catch(#type))
#define SWIG_throw(klass) SWIG_rt_throw((SwigObj *) klass, 0);
#define SWIG_throw_msg(klass, msg) SWIG_rt_throw((SwigObj *) klass, msg);
#define SWIG_endtry else SWIG_rt_unhandled(); SWIG_rt_endtry();



#include <stdarg.h>

#define SWIG_MAKE_DELETE(Name,Obj) void Name(Obj *op1, ...) {\
  Obj *obj;\
  va_list vl;\
  va_start(vl, op1);\
  do {\
    obj = va_arg(vl, Obj *);\
    delete_##Obj(obj);\
  } while (obj);\
  va_end(vl);\
}


typedef SwigObj FlightData;

void FlightData_paramData_set(SwigObj * carg1, SwigObj * carg2);
SwigObj * FlightData_paramData_get(SwigObj * carg1);
FlightData * new_FlightData(/*aaa*/ char * carg1);
void FlightData_AddMissionItem(SwigObj * carg1, SwigObj * carg2);
void FlightData_AddResolutionItem(SwigObj * carg1, SwigObj * carg2);
void FlightData_SetStartMissionFlag(SwigObj * carg1, SwigObj * carg2);
void FlightData_ConstructMissionPlan(SwigObj * carg1);
void FlightData_ConstructResolutionPlan(SwigObj * carg1);
void FlightData_InputState(SwigObj * carg1, double carg2, double carg3, double carg4, double carg5, double carg6, double carg7, double carg8);
void FlightData_AddTraffic(SwigObj * carg1, int carg2, double carg3, double carg4, double carg5, double carg6, double carg7, double carg8);
void FlightData_GetTraffic_pFlightData_i_pd_pd_pd_pd_pd_pd(SwigObj * carg1, int carg2, double * carg3, double * carg4, double * carg5, double * carg6, double * carg7, double * carg8);
void FlightData_ClearMissionList(SwigObj * carg1);
void FlightData_ClearResolutionList(SwigObj * carg1);
void FlightData_InputNextMissionWP(SwigObj * carg1, int carg2);
void FlightData_InputNextResolutionWP(SwigObj * carg1, int carg2);
void FlightData_InputTakeoffAlt(SwigObj * carg1, double carg2);
void FlightData_InputCruisingAlt(SwigObj * carg1, double carg2);
void FlightData_InputGeofenceData(SwigObj * carg1, SwigObj * carg2);
double FlightData_GetTakeoffAlt(SwigObj * carg1);
double FlightData_GetCruisingAlt(SwigObj * carg1);
double FlightData_GetAltitude(SwigObj * carg1);
int FlightData_GetTotalMissionWP(SwigObj * carg1);
int FlightData_GetTotalResolutionWP(SwigObj * carg1);
int FlightData_GetTotalTraffic(SwigObj * carg1);
void FlightData_Reset(SwigObj * carg1);
void FlightData_InputAck(SwigObj * carg1, SwigObj * carg2);
#include <stdbool.h>
bool FlightData_CheckAck(SwigObj * carg1, SwigObj * carg2);
SwigObj * FlightData_GetStartMissionFlag(SwigObj * carg1);
SwigObj * FlightData_GetMissionPlanSize(SwigObj * carg1);
SwigObj * FlightData_GetResolutionPlanSize(SwigObj * carg1);
SwigObj * FlightData_GetNextMissionWP(SwigObj * carg1);
SwigObj * FlightData_GetNextResolutionWP(SwigObj * carg1);
int FlightData_GetTotalFences(SwigObj * carg1);
double FlightData_getFlightPlanSpeed(SwigObj * carg1, SwigObj * carg2, int carg3);
void FlightData_GetTraffic_pFlightData_i_rlarcfm_Position_rlarcfm_Velocity(SwigObj * carg1, int carg2, SwigObj * carg3, SwigObj * carg4);
/*aaaaaa*/SwigObj * FlightData_GetGeofence(SwigObj * carg1, int carg2);
/*aaaaaa*/SwigObj * FlightData_GetPolyPath(SwigObj * carg1);
void delete_FlightData(FlightData * carg1);

typedef SwigObj TrafficMonitor;

void TrafficMonitor_DAA_set(SwigObj * carg1, SwigObj * carg2);
SwigObj * TrafficMonitor_DAA_get(SwigObj * carg1);
void TrafficMonitor_KMB_set(SwigObj * carg1, SwigObj * carg2);
SwigObj * TrafficMonitor_KMB_get(SwigObj * carg1);
TrafficMonitor * new_TrafficMonitor(SwigObj * carg1);
bool TrafficMonitor_CheckTurnConflict(SwigObj * carg1, double carg2, double carg3, double carg4, double carg5);
bool TrafficMonitor_MonitorTraffic(SwigObj * carg1, bool carg2, double carg3, /*aaa*/ double * carg4, /*aaa*/ double * carg5, /*aaa*/ double * carg6);
void TrafficMonitor_GetVisualizationBands(SwigObj * carg1, SwigObj * carg2);
bool TrafficMonitor_CheckSafeToTurn(SwigObj * carg1, /*aaa*/ double * carg2, /*aaa*/ double * carg3, double carg4, double carg5);
void delete_TrafficMonitor(TrafficMonitor * carg1);

#endif /* _TrafficMonitor_proxy_H_ */
