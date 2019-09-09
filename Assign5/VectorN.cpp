/*
Programmer: Alex Danilushking
Course:     241
Instructor: Daniel Rogness
Assignment: 5

Due Date: 10/23/2016

purpose: defines class methods for VectorN data type

Related Files:
  - Vector.h
  - assign5.cpp
***************************************************/

#include "VectorN.h"




//**************************************************Constructors

/*                              Defualt Constructor
Arguements: none

Returns:    nothing

Summary:    Defualt constructor for VectorN class
**************************************************/
VectorN::VectorN()
{
 Vap = nullptr;
 capacity = 0;
}


/*                          Alternative Constructor
Arguments: -array of doubles
           -unsigned integer

returns:   nothing

Summary:   creates a VectorN object from the Array
           of double that it tames in. The unsigned
           int is the size of the array.
**************************************************/
VectorN::VectorN(const double inputs[], size_t size)
{
 Vap = new double[size];
 for(size_t i = 0; i < size; i++)
 {
  Vap[i] = inputs[i];
 }
 capacity = size;
}


/*                                  Copy Construtor
Arguments: VectorN

Returns:   Another VectorN object

Summary:   Copies VectorN to a new VectorN object
**************************************************/
VectorN::VectorN(const VectorN& Copy)
{
 capacity = Copy.capacity;
 Vap = new double[capacity];

 for(size_t i =0; i < capacity; i++)
 {
  Vap[i] = Copy[i];
 }
}

/*                                      Destructor
Arguments: none

Returns:   nothing

Summary:   Destroys and Deletes the unused or
           unwanted object.
*************************************************/
VectorN::~VectorN()
{
 clear();
}

//***************************************************Operators

/*                                    OVERLOAD: =
Arguments: VectorN reference

Returns:   VectorN reference

Summary:   Checks they are already the same. if
           the Vectors are not then clear out
           the first Vectors contents and assign
           the reference vector to "this" Vector
************************************************/
VectorN& VectorN::operator=(const VectorN& other)
{ if( this == &other )
   {return *this;}

 else{
  delete Vap;
  capacity = other.capacity;

  if(other.capacity == 0)
   { Vap = nullptr; return *this;}

  Vap = new double[other.capacity];

 for(size_t i = 0;  i < other.capacity; i++)
  {
   Vap[i] = other[i];
  }
 }


 return *this;
}


/*                                   OVERLOAD: +
Arguments: VectorN Reference

Returns:   VectorN object

Summary:   Adds the componets of the two Vectors
           together. Only returns the least
           amount of components.
***********************************************/
VectorN VectorN::operator+(const VectorN& VecOperand) const
{
 if( capacity == 0)
  return VecOperand;
 else if (VecOperand.capacity == 0)
  return *this;

 else
 {
  VectorN temp;
  size_t minSize;
  if(capacity < VecOperand.capacity)
   {minSize = capacity;
   temp = *this;}
  else
  {minSize = VecOperand.capacity;
   temp = VecOperand;}

  for(size_t i =0; i < minSize; i++)
  {
    temp[i] = Vap[i] + VecOperand[i];
  }
  return temp;
 }
}


/*                                   OVERLOAD: -
Arguments: VectorN Reference

Returns:   VectorN object

Summary:   Subtracts the components of the two
           Vectors. Again, as with addition,
           only returns least amount of elements
***********************************************/
VectorN VectorN::operator-(const VectorN& VecOperand) const
{ VectorN temp = VecOperand * -1.0;
  return (*this + temp);
}


/*                                   OVERLOAD: *
Arguments: VectorN Reference

Returns:   double

Summary:   Multiples each element of the two
           Vectors together then adds it all up
***********************************************/
double VectorN::operator*(const VectorN& VecOperand) const//scalar prodcut
{
 double result = 0;
 size_t minSize;

 if(capacity < VecOperand.capacity)
  minSize = capacity;
 else
  minSize = VecOperand.capacity;

 for(size_t i = 0; i < minSize; i++)
 {
  result = result + (Vap[i] * VecOperand[i]);
 }
 return result;
}


/*                                  OVERLOAD: *
Arguments:  double Reference

Returns:    VectorN object

Summary:    This takes a double values and
            multiplies it to each element of
            the vector array
**********************************************/
VectorN VectorN::operator*(const double& scalar) const// Vector * scalar
{ VectorN temp = *this;
  for(size_t i = 0; i < capacity; i++)
  {
   temp[i] = Vap[i] * scalar;
  }
 return temp;
}


/*                                OVERLOAD: *
Arguments: -double Reference
           -VectorN Reference

Returns:   VectorN object

Summary:   Multiples each element of the array
           with the double quantity.
*********************************************/
VectorN operator*(const double& scalar, const VectorN& VecOperand) // Scalar * Vector
{
 return (VecOperand * scalar);
}


/*                                OVERLOAD: ==
Arguments: VectorN Reference

Returns:   Boolean

Summary:   Tests if two VectorN objects are
           equal to eachother buy checking
           if elements are equal
*********************************************/
bool VectorN::operator==(const VectorN& VecOperand) const
{
 if(capacity != VecOperand.capacity)
  return false;

 for(size_t i =0; i < capacity; i++)
 {
  if( Vap[i] != VecOperand[i])
  {return false;}
 }
 return true;
}


/*                                OVERLOAD: []
Arguments: integer

Returns:   double Reference

Summary:   Writes to the VectorN object
           changing only one element
*********************************************/
double& VectorN::operator[](const int index) //writing to VectorN
{
 return Vap[index];
}


/*                               OVERLOAD: []
Arguments: integer

Returns:   double

Summary:   Reads the value found in the
           pointer array of the VectorN
           object
********************************************/
double VectorN::operator[](const int index) const //reading from VectorN
{
 return Vap[index];
}


/*                              OVERLOAD: <<
Arguments: -ostream Reference
           -VectorN Reference

Returns:   ostream Reference

Summary:   Overloads the operator for "<<".
           Allows the user to print out the
           VectorN object
*******************************************/
ostream& operator<<(ostream& output, const VectorN& VecOperand)
{
 output << "(";
 for(size_t i = 0; i < VecOperand.capacity; i++)
   {
    if(i < VecOperand.capacity - 1)
      output << VecOperand[i] << ", ";
    else
      output << VecOperand[i];
   }
 output << ")";

return output;
}
//*****************************************************Methods


/*                                  clear()
Arguments: none

Returns:   void

Summary:   Frees memory by getting rid of
           data for a VectorN object
******************************************/
void VectorN::clear()
{
 Vap = nullptr;
 capacity = 0;
}


/*                                  size()
Arguments: none

Returns:   size_t

Summary:   Returns the capacity of the
           VectorN array
*****************************************/
size_t VectorN::size() const
{
 return capacity;
}


/*                                   at()
Arguments: integer

Returns:   double

Summary:   checks to see if the subscript
           is out of range. If it is not
           then it returns the value
           at whatever subscript
****************************************/
double VectorN::at(int sub) const //reads Vector elements
{
 if((unsigned)sub < 0 || (unsigned)sub >= (capacity))
  throw out_of_range("subscript out of range");

 return Vap[sub];
}


/*                                  at()
Arguments: integer

Returns:   double Reference

Summary:   Checks to see if the integer
           given is in bounds of array's
           scope. If so then we write to
           the element
***************************************/
double& VectorN::at(int sub) //writes to
{
 if((unsigned)sub < 0 || (unsigned)sub >= capacity)
  throw out_of_range("subscript out of range");

 return Vap[sub];
}

