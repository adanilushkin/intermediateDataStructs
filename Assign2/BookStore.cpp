#include "BookStore.h"
#include <fstream>

using std::ios;
using std::ifstream;
using std::cerr;

//***************************************Constructors

//Default Constructor
BookStore:: BookStore()
{
// for(int i=0; i< 30; i++)
// {
//   bookStock[i] = Book();
// }
 numStock = 0;
}
//Alt Constructor
BookStore:: BookStore(const char* Book)
{numStock = 0;

 ifstream inFile(Book, ios:: binary);
// inFile.open(Book);

 if (inFile.fail())
 {cerr << "Error: could not open File. Ending Process" << endl;
  exit(-1);
 }

 inFile.read((char*) this, sizeof(BookStore));
 cout << numStock << endl;
 inFile.close();

 sortByISBN();
}


//********************************************Method
void BookStore:: print()
{//numStock = 0;

 for(int i = 0; i < numStock; i++)
 // {if (bookStock[i].getQuantity()!= 0)
    {
     bookStock[i].print();
     cout << endl;
//     numStock += 1;
   }
//  }

}


void BookStore :: sortByISBN()
{
 int i, j;
 Book bucket;

 for(i = 1; i < numStock; i++)
  {
   bucket = bookStock[i];

   for(j = i;(j > 0) && (strcmp(bookStock[j-1].getISBN(), bucket.getISBN()) > 0); j--)
    bookStock[j] = bookStock[j-1];

   bookStock[j] = bucket;
  }
}

int BookStore:: searchForISBN(char searchISBN[])
{
 int low = 0;
 int high = numStock -1;
 int mid;


 while (low <= high)
 {
  mid = (low + high) / 2;
// cout <<"Book Stock quna" << bookStock[mid].getQuantity() << endl;
// cout <<"isbn searching" << searchISBN << endl;
 if(strcmp(searchISBN, bookStock[mid].getISBN()) == 0)
  return mid;

 if(strcmp(searchISBN, bookStock[mid].getISBN()) < 0)
  {high = mid - 1;}

 else
  low = mid + 1;

 }


 return -1;
}

void BookStore :: processOrders(const char* order)
{
 ifstream inFile;
 char orderNumber[7];
 char isbn[11];
 int orderQuantity;
 int numShipped;

 inFile.open(order);
 if (inFile.fail())
 {cerr << "File could not be opened. Terminating" << endl;
  exit(-1);
 }

  inFile >> orderNumber;
 while(! inFile.eof())
 {
  inFile >> isbn;
  inFile >> orderQuantity;

  int index = searchForISBN(isbn);
  if (index == -1)
  {cerr << "Error has Occurred. Null perameters" << endl;}
  else
  {
   int numShipped =  bookStock[index].fulfillOrder(orderQuantity);
   bookStock[index].print();
   cout << numShipped << " Where sent out" << endl;
  }
  inFile >> orderNumber;
 }
 inFile.close();
}
