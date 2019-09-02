//  File: m1.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 2 2019

#include "m1.h"
#include <iostream>

using namespace std;

//  constructor function initializes stack with a size 0
Stack :: Stack(): stackSize(0) {};
Stack :: ~Stack() {};

//  utility function to add a node to the top of the stack
void Stack :: push(int data) {

  // allocate memory for a new node
  class Node *temp = new Node();

  // check for stack overflow
  if (!temp) {
    cout << "There is not enough space to add another book!";
    exit(1);
    }

  // place data into new node
  temp->data = data;

  // logic for deciding node below
  if (stackSize!=0) temp->below = head;
  else temp->below = nullptr;

  // assign the head as the new node
  head = temp;
  ++stackSize;
}

// utility function to remove a node from the top of the stack
void Stack :: pop(){
  // allocate memory for temp var
  class Node *temp;

  if (head == NULL) {
    cout << "There are no more books to remove!";
  }
  else{
    //print out relevant information
    getISBN();
    getHeadValue();
    // move the head to the temp variable
    temp = head;
    // set the new head to the value below the old head
    head = head->below;
    // remove the link of the old head to the new head
    temp->below = NULL;
    // free the old head from memory
    delete(temp);
    --stackSize;
  }
}

// utility function to display the contents of the stack from top to bottom
void Stack :: print() const{

  //  pointer to traverse down the linked list
  class Node *walk;
  walk = head;
  getISBN();
  cout << "--------" << endl;
  while(walk!=NULL){
    cout << walk->data << endl;
    cout << "--------" << endl;
    walk = walk->below;
  }
  getStackSize();
  cout << endl;

}

// utility function to display the stack size
void Stack :: getStackSize() const{
  cout << "Number of books: " << stackSize << endl;
}

void Stack :: getISBN() const{
  cout << "The ISBN is: " << isbn << endl;
}

// utility function to display the value at the top of the stack
void Stack :: getHeadValue() const{
  cout << "The serial number of the book is: " << head->data << endl;
}
