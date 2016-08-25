#include "stdafx.h"
#include "AnalogEntity_LabView.h"
#include "Utilities.h"
#include "BrainStem2\BrainStem-all.h"


// Get/Set Value /////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall analog_getValue_LV(int* id, struct Result* result){
	AnalogClass analog;							//Declare Entity
	uint16_t value;								//Declare any needed local variables
	auto map = findDevice(*id);					//Get device (iterator)
	analog.init(map->second->stem, 0);			//Initalize Entity with device
	int error = analog.getValue(&value);		//Call function
	packResult(result, value, error);			//Pack up value and error information
}
aLIBEXPORT void __stdcall analog_setValue_LV(int* id, struct Result* result, int value){
	AnalogClass analog;
	auto map = findDevice(*id);
	analog.init(map->second->stem, 0);
	int error = analog.setValue(value);
	packResult(result, NULL, error);
}

// Get Voltage ///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall analog_getVoltage_LV(int* id, struct Result* result){
	AnalogClass analog;	
	int32_t voltage;				
	auto map = findDevice(*id);		
	analog.init(map->second->stem, 0);	
	int error = analog.getVoltage(&voltage);	
	packResult(result, voltage, error);	
}

// Get/Set Configuration /////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall analog_getConfiguration_LV(int* id, struct Result* result){
	AnalogClass analog;			
	uint8_t configuration;					
	auto map = findDevice(*id);				
	analog.init(map->second->stem, 0);		
	int error = analog.getConfiguration(&configuration);
	packResult(result, configuration, error);
}
aLIBEXPORT void __stdcall analog_setConfiguration_LV(int* id, struct Result* result, int configuration){
	AnalogClass analog;
	auto map = findDevice(*id);
	analog.init(map->second->stem, 0);
	int error = analog.setConfiguration(configuration);
	packResult(result, NULL, error);
}

// Get/Set Bulk Capture Sample Rate //////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall analog_getBulkCaptureSampleRate_LV(int* id, struct Result* result){
	AnalogClass analog;
	uint32_t sampleRate;
	auto map = findDevice(*id);
	analog.init(map->second->stem, 0);
	int error = analog.getBulkCaptureSampleRate(&sampleRate);
	packResult(result, sampleRate, error);
}
aLIBEXPORT void __stdcall analog_setBulkCaptureSampleRate_LV(int* id, struct Result* result, int sampleRate){
	AnalogClass analog;
	auto map = findDevice(*id);
	analog.init(map->second->stem, 0);
	int error = analog.setBulkCaptureSampleRate(sampleRate);
	packResult(result, NULL, error);
}

// Get/Set Bulk Capture Number of Samples ////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall analog_getBulkCaptureNumberOfSamples_LV(int* id, struct Result* result){
	AnalogClass analog;
	uint32_t numSamples;
	auto map = findDevice(*id);
	analog.init(map->second->stem, 0);
	int error = analog.getBulkCaptureNumberOfSamples(&numSamples);
	packResult(result, numSamples, error);
}
aLIBEXPORT void __stdcall analog_setBulkCaptureNumberOfSamples_LV(int* id, struct Result* result, int numSamples){
	AnalogClass analog;
	auto map = findDevice(*id);
	analog.init(map->second->stem, 0);
	int error = analog.setBulkCaptureNumberOfSamples(numSamples);
	packResult(result, NULL, error);
}

// Initiate Bulk Capture /////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall analog_initiateBulkCapture_LV(int* id, struct Result* result){
	AnalogClass analog;
	auto map = findDevice(*id);
	analog.init(map->second->stem, 0);
	int error = analog.initiateBulkCapture();
	packResult(result, NULL, error);
}

// Get Bulk Capture State ////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall analog_getBulkCaptureState_LV(int* id, struct Result* result){
	AnalogClass analog;
	uint8_t bulkCaptureState;
	auto map = findDevice(*id);
	analog.init(map->second->stem, 0);
	int error = analog.getBulkCaptureState(&bulkCaptureState);
	packResult(result, bulkCaptureState, error);
}