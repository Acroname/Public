#ifndef __Modules_LabView_H__
#define __Modules_LabView_H__

#include "Utilities.h"

extern "C" {

	//Modules
    void connectTo_USBHub2x4_LV(int* id, struct Result* result, int sn);

	aLIBEXPORT void __stdcall connectTo_USBHub3p_LV(int* id, struct Result* result, int sn);

	aLIBEXPORT void __stdcall connectTo_USBStem_LV(int* id, struct Result* result, int sn);

	aLIBEXPORT void __stdcall delete_Device_LV(int* id);



	//aLIBEXPORT void __stdcall sDiscoverUSB_LV(int id[], struct Result* result);
}

#endif