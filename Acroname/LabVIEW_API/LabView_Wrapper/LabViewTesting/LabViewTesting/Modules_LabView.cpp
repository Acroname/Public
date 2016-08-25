#include "stdafx.h"
#include "Utilities.h"
#include <map>
#include "BrainStem2\BrainStem-all.h"




//static bContinueSearch sfindAll_LV(const linkSpec* spec, bool* bSuccess, void* vpCBRef);

// USBHub2x4 Create/Delete ///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
void connectTo_USBHub2x4_LV(int* id, struct Result* result, int sn){
	aUSBHub2x4* stem = new aUSBHub2x4;
	linkSpec* spec = new linkSpec;

	stem->discoverAndConnect(USB, sn);
	stem->getLinkSpecifier(spec);

	//If we found
	if (spec->model == aMODULE_TYPE_USBHub2x4){
		//Assign id and store device in map
		*id = spec->serial_num;
		addDevice(*id, stem);
		packResult(result, NULL, aErrNone);
	}
	else {
		//Don't forget to disconnect
		stem->disconnect();

		//Clean up if we didn't find the device we wanted.
		delete stem;
		stem = NULL;

		//Return error
		packResult(result, NULL, aErrNotFound);
	}
	//Clean UP
	delete spec;
	spec = NULL;
}

// USBHub3p Create/Delete ///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall connectTo_USBHub3p_LV(int* id, struct Result* result, int sn){
	aUSBHub3p* stem = new aUSBHub3p;
	linkSpec* spec = new linkSpec;

	stem->discoverAndConnect(USB, sn);
	stem->getLinkSpecifier(spec);

	//If we found
	if (spec->model == aMODULE_TYPE_USBHub3p){
		//Assign id and store device in map
		*id = spec->serial_num;
		addDevice(*id, stem);
		packResult(result, NULL, aErrNone);
	}
	else {
		//Don't forget to disconnect
		stem->disconnect();

		//Clean up if we didn't find the device we wanted.
		delete stem;
		stem = NULL;

		//Return error
		packResult(result, NULL, aErrNotFound);
	}
	//Clean UP
	delete spec;
	spec = NULL;
}


// USBStem Create/Delete /////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
aLIBEXPORT void __stdcall connectTo_USBStem_LV(int* id, struct Result* result, int sn){
	aUSBStem* stem = new aUSBStem;
	linkSpec* spec = new linkSpec;

	stem->discoverAndConnect(USB, sn);
	stem->getLinkSpecifier(spec);

	//If we found
	if (spec->model == aMODULE_TYPE_USBStem_1){
		//Assign id and store device in map
		*id = spec->serial_num;
		addDevice(*id, stem);
		packResult(result, NULL, aErrNone);
	}
	else {
		//Don't forget to disconnect
		stem->disconnect();

		//Clean up if we didn't find the device we wanted.
		delete stem;
		stem = NULL;

		//Return error
		packResult(result, NULL, aErrNotFound);
	}
	//Clean UP
	delete spec;
	spec = NULL;
}

aLIBEXPORT void __stdcall delete_Device_LV(int* id){
	auto map = findDevice(*id);
	map->second->stem->disconnect();
	removeDevice(*id);
}


////For some reason I am getting a linker error for sDiscover...
//// sDiscover
////aLIBEXPORT void __stdcall sDiscoverUSB_LV(int id[], struct Result* result){
//aLIBEXPORT void __stdcall sDiscoverUSB_LV(int id[], struct Result* result){
//	int error = aErrNone;
//
//	//Allocate memory of type linkspec
//	std::list<linkSpec>* devices = new std::list<linkSpec>();
//
//	int count = aDiscovery_EnumerateModules(USB, sfindAll_LV, devices);
//	if (count == 0) {
//		packResult(result, NULL, aErrNotFound);
//		return;
//	}
//
//	int counter = 0;
//	for (auto it = devices->begin(); it != devices->end(); ++it){
//		id[counter] = it->serial_num;
//	}
//
//	packResult(result, NULL, error);
//
//}
//
//static bContinueSearch sfindAll_LV(const linkSpec* spec, bool* bSuccess, void* vpCBRef) {
//
//	list<linkSpec>* pSpecs = (std::list<linkSpec>*)vpCBRef;
//	pSpecs->push_back(*spec);
//	*bSuccess = true;
//	return true;
//}