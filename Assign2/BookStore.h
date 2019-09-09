#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include "Book.h"
#include <cstring>

using std :: strcmp;


class BookStore{
public:
//************Constructors***********

//Default Constructor
 BookStore();
//Alt Constructor
 BookStore(const char*);


//*************Methods**************
 void print();

 void sortByISBN();

 int searchForISBN(char []);

 void processOrders(const char*);

//**********Data Members************

private:
 Book bookStock[30];

 int numStock;

};

#endif
