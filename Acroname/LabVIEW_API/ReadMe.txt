April 23, 2021

#THIS EXAMPLE IS DEPRECATED

#Please visit www.acroname.com/support for our fully supported LabVIEW API









=================================================================================
BrainStem® LabVIEW API: Open Source
=================================================================================


Project Notes:
=================================================================================
This project contains the beginnings of an Open Source BrainStem LabVIEW API for 
LabVIEW 2015.  Please feel free to download and modifiy as needed.  As with any 
Open Source project the functionaly and usability depends on its contribuitors. 
If you are interested in becoming a contributior for this project please contact
support@acroname.com.

The current deployment package contains everything you need to work with the 
USBHub2x4 and USBHub3p.  A few other BrainStem entities have been started; however,
they are not currently exposed in the Deployment package, but can be found in
the "BrainStem_DLL_Import" folder.



Project Layout:
=================================================================================
LabView_BS_Project - Contains complete labview project (2015) include Hub deploy package.
	- BrainStem_DLL_Import - LabView API project that is generated as a result of 
		importing the LabView wrapper dll. To work in this project you will need to
		copy the 2.3.1 BrainStem.dll and BrainStem.lib files into this folder.
	- Deploy - Deployed package for the BrainStem USBHub2x4 and USBHub3p. Inside the 
		project you can find all the required VI's and example files that would 
		be needed to develop a VI for Acroname's usb Hub's. The BrainStem.dll and 
		LabViewTesting.dll have been included as folder is intended to run as a 
		stand alone deployment. 
	- Examples - Contains example files for working with BrainStem devices.

LabView_Wrapper - Visual Studio project for BrainStem wrapper.


Enjoy!

The Acroname Team
