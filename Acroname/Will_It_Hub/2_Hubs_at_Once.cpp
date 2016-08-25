//  Created by Acroname Inc. on 1/16/15.
//  Copyright (c) 2015 Acroname Inc. All rights reserved.

#include <iostream>
#include "BrainStem2/BrainStem-all.h"


int main(int argc, const char * argv[]) {
    std::cout << "Creating 2x USBhub2x4's" << std::endl;

    //Declare variables and objects
    aUSBHub2x4 Hub1, Hub2;
    aErr err = aErrNone;
    uint32_t voltage1, voltage2, current1, current2;
    
/////////////////////////////////////////////////////////////////////////////////////////
    
    // Connect to Hub1
    // The only difference for TCP/IP modules is to change 'USB' to 'TCP';
    err = Hub1.linkDiscoverAndConnect(USB, 0x56F68799);
    if (err != aErrNone) {
        std::cout << "Error "<< err <<" encountered connecting to Hub1" << std::endl;
        return 1;
    } else {
        std::cout << "Connected to Hub1." << std::endl;
    }
    
    
    // Connect to Hub2
    // The only difference for TCP/IP modules is to change 'USB' to 'TCP';
    err = Hub2.linkDiscoverAndConnect(USB, 0x57F3829C);
    if (err != aErrNone) {
        std::cout << "Error "<< err <<" encountered connecting to Hub2" << std::endl;
        return 1;
    } else {
        std::cout << "Connected to Hub2." << std::endl;
    }
    
/////////////////////////////////////////////////////////////////////////////////////////
    
    for (int i = 0; i < 4; ++i) {
        //Disable all ports
        Hub1.usb.setPortDisable(i);
        Hub2.usb.setPortDisable(i);
        
        //Wait for commands and wait for voltage/current to build.
        aTime_MSSleep(1000);
        
        //Get Port Voltage
        Hub1.usb.getPortVoltage(i, &voltage1);
        Hub1.usb.getPortCurrent(i, &current1);
        
        //Get Port Current
        Hub2.usb.getPortVoltage(i, &voltage2);
        Hub2.usb.getPortCurrent(i, &current2);
        
        //Print Hub1 voltage/current
        std::cout << "Hub1 Port " << i << " Voltage: " << voltage1 << std::endl;
        std::cout << "Hub1 Port " << i << " Current: " << current1 << std::endl;
        
        //Print Hub2 voltage/current
        std::cout << "Hub2 Port " << i << " Voltage: " << voltage2 << std::endl;
        std::cout << "Hub2 Port " << i << " Current: " << current2 << std::endl;
    }//end for
    
/////////////////////////////////////////////////////////////////////////////////////////
    
    for (int i = 0; i < 4; ++i) {
        //Enable all ports
        Hub1.usb.setPortEnable(i);
        Hub2.usb.setPortEnable(i);
        
        //Wait for commands and wait for voltage/current to drain.
        aTime_MSSleep(1000);
        
        //Get Port Voltage
        Hub1.usb.getPortVoltage(i, &voltage1);
        Hub1.usb.getPortCurrent(i, &current1);
        
        //Get Port Current
        Hub2.usb.getPortVoltage(i, &voltage2);
        Hub2.usb.getPortCurrent(i, &current2);
        
        //Print Hub1 voltage/current
        std::cout << "Hub1 Port " << i << " Voltage: " << voltage1 << std::endl;
        std::cout << "Hub1 Port " << i << " Current: " << current1 << std::endl;
        
        //Print Hub2 voltage/current
        std::cout << "Hub2 Port " << i << " Voltage: " << voltage2 << std::endl;
        std::cout << "Hub2 Port " << i << " Current: " << current2 << std::endl;
    }//end for
    
/////////////////////////////////////////////////////////////////////////////////////////
    
    // Disconnect
    err = Hub1.linkDisconnect();
    if (err == aErrNone) {
        std::cout << "Disconnected from Hub1." << std::endl;
    }
    
    // Disconnect
    err = Hub2.linkDisconnect();
    if (err == aErrNone) {
        std::cout << "Disconnected from Hub2." << std::endl;
    }
    
    return 0;
}
