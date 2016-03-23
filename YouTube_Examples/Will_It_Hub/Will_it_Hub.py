#  Created by Acroname Inc. on 1/16/15.
#  Copyright (c) 2015 Acroname Inc. All rights reserved.

import brainstem

#Finds all devices and puts their "spec" in a list
moduleslist = brainstem.discover.find_all(1)

#Creates a list of type USBHub2x4
stemList = list(brainstem.stem.USBHub2x4() for i in range(127))

#Connects each "spec" to a USBHub2x4 type and prints the serial number
for x, spec in enumerate(moduleslist):
    stemList[x].connect_from_spec(spec)
    print "Hub: " + str(x) + ", 0x%X" % spec.serial_number

#Control Device #
for x, hub in enumerate(stemList):

    #Controls Port #
    for i in range(0,4):

        #Ensure device is connected before talking to the device
        if(hub.is_connected()):

            #Get Port Voltage
            voltage = hub.usb.getPortVoltage(i)

            #Get Port Current
            current = hub.usb.getPortCurrent(i)

            #Print
            print "Hub: " + str(x) + ", Port: " + str(i) + ", Voltage: " + \
                str(voltage.value) + ", Current: " + str(current.value)

for x in stemList:
    if(x.is_connected()):
        x.disconnect()
