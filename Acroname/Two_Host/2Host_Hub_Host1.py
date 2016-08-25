import brainstem
import time

#Constants
UPSTREAM_PORT1 = 1
UPSTREAM_PORT0 = 2
MAX_LOOPS = 10
MAX_TIMEOUT = 20

#Create Hub object
print 'Running host0.py'
hub = brainstem.stem.USBHub2x4()

handoff = 0
#Main control loop
while (handoff < MAX_LOOPS):
    #Find and connect to device
    print "\nTrying to locate device"
    spec = brainstem.discover.find_module(brainstem.link.Spec.USB, 0x56F68799)

    #Only do stuff if a device was found
    if spec != None:
        #Connect to device
        hub.connect_from_spec(spec)

        #Wait for connection to be fully created
        timeout = 0
        while ((False == hub.is_connected()) and (timeout < MAX_TIMEOUT)):
            time.sleep(.1)
            timeout = timeout + 1

        #Test to see if we timedout from above
        if (timeout < MAX_TIMEOUT):

            #Get serial number (proves we are connected and receiving data)
            snHub = hub.system.getSerialNumber()
            print "Connected to Hub: 0x%X" % snHub.value

            #Turn on downstream port
            print "Port Enable"
            err = hub.usb.setPortEnable(0)

            #DO STUFF HERE
            print "Do stuff here"
            time.sleep(10)

            #Turn off downstream port
            print "Port Disable"
            err = hub.usb.setPortDisable(0)

            print "Passing control to host 0"
            #Host1 hands to host 0
            err = hub.usb.setUpstreamMode(UPSTREAM_PORT0)
            #Host0 hands to host 1
            #err = hub.usb.setUpstreamMode(UPSTREAM_PORT1)

            hub.disconnect()
            #gives time for the disconnect to go through
            time.sleep(.1)

    else:
        print "No device found.  Waiting..."
        time.sleep(10)

    #Increment handoff so that it doesn't run forever
    handoff = handoff + 1
    #clear spec so that nothing cares over
    spec = None

print "\nProgram Finnished"
