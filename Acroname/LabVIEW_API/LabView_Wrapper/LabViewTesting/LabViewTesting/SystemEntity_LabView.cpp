
#include "stdafx.h"
#include "SystemEntity_LabView.h"
#include "Utilities.h"
#include "BrainStem2\BrainStem-all.h"

// Get Module Address ////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall system_getModule_LV(int* id, struct Result* result){
	SystemClass system;							//Declare Entity
	uint8_t address;							//Declare any needed local variables
	auto map = findDevice(*id);					//Get device (iterator)
	system.init(map->second->stem, 0);			//Initalize Entity with device
	int error = system.getModule(&address);		//Call function
	packResult(result, address, error);			//Pack up value and error information
}

// Get Module Base Address ///////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall system_getModuleBaseAddress_LV(int* id, struct Result* result){
	SystemClass system;
	uint8_t baseAddress;
	auto map = findDevice(*id);
	system.init(map->second->stem, 0);
	int error = system.getModuleBaseAddress(&baseAddress);
	packResult(result, baseAddress, error);
}

// Get/Set Router ////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall system_getRouter_LV(int* id, struct Result* result){
	SystemClass system;
	uint8_t router;
	auto map = findDevice(*id);
	system.init(map->second->stem, 0);
	int error = system.getRouter(&router);
	packResult(result, router, error);
}
aLIBEXPORT void __stdcall system_setRouter_LV(int* id, struct Result* result, int router){
	SystemClass system;
	auto map = findDevice(*id);
	system.init(map->second->stem, 0);
	int error = system.setRouter(router);
	packResult(result, NULL, error);
}

// Get/Set Heartbeat Interval ////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall system_getHBInterval_LV(int* id, struct Result* result){
	SystemClass system;
	uint8_t HBInterval;
	auto map = findDevice(*id);
	system.init(map->second->stem, 0);
	int error = system.getHBInterval(&HBInterval);
	packResult(result, HBInterval, error);
}
aLIBEXPORT void __stdcall system_setHBInterval_LV(int* id, struct Result* result, int HBInterval){
	SystemClass system;
	auto map = findDevice(*id);
	system.init(map->second->stem, 0);
	int error = system.setHBInterval(HBInterval);
	packResult(result, NULL, error);
}

// Get/Set LED ///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall system_getLED_LV(int* id, struct Result* result){
	SystemClass system;
	uint8_t LED;
	auto map = findDevice(*id);
	system.init(map->second->stem, 0);
	int error = system.getLED(&LED);
	packResult(result, LED, error);
}
aLIBEXPORT void __stdcall system_setLED_LV(int* id, struct Result* result, int LED){
	SystemClass system;
	auto map = findDevice(*id);
	system.init(map->second->stem, 0);
	int error = system.setLED(LED);
	packResult(result, NULL, error);
}

// Get/Set Boot Slot /////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall system_getBootSlot_LV(int* id, struct Result* result){
	SystemClass system;
	uint8_t bootSlot;
	auto map = findDevice(*id);
	system.init(map->second->stem, 0);
	int error = system.getBootSlot(&bootSlot);
	packResult(result, bootSlot, error);
}
aLIBEXPORT void __stdcall system_setBootSlot_LV(int* id, struct Result* result, int slot){
	SystemClass system;
	auto map = findDevice(*id);
	system.init(map->second->stem, 0);
	int error = system.setBootSlot(slot);
	packResult(result, NULL, error);
}

// Get Version ///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall system_getVersion_LV(int* id, struct Result* result){
	SystemClass system;
	uint32_t version;
	auto map = findDevice(*id);
	system.init(map->second->stem, 0);
	int error = system.getVersion(&version);
	packResult(result, version, error);
}

// Get Model /////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall system_getModel_LV(int* id, struct Result* result){
	SystemClass system;
	uint8_t model;
	auto map = findDevice(*id);
	system.init(map->second->stem, 0);
	int error = system.getModel(&model);
	packResult(result, model, error);
}

// Get Serial Number /////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall system_getSerialNumber_LV(int* id, struct Result* result){
	SystemClass system;
	uint32_t serialNumber;
	auto map = findDevice(*id);
	system.init(map->second->stem, 0);
	int error = system.getSerialNumber(&serialNumber);
	packResult(result, serialNumber, error);
}

// Save //////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall system_save_LV(int* id, struct Result* result){
	SystemClass system;
	auto map = findDevice(*id);
	system.init(map->second->stem, 0);
	int error = system.save();
	packResult(result, NULL, error);
}

// Reset /////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall system_reset_LV(int* id, struct Result* result){
	SystemClass system;
	auto map = findDevice(*id);
	system.init(map->second->stem, 0);
	int error = system.reset();
	packResult(result, NULL, error);
}

// Get Input Voltage /////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall system_getInputVoltage_LV(int* id, struct Result* result){
	SystemClass system;
	uint32_t inputVoltage;
	auto map = findDevice(*id);
	system.init(map->second->stem, 0);
	int error = system.getInputVoltage(&inputVoltage);
	packResult(result, inputVoltage, error);
}

// Get Input Current /////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall system_getInputCurrent_LV(int* id, struct Result* result){
	SystemClass system;
	uint32_t inputCurrent;
	auto map = findDevice(*id);
	system.init(map->second->stem, 0);
	int error = system.getInputCurrent(&inputCurrent);
	packResult(result, inputCurrent, error);
}

// Get Module Hardware Offset ////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall system_getModuleHardwareOffset_LV(int* id, struct Result* result){
	SystemClass system;
	uint8_t hardwareOffset;
	auto map = findDevice(*id);
	system.init(map->second->stem, 0);
	int error = system.getModuleHardwareOffset(&hardwareOffset);
	packResult(result, hardwareOffset, error);
}

// Get/Set Module Software Offset ////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall system_getModuleSoftwareOffset_LV(int* id, struct Result* result){
	SystemClass system;
	uint8_t softwareOffset;
	auto map = findDevice(*id);
	system.init(map->second->stem, 0);
	int error = system.getModuleSoftwareOffset(&softwareOffset);
	packResult(result, softwareOffset, error);
}
aLIBEXPORT void __stdcall system_setModuleSoftwareOffset_LV(int* id, struct Result* result, int offset){
	SystemClass system;
	auto map = findDevice(*id);
	system.init(map->second->stem, 0);
	int error = system.setModuleSoftwareOffset(offset);
	packResult(result, NULL, error);
}

// Get Router Address Setting ////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall system_getRouterAddressSetting_LV(int* id, struct Result* result){
	SystemClass system;
	uint8_t address;
	auto map = findDevice(*id);
	system.init(map->second->stem, 0);
	int error = system.getRouterAddressSetting(&address);
	packResult(result, address, error);
}

// Route To Me ///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall system_RouteToMe_LV(int* id, struct Result* result, int enable){
	SystemClass system;
	auto map = findDevice(*id);
	system.init(map->second->stem, 0);
	int error = system.routeToMe(enable);
	packResult(result, NULL, error);
}