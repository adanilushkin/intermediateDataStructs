/*
Progammer: Alex Danilushkin

Course:    241

Instuctor: Daniel Rogents

Assignment:5

Due Date:  10/23/2016

Purpose: Declaration for our VectorN class
*********************************************************/
#ifndef VECTORN_H
#define VECTORN_H

#include <iostream>
#include <stdlib.h>
#include <stdexcept>

using std::cout; using std::endl;
using std::ostream;
using std::out_of_range;

class VectorN
{

friend ostream& operator<<(ostream&, const VectorN&);

public:

//constuctors
VectorN();
VectorN(const double[], size_t);
VectorN(const VectorN&);

//destructor
~VectorN();

//Methods
void clear();
size_t size() const;
double at(int) const;
double& at(int);

//operator Overloads

double  operator[](const int) const; // reading the subscript
double& operator[](const int); //writing to the subscript

VectorN operator+(const VectorN&) const;

VectorN operator-(const VectorN&) const;

//overloaded 3 times
//one for vec*vec, vec*doub, and doub* vec
VectorN operator*(const double&) const;
double operator*(const VectorN&) const;
friend VectorN operator*(const double&, const VectorN&);


bool operator==(const VectorN&) const;
VectorN& operator=(const VectorN&);


private:
double* Vap; //vector array pointer Vap
size_t capacity;


};

#endif
