
#include "Book.h"
//*******************************************************
//
//FILE:         Book.cpp
//AUTHOR:       Alex Danilushkin
//LOGON ID:     z1809166
//DUE DATE:     September 20th

//PURPOSE:      Contains methods for Book class
//*******************************************************


//*******************************************************
//*******************Constructors************************
//******************************************************/


//Defualt Constructor
Book::Book()
{
 isbn[0] = '\0';
 title[0] = '\0';
 price = 0.00;
 quantity = 0;
}

//Alternative Constructor
Book::Book(char *newISBN, char *newTitle, double newPrice, int newQuantity)
{
 strcpy(isbn, newISBN);
 strcpy(title, newTitle);

 if (newPrice < 0)
  {newPrice = 0;}

 if (newQuantity < 0)
  {newQuantity = 0;}

 setPrice(newPrice);
 setQuantity(newQuantity);
}

/*******************************************************
******************Accessor Methods**********************
*******************************************************/

//*******************************************SET METHODS

void Book::setPrice(double newPrice)
{ price = newPrice; }

void Book::setQuantity(int newQuantity)
{ quantity = newQuantity; }

//*******************************************Get Methods

char* Book::getISBN()
{return isbn;}

char* Book::getTitle()
{return title;}

double Book::getPrice()
{return price;}

int Book::getQuantity()
{return quantity;}

//*****************************************Other Mehtods

void Book:: print()
{ cout << isbn << endl;
  cout << title << endl;
  cout << price << endl;
  cout << quantity << endl;}

int Book:: fulfillOrder(int wantedQ)
{ int toShip = 0;
  if(wantedQ <= 0)
   {return toShip;}

  else if (wantedQ <= quantity)
   { toShip = wantedQ;
     setQuantity(quantity - wantedQ);
     return toShip;}
  else if (wantedQ > quantity)
   { toShip = quantity;
     setQuantity(0);
     return toShip;}
  else
   return 0;
}
