This folder contains a basic example of a National Instruments Test Stand project written for 
the BrainStem USBHub2x4 module.

Requirements:

* The project requires that the lib folder from The BrainStem dev-kit download available at:
  http://www.acroname.com/software
* To run the project, you will need an Acroname USBHub2x4 device plugged into your computer.
* VisualStudio 2013
* NI TestStand 32 or 64 bit versions.

Basic Startup:

1. First open the TS_USBHub2x4.sln file via Visual Studio.
2. Build the release target for the NI platform you have installed 32bit or 64bit.
2a. You should successfully have built a TS_USBHub2x4.dll within this folder.
3. Open the USBHub_Basic.seq with National Instruments Test Stand Sequence Editor.
4. Run the main sequence, this should turn off all of the downstream channels, 
   wait 2 seconds and turn downstream channel 1 on.