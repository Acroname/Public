#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include <Setupapi.h>
#include <devguid.h>
#include "conio.h"
#include "tchar.h"

#pragma comment (lib, "Setupapi.lib")	//Needed for all the "SetupDi*" stuff.

int main(int argc, char ** argv)
{
	HDEVINFO deviceInfoSet;		//Void pointer to "device information set" aka "Handle"
	PBYTE pBuffer;				//Byte Porter: Requred by SetupDiGetDeviceRegistryProperty
	DWORD RequiredSize;			//Size for pBuffer
	TCHAR buffer[4000];			//Buffer for VID / PID  (From online orgional example code)
	DWORD buffersize = 4000;	//Size for buffer (From online orgional example code)
	int memberIndex;			//index for enumerating through devices

	GUID *guidDev = (GUID*)&GUID_DEVCLASS_USB;  //GUID pointer = constant casted to GUID pointer

	//Returns a "handle" (void pointer) to a list of the desired device information based on flags.
	//DIGCF_PRESENT = Return only devices that are currently present in a system
	//DIGCF_PROFILE = Return only devices that are a part of the current hardware profile
	deviceInfoSet = SetupDiGetClassDevs(guidDev, NULL, NULL, DIGCF_PRESENT | DIGCF_PROFILE);

	memberIndex = 0;	//Keeps track of what device we are on.
	while (true) {
		//This is a structure of that data that will be recieved from the set (deviceInfoSet)
		SP_DEVINFO_DATA deviceInfoData;
		ZeroMemory(&deviceInfoData, sizeof(SP_DEVINFO_DATA));	//Macro for filling memory with zeros

		//Setting the size is important for certian actions done by SetupDiEnumDeviceInfo
		deviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);

		//While loop exit
		//Pulls data from deviceInfoSet until the set has been completly read and returns an error.
		if (SetupDiEnumDeviceInfo(deviceInfoSet, memberIndex, &deviceInfoData) == FALSE) {
			if (GetLastError() == ERROR_NO_MORE_ITEMS) {
				break;
			}
		}

		//////////////////////////////////////////////////////////////////////////////////////////////////////
		//Get Device Instance ID: VID / PID
		//////////////////////////////////////////////////////////////////////////////////////////////////////
		DWORD nSize = 0;
		//Pulls specific information from the data pulled via SetupDiEnumDeviceInfo
		SetupDiGetDeviceInstanceId(deviceInfoSet, &deviceInfoData, buffer, sizeof(buffer), &nSize);

		buffer[nSize] = '\0';	//Terminates the buffer with a null for printing
		_tprintf(_T("%s\n"), buffer);	//Print data pulled.
		//////////////////////////////////////////////////////////////////////////////////////////////////////
		//End Get Device Instance ID: VID / PID
		//////////////////////////////////////////////////////////////////////////////////////////////////////


		//////////////////////////////////////////////////////////////////////////////////////////////////////
		//Get Manufacture Information
		//////////////////////////////////////////////////////////////////////////////////////////////////////
		RequiredSize = 0;
		//Calling this with NULL's and 0, tells the function that we want the size of data that will be returned
		//to us.  We can then dynamically allocate that buffer.
		SetupDiGetDeviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_MFG, NULL, NULL, 0, &RequiredSize);
		//printf("buffer Size: %d\n", RequiredSize);	//Debug

		//Only allocate if there is something to be returned
		if (RequiredSize > 0) {
			//Allocate memory for buffer
			pBuffer = new BYTE[RequiredSize];
			ZeroMemory(pBuffer, (RequiredSize *sizeof(BYTE)));

			//Fill buffer
			SetupDiGetDeviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_MFG, NULL, pBuffer, RequiredSize, NULL);
			_tprintf(_T("Manufacturer: %s\n"), pBuffer);	//Print data pulled.

			//cleanup
			delete[] pBuffer;
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////
		//End Get Manufacturer Information
		//////////////////////////////////////////////////////////////////////////////////////////////////////


		//////////////////////////////////////////////////////////////////////////////////////////////////////
		//Get Location Information
		//////////////////////////////////////////////////////////////////////////////////////////////////////
		RequiredSize = 0;
		SetupDiGetDeviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_LOCATION_INFORMATION, NULL, NULL, 0, &RequiredSize);
		//printf("buffer Size: %d\n", RequiredSize);

		if (RequiredSize > 0) {
			pBuffer = new BYTE[RequiredSize];
			ZeroMemory(pBuffer, (RequiredSize *sizeof(BYTE)));

			SetupDiGetDeviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_LOCATION_INFORMATION, NULL, pBuffer, RequiredSize, NULL);
			_tprintf(_T("Location: %s\n"), pBuffer);	//Print data pulled.

			delete[] pBuffer;
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////
		//End Get Location Information
		//////////////////////////////////////////////////////////////////////////////////////////////////////


		//////////////////////////////////////////////////////////////////////////////////////////////////////
		//Get Location Path Information
		//////////////////////////////////////////////////////////////////////////////////////////////////////
		RequiredSize = 0;
		SetupDiGetDeviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_LOCATION_PATHS, NULL, NULL, 0, &RequiredSize);
		//printf("buffer Size: %d\n", RequiredSize);

		if (RequiredSize > 0) {
			pBuffer = new BYTE[RequiredSize];
			ZeroMemory(pBuffer, (RequiredSize *sizeof(BYTE)));

			SetupDiGetDeviceRegistryProperty(deviceInfoSet, &deviceInfoData, SPDRP_LOCATION_PATHS, NULL, pBuffer, RequiredSize, NULL);
			_tprintf(_T("Location Path (tree): %s\n"), pBuffer);	//Print data pulled.

			delete[] pBuffer;
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////
		//End Get Location Path Information
		//////////////////////////////////////////////////////////////////////////////////////////////////////


		printf("\n");
		memberIndex++;		//Increment for next device
	}

	//Clean up. Destorys the list of devices (the Void pointer)
	if (deviceInfoSet) {
		SetupDiDestroyDeviceInfoList(deviceInfoSet);
	}

	_getch();	//Only to keep the program from terminating. (So you can read output)
	return 0;
}
