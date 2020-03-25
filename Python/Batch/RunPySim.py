from Icarous import *
from matplotlib import pyplot as plt

# Set the home position for the simulation
HomePos = [37.102177,-76.387207,0.000000]

# List to hold simulated traffic vehicles
tfList = []

# Start a single traffic vehicle from Home at specified
# range,brg,alt,track,speed,climb rate
# Call this function again to start multiple traffic vehicles
StartTraffic(HomePos,100,80,5,1,270,0,tfList)

# Set uncertainty and smoothing params for traffic
for tf in tfList:
    tf.setpos_uncertainty(0.01,0.01,0,0,0,0)

# Initialize Icarous class
ic = Icarous(HomePos)

# Setup uncertainty and smoothing parameters
ic.setpos_uncertainty(0.01,0.01,0,0,0,0)

# Read params from file and input params
params = LoadIcarousParams('icarous_default.parm')
ic.SetParameters(params)

# Input flightplan
flightplan = [ (37.102177,-76.387207,5.000000,0.0),
               (37.102335,-76.387195,5.000000,1.0),
               (37.102335,-76.386206,5.000000,1.0),
               (37.102110,-76.386481,5.000000,1.0),
               (37.101796,-76.386859,5.000000,1.0),
               (37.102177,-76.387207,5.000000,1.0)]

ic.InputFlightplan(flightplan,0)

# Input geofences from file
#ic.InputGeofence("geofence2.xml")


# Run simulation until mission is complete
while not ic.CheckMissionComplete():
    status = ic.Run()
    if not status:
        continue

    # Run simulation traffic and input traffic data to Icarous
    RunTraffic(tfList)
    for i,tf in enumerate(tfList):
        ic.InputTraffic(i,tf.pos_gps,tf.vel)

# Plot data for visualization    
plt.figure(1)
plt.plot(np.array(ic.positionLog)[:,0],np.array(ic.positionLog)[:,1],'r')
for tf in tfList:
    plt.plot(np.array(tf.log['pos'])[:,0],np.array(tf.log['pos'])[:,1],'b')
plt.show()