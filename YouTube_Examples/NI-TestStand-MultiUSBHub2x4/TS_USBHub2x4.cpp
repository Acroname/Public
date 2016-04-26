// TODO - ADD acroname boilerplate here.


#include "stdafx.h"

#include "BrainStem2\BrainStem-all.h"

//global variables to hold values between calls
aUSBHub2x4* multiHubs;

BOOL APIENTRY DllMain(HANDLE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
	)
{
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH: multiHubs = NULL; break;
	case DLL_PROCESS_DETACH: break;
	}
	return TRUE;
}

extern "C" {

	//ProtoType Decleration
	int FindIndexFromSerialNumber(unsigned int serialNumber);



	// Create and connect to all devices based on the number of serial numbers passed in.
	// Serial numbers of modules can be found using the Updater.exe tool
	// Updater -D
	void __declspec(dllexport) __stdcall TS_MultiConnectToHub(unsigned int serialNumber[],
		int *errorOccurred,
		long *errorCode,
		wchar_t errorMsg[1024]) {

		try {
			aErr err = aErrNone;
			int numDevices = sizeof(serialNumber)/sizeof(unsigned int);

			multiHubs = new aUSBHub2x4[numDevices];

			//Loop through all hubs
			for (int i = 0; i < numDevices; i++) {
				//If not already connected then connect
				if (!multiHubs[i].linkIsConnected()) {
					err = multiHubs[i].linkDiscoverAndConnect(USB, serialNumber[i]);
				} else {
					err = aErrDuplicate;
				}

				if (err != aErrNone) {
					if (err != aErrDuplicate){
						multiHubs[i] = NULL;
					}
					*errorOccurred = TRUE;
					*errorCode = err;
				}
			}//end for
		} catch (...) {
			*errorOccurred = TRUE;
			wcscpy(errorMsg, L"Unknown Exception: TS_MultiConnectToHub");
		}
	}//end TS_MultiConnectToHub



	/////////////////////////////////////////////////////////////////////////////////
	// Enable the downstream port (channel) of a specific serial number (serialNumber).
	void __declspec(dllexport) __stdcall TS_EnableDownstreamPort(unsigned int serialNumber,
		unsigned int channel,
		int *errorOccurred,
		long *errorCode,
		wchar_t errorMsg[1024]) {

		try {
			aErr err = aErrNone;
			std::exception e;

			int index = FindIndexFromSerialNumber(serialNumber);
			//255 means the index was not found and we should exit
			if (index == 255) {
				*errorCode = 255;
				throw e;
			}

			if (multiHubs[index].linkIsConnected()) {
				err = multiHubs[index].usb.setPortEnable(channel);
			} else {
				err = aErrConnection;
			}

			if (err != aErrNone) {
				*errorOccurred = TRUE;
				*errorCode = err;
			}
		} catch (...) {
			*errorOccurred = TRUE;
			wcscpy(errorMsg, L"Unknown Exception: TS_EnableDownstreamPort");
		}
	}//end TS_EnableDownstreamPort



	/////////////////////////////////////////////////////////////////////////////////
	// Disable the downstream port (channel) of a specific serial number (serialNumber).
	void __declspec(dllexport) __stdcall TS_DisableDownstreamPort(unsigned int serialNumber,
		unsigned int channel,
		int *errorOccurred,
		long *errorCode,
		wchar_t errorMsg[1024]) {

		try {
			aErr err = aErrNone;
			std::exception e;

			int index = FindIndexFromSerialNumber(serialNumber);
			//255 means the index was not found and we should exit
			if (index == 255) {
				*errorCode = 255;
				throw e;
			}

			if (multiHubs[index].linkIsConnected()) {
				err = multiHubs[index].usb.setPortDisable(channel);
			} else {
				err = aErrConnection;
			}

			if (err != aErrNone) {
				*errorOccurred = TRUE;
				*errorCode = err;
			}
		} catch(...) {
			*errorOccurred = TRUE;
			wcscpy(errorMsg, L"Unknown Exception: TS_DisableDownstreamPort");
		}
	}//end TS_DisableDownstreamPort



	/////////////////////////////////////////////////////////////////////////////////
	//Disconnect and Destroy all BrainStem USBHubs2x4 that are created from the Multi Connect.
	void __declspec(dllexport) __stdcall TS_MultiDisconnectFromHub(int *errorOccurred,
		long *errorCode,
		wchar_t errorMsg[1024]) {

		try {
			aErr err = aErrNone;
			int numDevices = sizeof(multiHubs) / sizeof(aUSBHub2x4);

			for (int i = 0; i < numDevices; i++) {
				if (multiHubs[i].linkIsConnected()) {
					err = multiHubs[i].clearLink();
					err = multiHubs[i].linkDisconnect();
					multiHubs[i] = NULL;
				} else if (!multiHubs[i].linkIsConnected()) {
					multiHubs[i] = NULL;
				}

				if (err != aErrNone) {
					*errorOccurred = TRUE;
					*errorCode = err;
				}
			}//end for

			delete[] multiHubs;
		}
		catch (...) {
			*errorOccurred = TRUE;
			wcscpy(errorMsg, L"Unknown Exception: TS_MultiDisconnectFromHub");
		}
	}//end TS_MultiDisconnectFromHub



	/////////////////////////////////////////////////////////////////////////////////
	//Returns the index of where the serial number was found in the
	//array of aUSBHub2x4
	int FindIndexFromSerialNumber(unsigned int serialNumber) {

		linkSpec spec;
		int index = 0;
		int numDevices = sizeof(multiHubs) / sizeof(aUSBHub2x4);

		for (int i = 0; i < numDevices; i++) {
			multiHubs[i].getLinkSpecifier(&spec);
			if (spec.serial_num == serialNumber) return i;
		}

		return 255; //case in wich the serial number wasn't found
	}// end FindIndexFromSerialNumber



} // extern 'C'





