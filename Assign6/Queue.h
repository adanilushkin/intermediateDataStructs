/*
PROGAMMER:    Alex Danilushkin
COURSE:       241
INSTRUCTOR:   Daniel Rogness
ASSIGNMENT:   6

DUE DATE:     11/1/2016

PURPOSE:      Declartion for the Queue class

RELATED FILES:
              -Queue.cpp
              -assign6.cpp
*/
#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::underflow_error;
using std::ostream;

class Queue
{

friend ostream& operator<<(ostream&, const Queue&);

public:

Queue();
~Queue();
Queue(const Queue&);

Queue& operator=(const Queue&);
void clear();
size_t size() const;
size_t capacity() const;
bool empty() const;
int front() const;
int back() const;
void pop();
void push(int);
void reserve(unsigned int);

private:
int* array;
size_t cap;
size_t Size;

int Front;
int Back;
};
#endif
