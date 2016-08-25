// TODO - ADD acroname boilerplate here.


#include "stdafx.h"

#include "BrainStem2\BrainStem-all.h"

//global variables to hold values between calls
aUSBHub2x4* gHub;

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		gHub = NULL;
        break;

    case DLL_PROCESS_DETACH:
		break;
    }
    
    return TRUE;
}

extern "C" {

/////////////////////////////////////////////////////////////////////////////////
//Create and connect to a BrainStem USBHub2x4 with the given serial Number.
// Serial numbers of modules can be found using the Updater.exe tool
// Updater -D
void __declspec(dllexport) __stdcall TS_ConnectToHub(unsigned int serialNumber,
													 int *errorOccurred, 
													 long *errorCode, 
													 wchar_t errorMsg[1024])
{

    try
        {
			aErr err = aErrNone;
			
			if (gHub == NULL) {
				gHub = new aUSBHub2x4();
				err = gHub->linkDiscoverAndConnect(USB, serialNumber);
			}
			else if (!gHub->linkIsConnected()) {
				err = gHub->linkDiscoverAndConnect(USB, serialNumber);
			}
			else {
				err = aErrDuplicate;
			}

			if (err != aErrNone) {
				if (err != aErrDuplicate){
					delete(gHub);
					gHub = NULL;
				}
				*errorOccurred = TRUE;
				*errorCode = err;
			}

        }
        
    catch (...)
        {
        *errorOccurred = TRUE;
        }
}

/////////////////////////////////////////////////////////////////////////////////
// Enable the downstream port on channel
void __declspec(dllexport) __stdcall TS_EnableDownstreamPort(unsigned int channel,
	int *errorOccurred,
	long *errorCode,
	wchar_t errorMsg[1024])
{

	try
	{
		aErr err = aErrNone;

		if (gHub != NULL && gHub->linkIsConnected()) {
			err = gHub->usb.setPortEnable(channel);
		}
		else {
			err = aErrConnection;
		}

		if (err != aErrNone) {
			*errorOccurred = TRUE;
			*errorCode = err;
		}

	}

	catch (...)
	{
		*errorOccurred = TRUE;
	}
}

/////////////////////////////////////////////////////////////////////////////////
// Enable the downstream port on channel
void __declspec(dllexport) __stdcall TS_DisableDownstreamPort(unsigned int channel,
	int *errorOccurred,
	long *errorCode,
	wchar_t errorMsg[1024])
{

	try
	{
		aErr err = aErrNone;

		if (gHub != NULL && gHub->linkIsConnected()) {
			err = gHub->usb.setPortDisable(channel);
		}
		else {
			err = aErrConnection;
		}

		if (err != aErrNone) {
			*errorOccurred = TRUE;
			*errorCode = err;
		}

	}

	catch (...)
	{
		*errorOccurred = TRUE;
	}
}


/////////////////////////////////////////////////////////////////////////////////
//Disconnect and Destroy a BrainStem USBHub2x4 with the given serial Number.
void __declspec(dllexport) __stdcall TS_DisconnectFromHub(unsigned int serialNumber,
	int *errorOccurred,
	long *errorCode,
	wchar_t errorMsg[1024])
{

	try
	{
		aErr err = aErrNone;

		if (gHub != NULL && gHub->linkIsConnected()) {
			err = gHub->linkDisconnect();
			delete(gHub);
			gHub = NULL;
		}
		else if (!gHub->linkIsConnected()) {
			delete(gHub);
			gHub = NULL;
		}
		else {
			err = aErrNotFound;
		}

		if (err != aErrNone) {
			*errorOccurred = TRUE;
			*errorCode = err;
		}

	}

	catch (...)
	{
		*errorOccurred = TRUE;
	}
}

} // extern 'C'

