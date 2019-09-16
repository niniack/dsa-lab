//  File: main.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Prelab 4
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 16 2019

#include "m1_metro.hpp"
#include <iostream>

using namespace std;


int main(){
  cout << "This program displays the Abu Dhabi metro line ";
  cout << "using a singly linked-list as its implementation." << endl << endl;

  cout << "There are two functionalities: put and print." << endl;
  cout << "Put accepts a location and a data value. It then adds a node to the ";
  cout << "given location, treating it as an index." << endl;
  cout << "Print simply prints out all the contents of the list from head to tail.";
  cout << endl << endl;

  List list;
  cout << "Here the list is instantiated and it is seen that there are no metro stations.";
  cout << endl << endl;
  list.getListSize();
  cout << endl;

  cout << "We can start by adding the first four stations to the list." << endl;
  cout << "We can then view all the stations of the list with print()." << endl << endl;
  list.put(0, "Marina Mall");
  list.put(1, "Founder's Memorial" );
  list.put(2, "Madinat Zayet Shopping Center");
  list.put(3, "New York University Abu Dhabi (NYUAD)");
  list.print();


  cout << "We can now add two additional stations." << endl;
  cout << "Khalidiyah Mall is in between index 1 and 2, so we will place at index 2. " << endl;
  cout << "Abu Dhabi Mall is then between index 3 and index 4, so we will place at index 4.";
  cout << endl << endl;
  list.put(2, "Khalidiyah Mall");
  list.put(4, "Abu Dhabi Mall");
  list.print();

  cout << "Let's add the Galleria Mall in between Abu Dhabi Mall and NYUAD " << endl;
  cout << "at index; then, let's add Manarat Al Saadiyat in between Galleria and NYUAD";
  cout << endl << endl;
  list.put(5, "The Galleria Mall");
  list.put(6, "Manarat Al Saadiyat");
  list.print();

  return 0;
}
