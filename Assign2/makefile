#
# PROGRAM:     assign2
# PROGRAMMER:  Alex Danilushkin
# LOGON ID:    z1809166
# DATE DUE:    September 20th
#


# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rules to link object code files to create executable file
assign2: assign2.o Book.o BookStore.o
	g++ $(CCFLAGS) -o assign2 assign2.o Book.o BookStore.o

# Rule to compile source code files to object code
assign2.o: assign2.cpp BookStore.h
	g++ $(CCFLAGS) -c assign2.cpp

Book.o: Book.cpp Book.h
	g++ $(CCFLAGS) -c Book.cpp

BookStore.o: BookStore.cpp BookStore.h
	g++ $(CCFLAGS) -c BookStore.cpp

BookStore.h: Book.h

# Pseudo-Target to Remove object code and execu files

clean:
	-rm *.o assign2 
