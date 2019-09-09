#
#
#
#
#
#
#

CCFLAGS = -Wall -std=c++11

assign5: assign5.o VectorN.o
	g++ $(CCFLAGS) -o assign5 assign5.o VectorN.o

assign5.o: assign5.cpp VectorN.h
	g++ $(CCFLAGS) -c assign5.cpp

VectorN.o: VectorN.cpp VectorN.h
	g++ $(CCFLAGS) -c VectorN.cpp 


clean:
	-rm *.o assign5

