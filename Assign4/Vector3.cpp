#include "Vector3.h"


Vector3 :: Vector3(const double& X, const double& Y, const double& Z)
{
 Varray[0] = X;
 Varray[1] = Y;
 Varray[2] = Z;
 Xcord = Varray[0];
 Ycord = Varray[1];
 Zcord = Varray[2];

}

ostream& operator<<(ostream& output, const Vector3& vec)
{
 output <<"(" << vec[0] << ", "<< vec[1] << ", " << vec[2] << ")";

 return output;
}

double& Vector3::operator[](const int& index) //for writing
{
 return Varray[index];
}

double Vector3::operator[](const int& index) const //for reading
{
 return Varray[index];
}


//*******************addition
Vector3 Vector3::operator+(const Vector3& vec) const
{Vector3 SumVec = *this;
 SumVec.Xcord = SumVec.Xcord + vec.Xcord;
 SumVec.Ycord = SumVec.Ycord + vec.Ycord;
 SumVec.Zcord = SumVec.Zcord + vec.Zcord;

 SumVec[0] = SumVec.Xcord;
 SumVec[1] = SumVec.Ycord;
 SumVec[2] = SumVec.Zcord;

 return SumVec;
}

//*****************Subtraction
Vector3 Vector3::operator-(const Vector3& MinusVec) const
{
 Vector3 Vec = *this;
 Vector3 New;
 New.Xcord = MinusVec.Xcord * -1;
 New.Ycord = MinusVec.Ycord * -1;
 New.Zcord = MinusVec.Zcord * -1;
 return (Vec + New);
}



//*****************Multiplitcation
Vector3 Vector3::operator*(const double& scalar) const // Vector * scalar
{ Vector3 vec = *this;
 vec[0] *= scalar;
 vec[1] *= scalar;
 vec[2] *= scalar;

 return vec;
}

Vector3 operator*(const double& left, const Vector3& right) // Scalar * Vector
{
// return (right * left);
 return (right * left);
}

void Vector3::operator*=(const double& mult)
{ Vector3 alpha = *this;
 for(int i = 0; i < 3; i++)
  {
   alpha[i] = alpha[i] * mult;
   }
}

double Vector3::operator*(const Vector3& Multiplier) const
{
 Vector3 New;
 double product = 0;
 Vector3 vector1 = *this;
 for(int i = 0; i < 3; i++)
 {
  New[i] = vector1[i] * Multiplier[i];
  product += New[i];
 }
 return product;
}

//**************************Equality

bool Vector3::operator==(const Vector3& v2) const
{ Vector3 v1 = *this;
 if(v1[0] == v2[0] && v1[1] == v2[1] && v1[2] == v2[2])
  return true;
 else
  return false;
}
