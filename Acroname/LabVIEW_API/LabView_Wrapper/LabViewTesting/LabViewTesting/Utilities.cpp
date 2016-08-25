#include "stdafx.h"
#include "Utilities.h"
#include <map>
#include "BrainStem2\BrainStem-all.h"

//Map decleration
std::map<int, LabviewNode*> StemMap;


//Finds the device based on its "id" (Serial Number)
std::map<int, LabviewNode*>::iterator findDevice(int id){
	return StemMap.find(id);
}

//Adds a new device to map
void addDevice(int id, Module* stem){
	LabviewNode* node = new LabviewNode; //Allocates memory for the object

	//Stores the pointer to the passed in stem device (assumes memory has
	//already been alocated for the specific device (ie USBHub2x4 or USBStem))
	node->stem = stem; 

	//Creates association between the LabviewNode object and its "id" and then
	//inserts it into the map
	StemMap.insert(std::make_pair(id, node));
}


void removeDevice(int id){
	//Locates the device pointer based on its "id"
	auto map = findDevice(id);

	//Releases memory for the stem object
	delete map->second->stem;
	map->second->stem = NULL;

	//Releases memory for the LabviewNode object
	delete map->second;
	map->second = NULL;

	//Erases item from the map
	StemMap.erase(map);
}


void packResult(struct Result* result, int value, int error){
	result->value = value;
	result->error = error;
}