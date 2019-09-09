#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <vector>


template <class T>
class quicksort{
public:

void quickSort(vector<T>&, bool /*(*compare)(const T&, const T&)*/);

void quickSort(vector<T>&, int, int, bool);

int partition(vector<T>&, int, int, bool);
};

template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, cosnt T&)){
 quickSort(set, 0, set.size() -1, compare);
}

template <class T>
int
