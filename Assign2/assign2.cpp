#include "Book.h"
#include "BookStore.h"

int main()
{
//Beginning of Book************************************
//Setting Variables for Book Class
char isbn1[11] = "1234567890";
char title1[41] = "wow";
char isbn2[11] = "0987654321";
char title2[41] = "holy wow";
int numShipped;

//Testing Book Class
 Book Default;

 Book book1(isbn1, title1, 300.00, 12);

 Book book2(isbn2, title2, -12.0, -4);

 cout << "Printing Default\n\n" ;
 Default.print();
 cout << endl << endl;

 cout << "Printing book1\n\n";
 book1.print();
 cout << endl << endl;

 cout << "Printing book2\n\n";
 book2.print();
 cout << endl << endl;

 cout << book1.getISBN() << endl;
 cout << book1.getTitle() << endl;
 cout << book1.getPrice() << endl;
 cout << book1.getQuantity()<< endl;

 numShipped = book1.fulfillOrder(-4);
 cout << "\nShipped " << numShipped << endl;
 cout << "Quantity now " << book1.getQuantity() << endl;

 numShipped = book1.fulfillOrder(3);
 cout << "Shipped " << numShipped << endl;
 cout << "Quantity now " << book1.getQuantity() << endl;

//Beginnig of BookStore***********************************
 cout << "\n\nWe are now in BookStore\n" << endl;
 BookStore Store1("bookdata");

 Store1.print();

 Store1.processOrders("orders.txt");

 Store1.print();
return 0;
}
