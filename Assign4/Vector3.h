#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>

using std::cout; using std::endl;
using std::ostream;


class Vector3
{
public:

Vector3(const double& = 0.0, const double& = 0.0, const double& = 0.0);

friend ostream& operator<<(ostream&, const Vector3&);

double& operator[](const int&);
double  operator[](const int&) const;

Vector3 operator+(const Vector3&) const;
Vector3 operator-(const Vector3&) const;

Vector3 operator*(const double&) const;
double operator*(const Vector3&) const;
friend Vector3 operator*(const double&, const Vector3&);
void operator*=(const double&);

bool operator==(const Vector3&) const;



private:
double Varray[3];
double Xcord;
double Ycord;
double Zcord;

};

#endif
