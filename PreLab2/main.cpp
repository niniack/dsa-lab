//  File: main.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 2 2019

#include "stack.hpp"
#include <iostream>


#include "stack.cpp"


using namespace std;


int main(){
  cout << "This program demonstrates the stack data structure implemented with ";
  cout << "a singly linked list." << endl << endl;

  cout << "There are three functions: push, pop, and display." << endl;
  cout << "Push adds a value to the top of the stack, while pop removes the ";
  cout << "top node." << endl;
  cout << "Display simply prints out all the contents of the stack" << endl << endl;

  Queue stack;
  cout << "Here the stack is instantiated and it is seen that there are no values.";
  cout << endl;
  stack.getStackSize();
  cout << endl;

  cout << "Three values are pushed to the top of the stack." << endl;
  cout << "We can view them with the print function." << endl << endl;
  stack.push(5);
  stack.push(6);
  stack.push(10);
  stack.print();

  cout << "We then call the pop function twice to remove the top two values, ";
  cout << "then add a new value." << endl << endl;
  stack.pop();
  stack.pop();
  stack.push(55);
  stack.print();
}
