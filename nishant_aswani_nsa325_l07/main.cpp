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
  DoubleLinkedList list1;
  list1.tailPush(7);
  list1.tailPush(6);
  list1.tailPush(9);
  list1.tailPush(4);
  list1.tailPush(2);
  list1.tailPush(3);
  list1.print();

  // DoubleLinkedList list2 (list1);
  // list2.print();

  list1.quickSort(list1.getHead(), list1.getTail());

  list1.print();

  return 0;
}
