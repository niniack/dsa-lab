//  File: main.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 11
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Nov 11 2019

#include "maxHeap.hpp"
#include <iostream>

using namespace std;

int main(){
  int values[] = {12, 11, 13, 5, 6, 7, 20, 18, 2};
  int size = 9;

  maxHeap mh;

  cout << "Input Array: ";
  for (int i=0; i<size; ++i){
    cout << values[i] << ", ";
  }
  cout << endl;

  mh.buildHeap(values, size);
  cout << "Built Heap (PreOrder): ";
  mh.preOrderPrint(mh.getRoot());
  cout << endl;
  
}
