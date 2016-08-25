#ifndef __USBEntity_LabView_H__
#define __USBEntity_LabView_H__

#include "Utilities.h"

extern "C" {

	//////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////// USB Entity ////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////

	// Port Enable/Disable ///////////////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall usb_setPortEnable_LV(int* id, struct Result* result, int port);
	aLIBEXPORT void __stdcall usb_setPortDisable_LV(int* id, struct Result* result, int port);

	// Power Enable/Disable ///////////////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall usb_setPowerEnable_LV(int* id, struct Result* result, int port);
	aLIBEXPORT void __stdcall usb_setPowerDisable_LV(int* id, struct Result* result, int port);

	// Data Enable/Disable ///////////////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall usb_setDataEnable_LV(int* id, struct Result* result, int port);
	aLIBEXPORT void __stdcall usb_setDataDisable_LV(int* id, struct Result* result, int port);

	// Hi Speed Data Enable/Disable //////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall usb_setHiSpeedDataEnable_LV(int* id, struct Result* result, int port);
	aLIBEXPORT void __stdcall usb_setHiSpeedDataDisable_LV(int* id, struct Result* result, int port);

	// Super Speed Data Enable/Disable ///////////////////////////////////////////////////
	aLIBEXPORT void __stdcall usb_setSuperSpeedDataEnable_LV(int* id, struct Result* result, int port);
	aLIBEXPORT void __stdcall usb_setSuperSpeedDataDisable_LV(int* id, struct Result* result, int port);

	// Get Port Current //////////////////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall usb_getPortCurrent_LV(int* id, struct Result* result, int port);

	// Get Port Voltage //////////////////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall usb_getPortVoltage_LV(int* id, struct Result* result, int port);

	// Get/Set Hub Mode //////////////////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall usb_getHubMode_LV(int* id, struct Result* result);
	aLIBEXPORT void __stdcall usb_setHubMode_LV(int* id, struct Result* result, int mode);

	// Get Hub State /////////////////////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall usb_getHubState_LV(int* id, struct Result* result, int bank);

	// Get Hub Error Status //////////////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall usb_getHubErrorStatus_LV(int* id, struct Result* result, int bank);

	// Clear Port Error Status ///////////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall usb_clearPortErrorStatus_LV(int* id, struct Result* result, int channel);

	// Get/Set Upstream mode /////////////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall usb_getUpstreamMode_LV(int* id, struct Result* result);
	aLIBEXPORT void __stdcall usb_setUpstreamMode_LV(int* id, struct Result* result, int mode);

	// Get UpstreamState /////////////////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall usb_getUpstreamState_LV(int* id, struct Result* result);

	// Get System Temperature ////////////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall usb_getSystemTemperature_LV(int* id, struct Result* result);

	// Get/Set Enumeration Delay /////////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall usb_getEnumerationDelay_LV(int* id, struct Result* result);
	aLIBEXPORT void __stdcall usb_setEnumerationDelay_LV(int* id, struct Result* result, int delay);

	// Get/Set Port Current Limit ////////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall usb_getPortCurrentLimit_LV(int* id, struct Result* result, int channel);
	aLIBEXPORT void __stdcall usb_setPortCurrentLimit_LV(int* id, struct Result* result, int channel, int current);

	// Get/Set Port Mode /////////////////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall usb_getPortMode_LV(int* id, struct Result* result, int channel);
	aLIBEXPORT void __stdcall usb_setPortMode_LV(int* id, struct Result* result, int channel, int mode);

	// Get/Set Upstream Boost Mode ///////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall usb_getUpstreamBoostMode_LV(int* id, struct Result* result, int channel);
	aLIBEXPORT void __stdcall usb_setUpstreamBoostMode_LV(int* id, struct Result* result, int setting);

	// Get/Set Downstream Boost Mode /////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall usb_getDownstreamBoostMode_LV(int* id, struct Result* result, int channel);
	aLIBEXPORT void __stdcall usb_setDownstreamBoostMode_LV(int* id, struct Result* result, int setting);

	// Get/Set Downstream Data Speed /////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall usb_getDownstreamDataSpeed_LV(int* id, struct Result* result, int channel);

	//////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////// End USB Entity ////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////

}
#endif