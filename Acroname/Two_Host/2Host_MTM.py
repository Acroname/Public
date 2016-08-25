import brainstem
import time

#Find Brainstem Module (USB)
spec = brainstem.discover.find_module(1, 0x4BEF9E80)
print spec

#If it doesn't find anything it will not try and connect
if spec != None:

    #Create MTMUSBStem device object
    MTMStem = brainstem.stem.MTMUSBStem()
    #Connect to device
    MTMStem.connect_from_spec(spec)
    time.sleep(.5)

    #Confirm that we are connected to a valid device
    snMTM = MTMStem.system.getSerialNumber()
    print "\nConnected directly to MTMUSBStem device: 0x%X\n" % snMTM.value

    #Create PM (Power Module) object
    MTMIO = brainstem.stem.MTMIOSerial()
    #Connect to Power Module through the MTMUSBStem
    err = MTMIO.connect_through_link_module(MTMStem)
    time.sleep(.1)

    #***************************************************************************
    # #Sets up the router for BrainStem communication
    # #This really only needs to be done once, but is nice to have it in the code
    # #every time
    # router = MTMStem.system.getRouter()
    # MTMIO.system.setRouter(router.value)
    # #MTMIO.system.setRouter(8)
    # #saving to apply them to memory
    # MTMIO.system.save()
    # MTMIO.system.reset()
    # time.sleep(1)
    #***************************************************************************

    #Confirm that we are connected to a valid device
    snPM = MTMIO.system.getSerialNumber()
    print "MTMIOSerial Device is connected via the BrainStem network: 0x%X\n" % snPM.value

    #Enable downstream port 0
    err = MTMIO.usb.setPortEnable(0)
    print "Port 0 enable, Error: %d\n" % err

    #Do Stuff
    for x in range (0,5):
        print "Host 0, Do something here."
        MTMIO.usb.setUpstreamMode(0) #Enable upstream port 0
        time.sleep(5)

        #Do Host 0 stuff...

        print "Host 1, Do something here."
        MTMIO.usb.setUpstreamMode(1) #Enables upstream port 1
        time.sleep(5)

        #Do Host 1 stuff...

else:
    #Device not found.
    print "Could not find the specified device"
