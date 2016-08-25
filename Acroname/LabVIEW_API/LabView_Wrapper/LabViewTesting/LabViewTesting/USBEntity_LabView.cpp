#include "stdafx.h"
#include "USBEntity_LabView.h"
#include "Utilities.h"
#include "BrainStem2\BrainStem-all.h"

// Port Enable/Disable ///////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall usb_setPortEnable_LV(int* id, struct Result* result, int port){
	USBClass usb;							//Declare Entity
											//Declare any needed local variables
	auto map = findDevice(*id);				//Get device (iterator)
	usb.init(map->second->stem, 0);			//Initalize Entity with device
	int error = usb.setPortEnable(port);	//Call function
	packResult(result, NULL, error);		//Pack up value and error information
}
aLIBEXPORT void __stdcall usb_setPortDisable_LV(int* id, struct Result* result, int port){
	USBClass usb;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.setPortDisable(port);
	packResult(result, NULL, error);
}

// Power Enable/Disable ///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall usb_setPowerEnable_LV(int* id, struct Result* result, int port){
	USBClass usb;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.setPowerEnable(port);
	packResult(result, NULL, error);
}
aLIBEXPORT void __stdcall usb_setPowerDisable_LV(int* id, struct Result* result, int port){
	USBClass usb;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.setPowerDisable(port);
	packResult(result, NULL, error);
}

// Data Enable/Disable ///////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall usb_setDataEnable_LV(int* id, struct Result* result, int port){
	USBClass usb;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.setDataEnable(port);
	packResult(result, NULL, error);
}
aLIBEXPORT void __stdcall usb_setDataDisable_LV(int* id, struct Result* result, int port){
	USBClass usb;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.setDataDisable(port);
	packResult(result, NULL, error);
}

// Hi Speed Data Enable/Disable //////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall usb_setHiSpeedDataEnable_LV(int* id, struct Result* result, int port){
	USBClass usb;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.setHiSpeedDataEnable(port);
	packResult(result, NULL, error);
}
aLIBEXPORT void __stdcall usb_setHiSpeedDataDisable_LV(int* id, struct Result* result, int port){
	USBClass usb;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.setHiSpeedDataDisable(port);
	packResult(result, NULL, error);
}

// Super Speed Data Enable/Disable ///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall usb_setSuperSpeedDataEnable_LV(int* id, struct Result* result, int port){
	USBClass usb;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.setSuperSpeedDataEnable(port);
	packResult(result, NULL, error);
}
aLIBEXPORT void __stdcall usb_setSuperSpeedDataDisable_LV(int* id, struct Result* result, int port){
	USBClass usb;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.setSuperSpeedDataDisable(port);
	packResult(result, NULL, error);
}

// Get Port Current //////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall usb_getPortCurrent_LV(int* id, struct Result* result, int port){
	USBClass usb;
	uint32_t current = 0;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.getPortCurrent(port, &current);
	packResult(result, current, error);
}

// Get Port Voltage //////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall usb_getPortVoltage_LV(int* id, struct Result* result, int port){
	USBClass usb;
	uint32_t voltage = 0;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.getPortVoltage(port, &voltage);
	packResult(result, voltage, error);
}

// Get/Set Hub Mode //////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall usb_getHubMode_LV(int* id, struct Result* result){
	USBClass usb;
	uint32_t mode;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.getHubMode(&mode);
	packResult(result, mode, error);
}
aLIBEXPORT void __stdcall usb_setHubMode_LV(int* id, struct Result* result, int mode){
	USBClass usb;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.setHubMode((uint32_t)mode);
	packResult(result, NULL, error);
}

// Get Hub State /////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall usb_getHubState_LV(int* id, struct Result* result, int bank){
	USBClass usb;
	uint32_t status;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.getHubState(bank, &status);
	packResult(result, status, error);
}

// Get Hub Error Status //////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall usb_getHubErrorStatus_LV(int* id, struct Result* result, int bank){
	USBClass usb;
	uint32_t status;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.getHubErrorStatus(bank, &status);
	packResult(result, status, error);
}

// Clear Port Error Status ///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall usb_clearPortErrorStatus_LV(int* id, struct Result* result, int channel){
	USBClass usb;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.clearPortErrorStatus(channel);
	packResult(result, NULL, error);
}

// Get/Set Upstream mode /////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall usb_getUpstreamMode_LV(int* id, struct Result* result){
	USBClass usb;
	uint8_t mode;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.getUpstreamMode(&mode);
	packResult(result, mode, error);
}
aLIBEXPORT void __stdcall usb_setUpstreamMode_LV(int* id, struct Result* result, int mode){
	USBClass usb;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.setUpstreamMode(mode);
	packResult(result, NULL, error);
}

// Get UpstreamState /////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall usb_getUpstreamState_LV(int* id, struct Result* result){
	USBClass usb;
	uint8_t state;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.getUpstreamState(&state);
	packResult(result, state, error);
}

// Get System Temperature ////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall usb_getSystemTemperature_LV(int* id, struct Result* result){
	USBClass usb;
	uint32_t temp;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.getSystemTemperature(&temp);
	packResult(result, temp, error);
}

// Get/Set Enumeration Delay /////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall usb_getEnumerationDelay_LV(int* id, struct Result* result){
	USBClass usb;
	uint32_t delay;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.getEnumerationDelay(&delay);
	packResult(result, delay, error);
}
aLIBEXPORT void __stdcall usb_setEnumerationDelay_LV(int* id, struct Result* result, int delay){
	USBClass usb;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.setEnumerationDelay(delay);
	packResult(result, NULL, error);
}

// Get/Set Port Current Limit ////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall usb_getPortCurrentLimit_LV(int* id, struct Result* result, int channel){
	USBClass usb;
	uint32_t current;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.getPortCurrentLimit(channel, &current);
	packResult(result, current, error);
}
aLIBEXPORT void __stdcall usb_setPortCurrentLimit_LV(int* id, struct Result* result, int channel, int current){
	USBClass usb;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.setPortCurrentLimit(channel, current);
	packResult(result, NULL, error);
}

// Get/Set Port Mode /////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall usb_getPortMode_LV(int* id, struct Result* result, int channel){
	USBClass usb;
	uint8_t mode;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.getPortMode(channel, &mode);
	packResult(result, mode, error);
}
aLIBEXPORT void __stdcall usb_setPortMode_LV(int* id, struct Result* result, int channel, int mode){
	USBClass usb;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.setPortMode(channel, mode);
	packResult(result, NULL, error);
}

// Get/Set Upstream Boost Mode ///////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall usb_getUpstreamBoostMode_LV(int* id, struct Result* result, int channel){
	USBClass usb;
	uint8_t setting;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.getUpstreamBoostMode(&setting);
	packResult(result, setting, error);
}
aLIBEXPORT void __stdcall usb_setUpstreamBoostMode_LV(int* id, struct Result* result, int setting){
	USBClass usb;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.setUpstreamBoostMode(setting);
	packResult(result, NULL, error);
}

// Get/Set Downstream Boost Mode /////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall usb_getDownstreamBoostMode_LV(int* id, struct Result* result, int channel){
	USBClass usb;
	uint8_t setting;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.getDownstreamBoostMode(&setting);
	packResult(result, setting, error);
}
aLIBEXPORT void __stdcall usb_setDownstreamBoostMode_LV(int* id, struct Result* result, int setting){
	USBClass usb;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.setDownstreamBoostMode(setting);
	packResult(result, NULL, error);
}

// Get/Set Downstream Data Speed /////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall usb_getDownstreamDataSpeed_LV(int* id, struct Result* result, int channel){
	USBClass usb;
	uint8_t mode;
	auto map = findDevice(*id);
	usb.init(map->second->stem, 0);
	int error = usb.getDownstreamDataSpeed(channel, &mode);
	packResult(result, mode, error);
}