#Programmer: Alex Danilushkin
#z ID:       Z190166
#Course:     241
#
#Due Date:   11/10/16
#
#

CCFLAGS= g++ -Wall -std=c++11

assign7: assign7.o
	$(CCFLAGS) -o assign7 assign7.o

assign7.o: assign7.cpp Queue.h
	$(CCFLAGS) -c assign7.cpp

clean:
	rm *.o assign7
