#
#
#
#
#
#
#

CCFLAGS = -Wall -std=c++11

assign4: assign4.o Vector3.o
	g++ $(CCFLAGS) -o assign4 assign4.o Vector3.o

assign4.o: assign4.cpp Vector3.h
	g++ $(CCFLAGS) -c assign4.cpp

Vector3.o: Vector3.cpp Vector3.h
	g++ $(CCFLAGS) -c Vector3.cpp 


clean:
	-rm *.o assign4

