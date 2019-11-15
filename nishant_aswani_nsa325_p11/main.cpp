//  File: main.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 9
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Nov 11 2019

#include "maxHeap.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main(){
  int values[] = {12, 11, 13, 5, 6, 7, 20, 18, 31, 2};
  int size = 10;

  maxHeap mh(size+1);

  cout << "Input Array: ";
  for (int i=0; i<size; ++i){
    cout << values[i] << ", ";
  }
  cout << endl;

  mh.buildHeap(values, size);
  cout << "Max Heap: ";
  mh.printHeap();
  mh.heapSort();
  cout << "Sorted Heap: ";
  mh.printHeap();
}
