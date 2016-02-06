import os

def writePin(pin, output):
	
	#Write the value to the pin
	if output == "HIGH":
		strout = str(1)
	else:
		if output == "LOW":
			strout = str(0)
		else:
			print "Error in input, the output value to be written to " + pint + " is " + output
	cmd = "echo " + strout + " > /sys/class/gpio/gio" + str(pin) + "/value"
	print cmd
	#os.system( cmd )

def readPin(pin):

	#Read value from the pin
	

def setPin(pin, type):
	
	#Initialize pin for output
	if type == "OUTPUT":

		#Export the pin
		cmd = "echo " + str(pin) + " > /sys/class/gpio.export"
		print cmd
		#os.system( cmd )

		#Set up the pin for output
		cmd = "echo out > /sys/class/gpio/gpio" + str(pin) + "/direction"
		print cmd
		#os.system( cmd )

	#Initialize pin for input
	if type == "INPUT":

		#Export the pin
		cmd = "echo " + str(pin) + " > /sys/class/gpio.export"
		print cmd
		#os.system( cmd )

		#Set up the pin for input
		cmd = "echo in > /sys/class/gpio/gpio" + str(pin) + "/direction"
		print cmd
		#os.system( cmd )
