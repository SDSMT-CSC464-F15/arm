''' 
 sendMsgFile.py

 This mode of communication takes the file that is in the ODROID and finds the path
 to the path through the file.

 In progress...

 Basic algorithm:

 Tell computer A to get to computer Z.
 A will open roadmap.txt and find next computer B to get to Z.
 It will ssh into B.
 It will repeat in B, C, D, ... until it gets to Z

'''
# my stupid notes - cns
# /etc/network/hostname
# command 'hostname' will give hostname
# cmd = "stuff"
# os.system( cmd )

import sys
import os
import commands

def main():
   
    # the destination host  
    destHost = sys.argv[1]
    
    # check to see if we reached destination
    cmd = "hostname"
    currentHost = commands.getoutput( cmd )
    if destHost == currentHost:
        print "You have reached your destination"
        return

    # use passed in host Z to find next host B
    nextHost = nextStop( destHost )
    print nextHost

    # if the next stop wasn't found, turn around and go home
    if nextHost == None:
        print "Car broke down. Sorry, bud."
        return

    # ssh into b

def nextStop( destHost ):
    
    # use passed in host Z to find next host B
    roadmap = open( "roadmap.txt" )
    
    # go through each line 
    for line in roadmap:
        words = line.split()
        # go through each word
        for i in range( 0, len(words) ):
            # find the destination host
            if words[i] == destHost:
                # try to get the next value. try-except for overstepping
                try:
                    # retrieve the next stop
                    return words[i+1]
                except:
                    return None

    # no next stop was found
    return None

if __name__ == "__main__":
    
    if len( sys.argv ) != 2:
        print "no no"
    else:
        main()
