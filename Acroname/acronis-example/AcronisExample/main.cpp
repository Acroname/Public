//
//  main.cpp
//  AcronisExample
//
/////////////////////////////////////////////////////////////////////
//                                                                 //
// Copyright (c) 2019 Acroname Inc. - All Rights Reserved          //
//                                                                 //
// Author: Narayan Birkley                                         //
// This file is part of the BrainStem release. See the license.txt //
// file included with this package or go to                        //
// https://acroname.com/software/brainstem-development-kit         //
// for full license details.                                       //
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include "BrainStem2/BrainStem-all.h"
#include <ctime>

int main(int argc, const char * argv[]) {

    // Create an instance of the USBHub3p
    aUSBHub3p hub;
    aErr err = aErrNone;
	int sleepTime_ms = 30000;

    // Connect to the hardware.
	// If you are using multiple hubs you will have to specify which hub to connect to by serial number.
    // err = stem.discoverAndConnect(USB, 0x40F5849A); // for a known serial number
    err = hub.discoverAndConnect(USB);
    if (err != aErrNone) {
        std::cerr << "Error "<< err <<" encountered connecting to BrainStem module" << std::endl;
        return err;
    } else {
        std::cout << "Connected to BrainStem module." << std::endl;
    }

	if (argc == 1)//argc == 1, run pre command
	{
		//Disable all ports to prepare to only enable one
		std::cout << "Disabling ports" << std::endl;
		for (int i = 0; i < 8; ++i) {
			// Disable all ports.
			err = hub.usb.setPortDisable(i);
		}

		//Find day of week, Sunday = 0, Monday = 1, ... Saturday = 6
		std::time_t tempTime = time(NULL);
		const std::tm * currTime = std::localtime(&tempTime);
		std::cout << "Enabling port " << currTime->tm_wday << std::endl;

		//Enable port based on day of week
		err = hub.usb.setPortEnable(currTime->tm_wday);

		//Wait a few seconds for the host computer to connect to the drive
		std::cout << "Sleeping for " << sleepTime_ms / 1000 << " seconds. " << std::endl;
		aTime_MSSleep(sleepTime_ms);//double check
	}
	else //argc > 1, run post command
	{
		aTime_MSSleep(5000);
		for (int i = 0; i < 8; ++i) {
			// Disable all ports.
			err = hub.usb.setPortDisable(i);
		}
	}

	//Save hub state
	err = hub.system.save();
	if (err != aErrNone) {
		std::cerr << "Error " << err << " encountered saving hub state." << std::endl;
	}
	else {
		std::cout << "Save succeeded." << std::endl;
	}

	// Disconnect
	err = hub.disconnect();
	if (err == aErrNone) {
		std::cout << "Disconnected from BrainStem module." << std::endl;
	}

    return 0;
}
