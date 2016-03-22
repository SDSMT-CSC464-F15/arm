all:
	gcc test.cc -o test -lwiringPi -lpthread
	gcc testReceive.cc -o testReceive -lwiringPi -lpthread
	gcc write.c -o write -lwiringPi -lpthread
	gcc read.c -o read -lwiringPi -lpthread
clean:
	rm -f *.o
dist-clean:
	rm -f test
	rm -f testReceive
	rm -f read
	rm -f write
