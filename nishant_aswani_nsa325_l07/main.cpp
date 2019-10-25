//  File: main.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 6
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Oct 7 2019


#include "quickSortDLL.hpp"
#include <iostream>

using namespace std;

int main(){

  Data d1 (4.4, 15000, 11500);
  Data d2 (3.6, 12500, 13000);
  Data d3 (4.2, 15500, 12000);
  Data d4 (4.0, 13500, 13000);
  Data d5 (3.8, 13000, 13000);

  DoubleLinkedList list1;
  list1.tailPush(d1);
  list1.tailPush(d3);
  list1.tailPush(d4);
  list1.tailPush(d5);
  list1.tailPush(d2);
  list1.print();

  // DoubleLinkedList list2 (list1);
  // list2.print();

  list1.quickSort(list1.getHead(), list1.getTail());
  return 0;
}
