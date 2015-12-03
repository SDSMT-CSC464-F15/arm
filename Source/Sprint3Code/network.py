#!/usr/bin/python

import fileinput
import os

if os.geteuid() != 0:
	exit("Forgot the sudo :(")

addComment = False
removeComment = False
for line in fileinput.input("/etc/network/interfaces", inplace=True):
	if line == "auto eth0\n":
		addComment = True
	if line == "# auto eth0\n":
		removeComment = True
	if addComment:	
		print "# %s" % (line),
	else:
		if removeComment:
			print "%s" % (line[2:]),
		else:
			print "%s" % (line),
os.system("ifdown eth0")
os.system("ifup eth0")
