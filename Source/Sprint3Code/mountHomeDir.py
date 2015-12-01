import os

def Main():
	
	hosts = [ 'snow_white', 'dopey', 'sleepy', 'grumpy', 'doc', 'happy', 'bashful', 'sneezy' ]

	for host in hosts:
		if host != 'snow_white':
			cmd = "ssh odroid@" + host + " 'mount -t nfs snow_white:/home /home'"
			os.system( cmd )

if __name__ == '__main__':
	Main()