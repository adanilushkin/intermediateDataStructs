#ifndef SORTS_H
#define SORTS_H

#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>

using std::setw;
using std::cout; using std::endl;
using std::vector;
using std::cerr;
using namespace std;

template <class T>
class sorts{

public:

bool lessThan(const T&, const T&);

bool greaterThan(const T& item1, const T& item2);

void buildList(vector<T>& , const char* );

void printList(const vector<T>&, int, int);

};

template <class T>
void buildList(vector<T>& set, const char* fileName)
{
T item;
ifstream inFile;

inFile.open(fileName);
if(inFile.fail())
	{cerr << "Error: could not open File. Terminating process" << endl;}

inFile >> item;
while(!inFile.eof())
  {
   set.push_back(item);
   inFile >> item;
  }

inFile.close();
}

template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{
 for(size_t i = 0; i <set.size(); i++)
  {
     if(i% numPerLine == 0)
       cout << endl;
    cout << setw(itemWidth)<< set[i]  << ' ';

  }
 cout << endl;
}

template <class T>
bool lessThan(const T& item1, const T& item2)
{
if(item1 < item2)
 return true;

return false;
}

template <class T>
bool greaterThan(const T& item1, const T& item2)
{
if(item1 > item2)
  return true;

return false;
}
#endif
