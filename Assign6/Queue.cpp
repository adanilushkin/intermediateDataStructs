/*
PROGAMMER:     Alex Danilushkin
COURSE:        241
INSTRUCTOR:    Daniel Rogness
ASSIGNMENT:    6

DUE DATE:      11/1

PURPOSE:       To create and understand a
               functioning Queue

RELATED FILES:
               -Queue.h
               -assign6.cpp
**************************************************/
#include "Queue.h"




/*                                Queue Constructor
Arguments: None

Returns:   Nothing

Summary:   Defualt Constructor for the Queue class
**************************************************/
Queue::Queue()
{
 Front = 0;
 Back = cap - 1;
 array = nullptr;
 Size = 0;
 cap = 0;
}


/*                                 Queue Destructor
Arguments: None

Returns:   Nothing

Summary:   Destroys the Queue object when the diver
           is done running
**************************************************/
Queue::~Queue()
{
 Front = 0;
 Back = cap -1;
 delete array;
}



/*                           Queue Copy Constructor
Arguments: Queue object Reference

Returns:   Nothing

Summary:   Creates a Queue object from another
           Queue object.
**************************************************/
Queue::Queue(const Queue& Copy)
{
 cap = Copy.cap;
 Size = Copy.Size;

 array = new int[cap];

 for(size_t i = 0; i < Size; i++)
 {
  array[i] = Copy.array[i];

 }

 Front = 0;
 Back = Size-1;
}


/*                                    OVERLOAD: <<
Arguments: -Ostream
           -Queue object Reference

Returns:   Ostream

Summary:   This standalone function takes the
           contents inside the queue's array and
           prints them out
**************************************************/
ostream& operator<<(ostream& stuff, const Queue& Q)
{
 size_t current, i;
 for(current = Q.Front, i = 0; i < Q.Size; ++i)
 {
  stuff << Q.array[current] << " ";

  current = (current + 1) % Q.cap;
 }

 return stuff;
}


/*                                     OVERLOAD: =
Arguments: Queue Object Reference

Returns:   Reference to the object being modified

Summary:   copies the contents of a Queue object to
           another one
**************************************************/
Queue& Queue::operator=(const Queue& Q)
{
 if(this == &Q)
  return *this;

 delete array;
 cap = Q.cap;
 Size = Q.Size;
 Front = Q.Front;
 Back = Q.Back;
 array = new int[Q.cap];

 if(Q.cap == 0)
  {array = nullptr; return *this;}

 for(size_t i = 0; i < cap; ++i)
 {
  array[i] = Q.array[i];
 }

 return *this;
}


/*                                    METHOD: CLEAR
Arguments: None

Returns:   Void

Summary:   Clears the contents of the Queue object
**************************************************/
void Queue::clear()
{
 delete[] array;
 array = nullptr;
 Size = 0;
 Front = 0;
 Back = cap - 1;
}


/*                                    METHOD: SIZE
Arguments: None

Returns:   Unsigned Integer

Summary:   Returns the Size of the Queue. In other
           words, how many integers are currently
           active inside the Queue.
**************************************************/
size_t Queue::size() const
{
 return Size;
}


/*                                 METHOD: CAPACITY
Arguments: None

Returns:   Unsigned Integer

Summary:   Returns the Capacity of the Queue. In
           other words, how many elements can be
           inside the Queue at a given time.
**************************************************/
size_t Queue::capacity() const
{
 return cap;
}

bool Queue::empty() const
{
 if(Size == 0)
  return true;

 return false;
}


/*                                    METHOD: FRONT
Arguments: None

Returns:   Integer

Summary:   Returns the integer found at the Front
           subscript. Throws an error if the Queue
           is empty.
**************************************************/
int Queue::front() const
{
 if(empty())
  throw underflow_error ("Nothing in the Queue. Please add things to Queue to use method properly");

 return array[Front];
}



/*                                    METHOD: BACK
Arguments: None

Returns:   Integer

Summary:   Returns the integer found at the Back
           subscript. Throws an error if the Queue
           is empty.
**************************************************/
int Queue::back() const
{
 if(empty())
  throw underflow_error ("Nothing in the Queue. Please add things to Queue to use method properly");

 return array[Back];
}


/*                                      METHOD: POP
Arguments: None

Returns:   Void

Summary:   This method "pops" off the front
           subscript making the value no longer in
           use by the Queue. If there is nothing
           inside the Queue then it throws an
           error.
**************************************************/
void Queue::pop()
{
 if(empty())
  throw underflow_error ("Nothing in the Queue. Please add things to Queue to use method properly");

   Front = (Front+1)% cap;

  Size--;
}



/*                                     METHOD: PUSH
Arguments: Integer

Returns:   Void

Summary:   This method adds an integer to the
           Queue. This item will be the new Back.
           If there is not enough room in the Queue
           then it calls the Reserve method which
           allocates more memory.
**************************************************/
void Queue::push(int item)
{

 if(cap == 0)
    reserve(size_t(1));
 if( Size == cap)
    reserve(size_t(cap));

 Size++;
 if((size_t)Back == (cap - 1))
  {Back = 0; array[Back] = item;}
 else
  {Back++; array[Back] = item;}
}



/*                                  METHOD: RESERVE
Arguments: Unsigned Integer

Returns:   Void

Summary:   This method is called by the push
           method. It allocates more memory to a
           Queue. If there is currently at 0
           capacity then it adds a single chunk of
           memory. Otherwise, it doubles the
           capacity of the Queue.
**************************************************/
void Queue::reserve(unsigned int addCap)
{
 if(addCap == (size_t)1)
  {array = new int[addCap]; Front = 0; cap = addCap; Back = 0;}
 if(addCap >= (size_t)1)

 {

  int temp[Size];
  size_t current, i;

  for(current = Front, i = 0; i < Size; i++)
   {
    temp[i] = array[current];

    current = (current + 1) % cap;
   }

  cap = cap + addCap;
  delete[] array;
  array = new int[cap];

  for(i = 0; i < Size; i++)
   {
    array[i] = temp[i];
   }
  Front = 0;
  Back = Size -1;
 }
}
