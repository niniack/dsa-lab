//  File: main.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 6
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 30 2019


#include "insertionSortDLL.hpp"
#include <iostream>

using namespace std;

int main(){
  DoubleLinkedList list1;
  list1.tailPush(6);
  list1.tailPush(72);
  list1.tailPush(69);
  list1.tailPush(8);
  list1.tailPush(4);
  list1.tailPush(5);
  list1.tailPush(43);
  list1.print();

  DoubleLinkedList list2 (list1);
  list2.print();

  list2.insertionSort();

  list2.print();
  list1.print();

  return 0;
}
