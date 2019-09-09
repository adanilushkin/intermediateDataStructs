#
#
#
#
#
#
#
#

CCFLAGS= g++ -Wall -std=c++11

assign6: assign6.o Queue.o
	$(CCFLAGS) -o assign6 assign6.o Queue.o

assign6.o: assign6.cpp Queue.h
	$(CCFLAGS) -c assign6.cpp

Queue.o: Queue.cpp Queue.h
	$(CCFLAGS) -c Queue.cpp 

clean:
	-rm *.o assign6
