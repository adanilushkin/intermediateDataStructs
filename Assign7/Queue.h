/********************************************************
* PROGAMMER:   Alex Danilushkin
* COUSRE:      241
* INSTRUCTOR:  Daniel Rogness
* ASSIGNMENT:  7
*
* DUE DATE:    11/10/16
*
* PURPOSE: Declarations for the Queue<T> class
*          and the definations for the Queue class
* RELATED FILES:
*           - assign7.cpp
*********************************************************/


//********************HEADERS****************************/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

using std::ostream;
using std::cout;
using std::endl;
using std::underflow_error;



/*******************************************   Node Struct
*Arguments: general class <T>
*
*Returns:   nothing
*
*Summary:   The structure for the node.
*********************************************************/
//struct for Node
template <class T>
struct Node
 {
  T data;
  Node<T>* next;

  Node(const T& = T(), Node<T>* next = nullptr);
 };

template <class T>
Node<T>::Node(const T& newData, Node<T>* newNext)
 {
  data = newData;
  next = newNext;
 }


template <class T>
class Queue;

template <class T>
ostream& operator<<(ostream&, const Queue<T>&);



/*******************************************   Queue Class
*Summary: The declation statments for the Queue class
*
*********************************************************/
template <class T>
class Queue
{
 public:
   //constructors
   Queue();
   ~Queue();
   Queue(const Queue&);

   //operator overloads
   Queue<T>& operator=(const Queue<T>&);
   friend ostream& operator<< <>(ostream&, const Queue<T>&);

   //methods
   void clear();
   size_t size() const;
   bool empty() const;
   T& front() const;
   T& back() const;
   void push(const T&);
   void pop();

 private:
   Node<T>* qFront;
   Node<T>* qBack;
   size_t qSize;
};



/*************************************   Queue Constructor
*Arguments: None
*
*Returns:   nothing
*
*Summary:   The default consturctor for the Queue class.
*           Sets an empty Queue.
*********************************************************/
template <class T>
Queue<T>::Queue()
{
 qFront = qBack = nullptr;
 qSize = 0;
}


/**************************************   Queue Destructor
*Arguments: None
*
*Returns:   nothing
*
*Summary:   Clears and resets the Queue by calling the
            clear method.
*********************************************************/
template <class T>
Queue<T>::~Queue()
{
 clear();
}


/********************************   Queue Copy Constructor
*Arguments: A const general class T Queue refrence
*
*Returns:   nothing
*
*Summary:   Creates a copy of a Queue from another Queue.
*********************************************************/
template <class T>
Queue<T>::Queue(const Queue<T>& copy)
{
 qFront = qBack = nullptr;
 qSize = 0;

 Node<T>* ptr;
 for(ptr = copy.qFront; ptr != nullptr; ptr = ptr->next)
  { push(ptr->data);}
}



//******************* OPERATOR OVERLOADS ***************



/*******************************************   OPERATOR: =
*Arguments: const Queue reference
*
*Returns:   Queue reference
*
*Summary:   Overloads the = operator.
*********************************************************/
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& copy)
{
 if(this != &copy)
  {
   clear();

   Node<T>* ptr;
   for(ptr = copy.qFront; ptr != nullptr; ptr = ptr->next)
     {push(ptr->data);}
  }

 return *this;
}



/*******************************************   OPERATOR <<
*Arguments: Ostream referance and const Queue
*
*Returns:   Ostream Reference
*
*Summary:   Prints out the contents of the Queue
*********************************************************/
template <class T>
ostream& operator<<(ostream& output, const Queue<T>& print)
{
 Node<T>* ptr;
 for(ptr = print.qFront; ptr != nullptr; ptr = ptr->next)
   output << ptr->data << " ";

 return output;
}



//********************** METHODS *************************


/*****************************************   Method: Clear
*Arguments: None
*
*Returns:   Void
*
*Summary:   Resest the Queue and sets the pointers to
            null.
*********************************************************/
template <class T>
void Queue<T>::clear()
{
 while(empty() == false)
  {
    pop();
  }
 qSize = 0;
 qFront = qBack = nullptr;
}



/******************************************   Method: Size
*Arguments: None
*
*Returns:   Size_t
*
*Summary:   Returns the size of the Queue
*********************************************************/
template <class T>
size_t Queue<T>::size() const
{
 return qSize;
}




/****************************************   Method: Empty
*Arguments: None
*
*Returns:   Boolean
*
*Summary:   Checks if the Queue is empty. Returns true
            if empty.
*********************************************************/
template <class T>
bool Queue<T>::empty() const
{
 if( qFront == nullptr && qBack == nullptr)
   return true;

 return false;
}



/*****************************************   Method: Front
*Arguments: None
*
*Returns:   General class reference
*
*Summary:   Returns the item reference at Front. Method
            is const to avoid changing the item
            reference.
*********************************************************/
template <class T>
T& Queue<T>::front() const
{
 if(empty() == true)
   throw underflow_error("Exception: Queue underflow on front()");

 return qFront->data;
}




/******************************************   Method: Back
*Arguments: None
*
*Returns:   General class reference
*
*Summary:   Returns the item reference at the back of the
            Queue. Method is const to not change the item.
*********************************************************/
template <class T>
T& Queue<T>::back() const
{
 if(empty())
   throw underflow_error("Exception: Queue underflow on back()");

 return qBack->data;
}



/*******************************************   Node Struct
*Arguments: general class <T>
*
*Returns:   nothing
*
*Summary:   The structure for the node.
*********************************************************/
template <class T>
void Queue<T>::push(const T& item)
{
 Node<T>* newNode = new Node<T>(item);
 if(empty())
   qFront = newNode;
 else
   qBack->next = newNode;

 qBack = newNode;
 qSize++;
}



/*******************************************   Node Struct
*Arguments: general class <T>
*
*Returns:   nothing
*
*Summary:   The structure for the node.
*********************************************************/
template <class T>
void Queue<T>::pop()
{
 if(empty())
   throw underflow_error("Execption: underflow on pop()");

 Node<T>* delNode = qFront;
 qFront = qFront->next;

 if(qFront == nullptr)
   qBack = nullptr;

 delete delNode;
 qSize--;
}

#endif
