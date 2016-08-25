#include "stdafx.h"
#include "DigitalEntity_LabView.h"
#include "Utilities.h"
#include "BrainStem2\BrainStem-all.h"


// Get/Set Configuration /////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall digital_getConfiguration_LV(int* id, struct Result* result){
	DigitalClass digital;
	uint8_t configuration;
	auto map = findDevice(*id);
	digital.init(map->second->stem, 0);
	int error = digital.getConfiguration(&configuration);
	packResult(result, configuration, error);
}
aLIBEXPORT void __stdcall digital_setConfiguration_LV(int* id, struct Result* result, int configuration){
	DigitalClass digital;
	auto map = findDevice(*id);
	digital.init(map->second->stem, 0);
	int error = digital.setConfiguration(configuration);
	packResult(result, NULL, error);
}

// Get/Set State /////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall digital_getState_LV(int* id, struct Result* result){
	DigitalClass digital;
	uint8_t state;
	auto map = findDevice(*id);
	digital.init(map->second->stem, 0);
	int error = digital.getConfiguration(&state);
	packResult(result, state, error);
}
aLIBEXPORT void __stdcall digital_setState_LV(int* id, struct Result* result, int state){
	DigitalClass digital;
	auto map = findDevice(*id);
	digital.init(map->second->stem, 0);
	int error = digital.setConfiguration(state);
	packResult(result, NULL, error);
}