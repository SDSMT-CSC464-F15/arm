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

    # if the next stop wasn't found, turn around and go home
    if nextHost == None:
        print "Car broke down. Sorry, kids."
        return

    print "Next pee break: " + nextHost

    # ssh into b
    cmd = "ssh " + nextHost
    os.system( cmd )
    cmd = "hostname"
    newHost = commands.getoutput( cmd )
    
def nextStop( destHost ):
    
    # use passed in host Z to find next host B
    # Open roadmap to find next path
    print "Say Map!!"
    try:
        roadmap = open( sys.argv[2] )
    except:
        print "Dora said 'Map!', but Map no show :("
        exit()  


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
    
    print "Starting minivan..."
    
    # Check parameters
    if len( sys.argv ) != 3:
        print "Out of fuel. Fill up before starting roadtrip."
    else:
        main()
