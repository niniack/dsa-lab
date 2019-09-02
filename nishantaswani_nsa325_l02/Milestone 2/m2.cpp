//  File: m2.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 2 2019

#include "m2.h"
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

  // logic for deciding node below and tail

  // if there exist nodes set the new node to the old head
  if (stackSize!=0) {
    temp->below = head;
  }

  // if there are no nodes set the first node to null and point tail to it
  else {
    temp->below = nullptr;
    tail = temp;
  }

  // assign the head as the new node
  head = temp;
  ++stackSize;
}

// utility function to remove a node from the top of the stack
void Stack :: pop(){
  // allocate memory for temp var
  class Node *walk = head;
  class Node *cleanup;

  if (head == NULL) {
    cout << "There are no more books to remove!";
  }
  else{
    //print out relevant information
    getISBN();
    getTailValue();
    // In a singly linked list we cannot easily remove the tail
    // so we must traverse the entire linked list to find the node
    // right before the final node

    //this while loop takes us to the second last node

    if( walk != NULL){
      while (walk->below->below != NULL){
        walk = walk->below;
      }
    }

    // set the second last node to point to null
    walk->below = NULL;
    // move tail data to a cleanup variable
    cleanup = tail;
    // set tail to the second last node to make a new tail
    tail = walk;
    // delete the cleanup node;
    delete(cleanup);
    // decrement stack size
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
  cout << "The serial number of the first book is: " << head->data << endl;
}

void Stack :: getTailValue() const{
  cout << "The serial number of the last book is: " << tail->data << endl;
}
