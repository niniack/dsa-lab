//  File: main.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Prelab 4
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 16 2019

#include "linkedList.hpp"
#include <iostream>

using namespace std;


int main(){
  cout << "This program demonstrates the list data structure implemented with ";
  cout << "a singly linked implementation and a put function." << endl << endl;

  cout << "There are two functions: put and print." << endl;
  cout << "Put accepts a location and a data value. It then adds a node to the ";
  cout << "given location, treating it as an index." << endl;
  cout << "Print simply prints out all the contents of the list from head to tail.";
  cout << endl << endl;

  // Queue stack;
  // cout << "Here the stack is instantiated and it is seen that there are no values.";
  // cout << endl;
  // stack.getStackSize();
  // cout << endl;

  List list;
  cout << "Here the list is instantiated and it is seen that there are no values.";
  cout << endl;
  list.getListSize();
  cout << endl;

  cout << "We can start by adding a node to the list" << endl;
  cout << "We can then view the contents of the list with print()." << endl << endl;
  list.put(0, 5);
  list.print();


  cout << "Adding a few more nodes, we can see the list growing" << endl;
  list.put(1, 6);
  list.put(2, 9);
  list.put(3, 12);
  list.print();

  cout << "We can also add in between the list." << endl;
  cout << "Let's add a node containing 8 after 6 and before 9, ";
  cout << "which is an insertion at index 2." << endl << endl;
  list.put(2, 8);

  cout << "Let's also add 2 to the top of the list" << endl;
  list.put(0, 2);
  list.print();

  cout << "We cannot add to a location beyond the size of the list." << endl;
  cout << "It does not make sense to add a node at index 7 if the list ";
  cout << "is only 6 nodes long (has 5 indices)." << endl << endl;
  list.put(7, 15);

  return 0;
}
