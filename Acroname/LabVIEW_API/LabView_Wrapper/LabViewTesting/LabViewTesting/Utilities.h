#ifndef __Utilities_H__
#define __Utilities_H__

#include <map>
#include "BrainStem2\BrainStem-all.h"


//Device Information Structure
//In the future it might be nice to add other items for quick access.  Such as 
//Network information.
struct LabviewNode {
	Module* stem;
};

//Result Structure
//Used to pass information back to LabView
struct Result {
	int value;
	int error;
};

//////////////////////////////////////////////////////////////////////////////////////////
//Functions for working with the "map" (list) of devices.  These functions are also
//responsiable for memory manament
//////////////////////////////////////////////////////////////////////////////////////////

//Locates the device in the map based on its "id" (Serial Number) and returns an 
//iterator (pointer) to the LabviewNode object
std::map<int, LabviewNode*>::iterator findDevice(int id);

//Addes a new device to the map. 
void addDevice(int, Module* stem);

//Removes a device from the map
void removeDevice(int);
//////////////////////////////////////////////////////////////////////////////////////////

//Packs a value and error into a "Result" structure.
void packResult(struct Result* result, int value = NULL, int error = aErrNone);

#endif