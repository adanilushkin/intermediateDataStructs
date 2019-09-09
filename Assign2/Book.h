#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <cstring>

using std::strcpy;
using std::cout;
using std::endl;
using std::ostream;

/*******************************************************
FILE:     Book.h
AUTHOR:   Alex Danilushkin
LOGON ID: z1809166
DUE DATE: September 20th 2016

PURPOSE:  Contains the Declaration for the book class
*******************************************************/
class Book
{
public:
//Constructor Methods
 Book();  //Default Constructor
 Book( char[], char[], double, int);  //Alternative Constructor

//Access Modifiers
 char* getISBN();//These two methods do not have associated set methods
 char* getTitle();//They do not need them as they will never change

 double getPrice();
 void setPrice(double);

 int getQuantity();
 void setQuantity(int);

//Other Methods
 void print();
 int fulfillOrder(int);
private:
//Data Members
 char isbn[11];
 char title[41];
 double price;
 int quantity;

};

#endif
