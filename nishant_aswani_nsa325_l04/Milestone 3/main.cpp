//  File: main.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 4
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 16 2019

#include "m3_metro.hpp"
#include <iostream>

using namespace std;


int main(){
  cout << "This program displays the Abu Dhabi metro line ";
  cout << "using a singly linked-list as its implementation." << endl << endl;

  cout << "There are three functionalities: put, remove, reverse, and print." << endl;
  cout << "Put accepts a location and a data value. It then adds a node to the ";
  cout << "given location, treating it as an index." << endl;
  cout << "Remove accepts a station name and removes that station if it is a ";
  cout << "part of the list." << endl;
  cout << "Reverse traverses the list to reverse the links of each node." << endl;
  cout << "Print simply prints out all the contents of the list from head to tail.";
  cout << endl << endl;

  List list;

  cout << "We can start by using the list from milestone 1." << endl;
  cout << "We can then view all the stations of the list with print()." << endl << endl;
  list.put(0, "Marina Mall");
  list.put(1, "Founder's Memorial" );
  list.put(2, "Madinat Zayet Shopping Center");
  list.put(3, "New York University Abu Dhabi (NYUAD)");
  list.put(2, "Khalidiyah Mall");
  list.put(4, "Abu Dhabi Mall");
  list.put(5, "The Galleria Mall");
  list.put(6, "Manarat Al Saadiyat");
  list.print();

  cout << "For providing service the other way, we can reverse the list " << endl;
  cout << "using the reverse() method." << endl << endl;
  list.reverse();
  list.print();

  return 0;
}
