#!/usr/bin/python

import fileinput
import os

if os.geteuid() != 0:
	exit("Forgot the sudo :(")

addComment = False
removeComment = False
for line in fileinput.input("/etc/network/interfaces", inplace=True):
	if line.startswith("auto eth"):
		addComment = True
	if line.startswith("# auto eth"):
		removeComment = True
	if addComment:	
		print "# %s" % (line),
	else:
		if removeComment:
			print "%s" % (line[2:]),
		else:
			print "%s" % (line),
os.system("service network-manager restart")
