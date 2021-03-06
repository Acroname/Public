#ifndef __AnalogEntity_LabView_H__
#define __AnalogEntity_LabView_H__

#include "Utilities.h"

extern "C" {

	//////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////// Analog Entity /////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////

	// Get/Set Value /////////////////////////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall analog_getValue_LV(int* id, struct Result* result);
	aLIBEXPORT void __stdcall analog_setValue_LV(int* id, struct Result* result, int value);

	// Get Voltage ///////////////////////////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall analog_getVoltage_LV(int* id, struct Result* result);

	// Get/Set Configuration /////////////////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall analog_getConfiguration_LV(int* id, struct Result* result);
	aLIBEXPORT void __stdcall analog_setConfiguration_LV(int* id, struct Result* result, int configuration);

	// Get/Set Bulk Capture Sample Rate //////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall analog_getBulkCaptureSampleRate_LV(int* id, struct Result* result);
	aLIBEXPORT void __stdcall analog_setBulkCaptureSampleRate_LV(int* id, struct Result* result, int sampleRate);

	// Get/Set Bulk Capture Number of Samples ////////////////////////////////////////////////
	aLIBEXPORT void __stdcall analog_getBulkCaptureNumberOfSamples_LV(int* id, struct Result* result);
	aLIBEXPORT void __stdcall analog_setBulkCaptureNumberOfSamples_LV(int* id, struct Result* result, int numSamples);

	// Initiate Bulk Capture /////////////////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall analog_initiateBulkCapture_LV(int* id, struct Result* result);

	// Get Bulk Capture State ////////////////////////////////////////////////////////////////
	aLIBEXPORT void __stdcall analog_getBulkCaptureState_LV(int* id, struct Result* result);

	//////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////// End Analog Entity /////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////

}

#endif
