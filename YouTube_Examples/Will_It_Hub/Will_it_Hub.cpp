//  Created by Acroname Inc. on 1/16/15.
//  Copyright (c) 2015 Acroname Inc. All rights reserved.

#include <iostream>
#include "BrainStem2/BrainStem-all.h"

const int MAX_HUBS = 127;

struct hubData{
    uint32_t voltageOn[MAX_HUBS];
    uint32_t voltageOff[MAX_HUBS];
    uint32_t currentOn[MAX_HUBS];
    uint32_t currentOff[MAX_HUBS];
};

int main(int argc, const char * argv[]) {
    
    //Declare
    aUSBHub2x4 Hub[MAX_HUBS];
    int x;
    aErr err;
    list<linkSpec>* devices;
    hubData* data;
    
    std::cout << "Creating USBhub2x4's" << std::endl;
    
    //Allocate memory of type linkspec
    devices = new list<linkSpec>();
    
    //Find all devices and put into a list
    err = Acroname::BrainStem::Link::sDiscover(USB, devices);
    
/////////////////////////////////////////////////////////////////////////////////////////
    
    //Connect
    x = 0;
    for (std::list<linkSpec>::iterator it = devices->begin(); it != devices->end(); it++) {
        Hub[x].linkConnect(*it);
        printf("Hub: %d, SN: %0X", x, it->serial_num);
        x++;
    }
    
/////////////////////////////////////////////////////////////////////////////////////////
    
    //Allocate memory
    data = new hubData;
    
    //Controls Hub #
    for (int i = 0; i < devices->size(); i++) {
        
        //Controls Port Number
        for (int j = 0; j < 4; j++) {
            
            //Get Port Voltage
            Hub[i].usb.getPortVoltage(j, &data->voltageOn[j]);
            
            //Get Port Current
            Hub[i].usb.getPortCurrent(j, &data->currentOn[j]);
            
            //Print Hub1 voltage/current
            std::cout << "Hub: " << i << " Port " << j << " Voltage: " << data->voltageOn[j] <<
                " Current: " << data->currentOn[j] << std::endl;
            
        }//end for
    }//end for
    
/////////////////////////////////////////////////////////////////////////////////////////
    
    //Disconnect
    x = 0;
    for (std::list<linkSpec>::iterator it = devices->begin(); it != devices->end(); it++) {
        if (Hub[x].linkIsConnected()) {
            Hub[x].linkDisconnect();
        }
    }
    
    
    //Clean up.
    delete devices;
    delete data;
    return 0;
}
