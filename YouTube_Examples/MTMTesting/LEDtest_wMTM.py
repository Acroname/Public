import brainstem
from brainstem.result import Result
import time

################################################################################
################################### CLASS LAND  ################################
################################################################################

#This class contains all the data storage and required functions
class testData(object):
    def __init__(self):
        self.vDropResistor=0
        self.vDropLED=0
        self.resistance=0
        self.errorCount=0
        self.errorCalculate=0

        #These are Result objects
        self.powerVoltage=Result(0,0)
        self.ADCVoltage=Result(0,0)
        self.powerCurrent=Result(0,0)


    #Function clears the erros in the object.  Used when going to the next test.
    def clearErrors(self):
        self.errorCount=0
        self.errorCalculate=0

    #Gathers all the needed date from the stems
    def gatherData(self):
        #Get PM data
        #Get output voltage
        self.powerVoltage = 0
        self.powerVoltage = MTMPM.rail[0].getVoltage()
        if (self.powerVoltage.error != Result.NO_ERROR):
            self.errorCount = self.errorCount + 1
            self.powerVoltage = Result(0,0)

        #Get output current
        self.powerCurrent = 0
        self.powerCurrent = MTMPM.rail[0].getCurrent()
        #print "Raw Current: %d, Converted: %.4f" %(self.powerCurrent.value, float(self.powerCurrent.value)/1000000)
        if (self.powerCurrent.error != Result.NO_ERROR):
            self.errorCount = self.errorCount + 1
            self.powerCurrent = Result(0,0)

        #Get MTMStem data
        self.ADCVoltage = 0
        self.ADCVoltage = MTMStem.analog[x].getVoltage()
        if (self.ADCVoltage.error != Result.NO_ERROR):
            self.errorCount = self.errorCount + 1
            self.ADCVoltage = Result(0,0)

    #Calculates required values and keeps track of calculation errors
    def calculateValues(self):

        #Calculate voltage drop accros the resistor (Vsource - Vadc)
        self.vDropResistor = (self.powerVoltage.value - self.ADCVoltage.value)
        if self.vDropResistor < 0:
            self.vDropResistor = 0
            self.errorCalculate = self.errorCalculate + 1

        self.vDropLED = (self.powerVoltage.value - self.vDropResistor)
        if self.vDropLED < 0:
            self.vDropLED = 0
            self.errorCalculate = self.errorCalculate + 1

        #Calculate resistance (vDrop/current)
        #Test for divide by 0
        if self.powerCurrent.value > 0:
            self.resistance = (self.vDropResistor / float(self.powerCurrent.value))
        else:
            self.resistance = 0
            self.errorCalculate = self.errorCalculate + 1

    #Print data in variouse formats based on option
    def printData(self, option = 0, samples=0):
        #Print without samples
        if (option == 0):
            print "1. %.5f VDC,\t     2. %.5f A,\t  3. %.5f VDC,\t4. %.5f VDC,\t       5. %.3f Ohms" \
                %((float(self.powerVoltage.value)/1000000),
                (float(self.powerCurrent.value)/1000000),
                (float(self.ADCVoltage.value)/1000000),
                (float(self.vDropResistor)/1000000),
                float(self.resistance))
        #Disable print
        elif (option == 1):
            pass
        #Print with samples taken
        elif (option == 2):
            print "1. %.5f VDC,\t     2. %.5f A,\t  3. %.5f VDC,\t4. %.5f VDC,\t       5. %.3f Ohms    # Samples: %d" \
                %((float(self.powerVoltage.value)/1000000),
                (float(self.powerCurrent.value)/1000000),
                (float(self.ADCVoltage.value)/1000000),
                (float(self.vDropResistor)/1000000),
                float(self.resistance),
                samples)
        #Debug print so that it can be copied into excel
        elif (option == 3):
            print "%.5f\t %.5f\t %.5f\t%.5f\t%.3f" \
                %((float(self.powerVoltage.value)/1000000),
                (float(self.powerCurrent.value)/1000000),
                (float(self.ADCVoltage.value)/1000000),
                (float(self.vDropResistor)/1000000),
                float(self.resistance))
        #Sweap data print
        elif(option == 4):
            print "%.5f\t%.5f\t%.5f" %((float(self.ADCVoltage.value)/1000000),
                                    (float(self.vDropResistor)/1000000),
                                    (float(self.powerCurrent.value)/1000000))
        else:
            print "Invalid print option"

    #Header/Column data
    def printHeadder(self):
        print "\nTest Circuit: %d" %(x+1)
        print "1. Supplied Voltage, 2. Supplied Current, 3. LED Voltage,       4. Resistor Voltage,   5. Resistance"

    #Footer/Error Data
    def printFooter(self):
        print "Error Count: %d, Error Calculate: %d" % (self.errorCount, self.errorCalculate)
        if ((self.errorCount > 0) or (self.errorCalculate > 0)):
            print "*************************************************************************"
            print "Errors were encountered during the test. The results could be compromised"
            print "*************************************************************************"

    #Adds/Sums data together
    def addData(self, data):
        self.vDropResistor = data.vDropResistor + self.vDropResistor
        self.vDropLED = data.vDropLED + self.vDropLED
        self.resistance = data.resistance + float(self.resistance)
        self.powerVoltage = Result(0,(data.powerVoltage.value + self.powerVoltage.value))
        self.ADCVoltage = Result(0,(data.ADCVoltage.value + self.ADCVoltage.value))
        self.powerCurrent = Result(0,(data.powerCurrent.value + self.powerCurrent.value))

    #Averges the added data based on the number of sameples taken
    def averageData(self, counter):
        self.vDropResistor = self.vDropResistor / counter
        self.vDropLED = self.vDropLED / counter
        self.resistance = self.resistance / counter
        self.powerVoltage = Result(0,(self.powerVoltage.value / counter))
        self.ADCVoltage = Result(0,(self.ADCVoltage.value / counter))
        self.powerCurrent = Result(0,(self.powerCurrent.value / counter))

################################################################################
################################ END CLASS LAND  ###############################
################################################################################


################################################################################
################################ FUNCTION LAND #################################
################################################################################

#Glue: Connects hardware to the specific program focus.
def configureDevices(MTMPM, MTMStem):
    #Setup MTMUSBStem
    #Setup digital and analog pins for the test circuit
    #Set as output
    #High value will turn off the circuit
    #Low value will turn on the circuit (by sinking current, max = 20mA)

    #HIGH Z OPTION
    MTMStem.digital[0].setConfiguration(4)  #Red
    MTMStem.digital[1].setConfiguration(4)  #Green
    MTMStem.digital[2].setConfiguration(4)  #Blue

    #Output Configuration option
    #Set pin state option
    # MTMStem.digital[0].setConfiguration(1)  #Red
    # MTMStem.digital[1].setConfiguration(1)  #Green
    # MTMStem.digital[2].setConfiguration(1)  #Blue
    # #Set the state to High (circuit off)
    # MTMStem.digital[0].setState(1)  #Red
    # MTMStem.digital[1].setState(1)  #Green
    # MTMStem.digital[2].setState(1)  #Blue

    #Setup analog as inputs to measure voltage after the resistor
    MTMStem.analog[0].setConfiguration(0)   #Red
    MTMStem.analog[1].setConfiguration(0)   #Green
    MTMStem.analog[2].setConfiguration(0)   #Blue

    #Setup MTMPM1
    #Setup the power for the test circuit
    #Set voltage to 3.3 VDC (uV)
    MTMPM.rail[0].setVoltage(3300000)
    #Current limited to 1A
    #MTMPM.rail[0].setCurrentLimit(1000000)
    MTMPM.rail[0].setCurrentLimit(3000000)
    #Turn on the power

#Handles the data store.  ie adds, averages, and prints.
def handleData(store):
    counter = 0
    tempData = testData()
    combinedData = testData()

    x=None
    for x in range (0,len(store)):
        tempData = store.pop()
        combinedData.addData(tempData)
        #combinedData.printData(0)
        counter = counter + 1

    combinedData.averageData(counter)
    combinedData.printData(2, counter)

def sweepTest(MTMPM, MTMStem):

    sweepData = testData()
    setVoltage = 1800000

    #Get Stored set voltage
    voltageResult = MTMPM.rail[0].getVoltage()

    for counter in range (0,32):
        err = MTMPM.rail[0].setVoltage(setVoltage)
        time.sleep(.1)
        sweepData.gatherData()
        sweepData.calculateValues()
        sweepData.printData(4,0)
        setVoltage = setVoltage + 100000

    MTMPM.rail[0].setVoltage(voltageResult.value)



################################################################################
############################### END FUNCTION LAND ##############################
################################################################################


################################################################################
################################## MAIN MAN ####################################
################################################################################

#Find Brainstem Module (USB)
spec = brainstem.discover.find_module(1,0x4BEF9E80)
print spec

#If it doesn't find anything it will not try and connect
if spec != None:

    #Create MTMUSBStem device object
    MTMStem = brainstem.stem.MTMUSBStem()

    #Connect to device
    MTMStem.connect_from_spec(spec)
    time.sleep(.5)

    #Confirm that we are connected to a valid device
    snMTM = MTMStem.system.getSerialNumber()
    print "\nConnected directly to device: 0x%X" % snMTM.value

    #Create PM (Power Module) object
    MTMPM = brainstem.stem.MTMPM1()

    #Connect to Power Module through the MTMUSBStem
    err = MTMPM.connect_through_link_module(MTMStem)
    print "Connecting through module, Error: " + str(err)
    time.sleep(1)

    #Note:
    #***************************************************************************
    #Sets up the router for BrainStem communication
    #This is only needed once or during commissioning, but is helpful when
    #testing devices.
    router = MTMStem.system.getRouter()
    print "MTMUSBStem Router: %d" % router.value
    err = MTMPM.system.setRouter(router.value)

    #Must save and reset in order to take affect
    err = MTMPM.system.save()
    err = MTMPM.system.reset()
    #Wait for reboot
    time.sleep(.5)
    #***************************************************************************

    #Confirm that we are connected to a valid device
    snPM = MTMPM.system.getSerialNumber()
    #Debug - print "SN: %d, Err: %d" % (snPM.value, snPM.error)
    print "Connected via BrainStem network to device: 0x%X\n" % snPM.value

    #Setup all our I/O, Power, ADC etc.
    configureDevices(MTMPM, MTMStem)

    #Turn Rail on (Power)
    MTMPM.rail[0].setEnableExternal(1)
    #Allow time to stabalize
    time.sleep(.5)

    #Create testData object (Stores data and functions for handling it)
    data = testData()

    #Loop for each test (each LED)
    for x in range (0,3):

        #Print column labels
        data.printHeadder()
        data.clearErrors()

        #Turn on test channel
        #HIGH Z OPTION
        MTMStem.digital[x].setConfiguration(1)
        MTMStem.digital[x].setState(0)
        #Set pin state option
        #MTMStem.digital[x].setState(0)

        #Allow time to stabalize
        time.sleep(1)

        #Loop for controlling test itteration
        for y in range (0,1):

            #sweepTest(MTMPM, MTMStem)

            #creates a data store (list) for this test.
            #Basically a linked list made up of samples taken
            dataStore = []

            #Keeps loop going for a specific amount of timeout
            #The idea is to take as many samples as possiable in that amount of time
            timeout = time.time() + 10
            while (time.time() < timeout):

                #Get data sample
                data.gatherData()

                #Calculate sample values
                data.calculateValues()

                #Add sample list
                dataStore.append(data)

                #Print the current sample
                #1=pass=disabled (pass). Was used as debug with option 0
                data.printData(1)

            #Works with the data store.  Adds, averages, and prints
            handleData(dataStore)
            #Deletes the current store
            del(dataStore)
        ################################
        #END FOR (for y in range(0,x):)
        ###############################

        #HIGH Z OPTION
        #Turn off channel after all testing is complete
        MTMStem.digital[x].setConfiguration(4)

        #Output Configuration Option
        #Setting pin state option
        #MTMStem.digital[x].setState(1)

        #Print footer data (errors)
        data.printFooter()

    ###############################
    #END FOR (for x in range (0,3):)
    ###############################

    #Turn Rail Off after all testing
    MTMPM.rail[0].setEnableExternal(0)

else:
    print "Could not connect to device"


################################################################################
############################### END MAIN MAN ###################################
################################################################################
