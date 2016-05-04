getUSBDescriptors Project

The following project contains code that will pull USB descriptor information and print it out.  Unfortunately,
It is not complete, but it should speed up your learning curve as I have added a large amount of comments.
You will also see an image file which I will describe below.  With this information you should be able to
programmatically determines what device is connected to which port of the hub.

USB Tree description:
The photo in this project is a screenshot of the following items:
	1. Device manager
	2. Program output
	3. Device Properties
		a. Generic Hub
		b. USBHub2x4 BS
		c. Serial device (USBHub2x4 Downstream Port 0)
		d. USBStem (USBHub2x4 Downstream Port 2)
		e. Serial device (USBHub2x4 Downstream Port 3)

Important Notes:
	1. The Acroname Hub is recognized as two devices:
		a. USBHub2x4 BS
		b. Generic USB Hub.
	2. This program only prints "Universal Serial Bus controllers" (as defined in the device manager).  
		It looks that "Universal Serial Bus devices" are stored in another structure.
	3. The enumeration of devices downstream of the Hub are as follows:  (I assume it is done this
		(way because the 2x upstream ports are counted in the enumeration ie 1-6
		USBHub2x4 downstream port 0 = "Port_#0003"
		USBHub2x4 downstream port 1 = "Port_#0004"
		USBHub2x4 downstream port 2 = "Port_#0005"
		USBHub2x4 downstream port 3 = "Port_#0006"
	4. Acroname's VID is "VID_24FF"  This is common across all of our devices

By looking at the properties windows you can make some connections.  
	1. The USBHub2x4 "properties"  list the hub as "Hub_#0007"  This is common across all the downstream
		devices. However, this is not the number listed in the programs output as the USBHub2x4 is a 
		"Universal Serial Bus device" and the program does not list those.
	2. The Generic USB Hub "properties" shows "Port_#0006 Hub_#0005"  This can be linked to the programs output
		by looking at "Location Path (tree):"  You will notice that two devices have levels below "#USB(6)"
		(The reasons there are only 2 is because one device is the USBStem which does not show up because
		it is apart of the "Universal Serial Bus device" list.
