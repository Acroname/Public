//
//  main.cpp
//  BrainStem2Example
//
/////////////////////////////////////////////////////////////////////
//                                                                 //
// Copyright (c) 2018 Acroname Inc. - All Rights Reserved          //
//                                                                 //
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

    // Connect to the hardware.
    // The only difference for TCP/IP modules is to change 'USB' to 'TCP';
    // ex err = stem.discoverAndConnect(USB, 0x40F5849A); // for a known serial number
	// If you have more than one Acroname Hub connected to the host computer, you'll have to use the above method with the serial number of the backup device hub.
    err = hub.discoverAndConnect(USB);
    if (err != aErrNone) {
        std::cout << "Error "<< err <<" encountered connecting to BrainStem module" << std::endl;
        return 1;
    } else {
        std::cout << "Connected to BrainStem module." << std::endl;
    }
	if (argc == 1)
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
		std::cout << "Enabling port" << std::endl;
		//Enable port based on day of week
		err = hub.usb.setPortEnable(currTime->tm_wday);

		//Wait a few seconds for the host computer to connect to the drive
		aTime_MSSleep(15000);
	}
	else
	{
		aTime_MSSleep(5000);
		for (int i = 0; i < 8; ++i) {
			// Disable all ports.
			err = hub.usb.setPortDisable(i);
		}
	}

	//Save hub state
	err = hub.system.save();
	std::cout << err;

	// Disconnect
	err = hub.disconnect();
	if (err == aErrNone) {
		std::cout << "Disconnected from BrainStem module." << std::endl;
	}

    return 0;

}
