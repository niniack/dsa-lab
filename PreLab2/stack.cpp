//  File: stack.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 2 2019

#include "stack.hpp"

using namespace std;

//  constructor function initializes stack with a size 0
Queue :: Queue(): stackSize(0) {};
Queue :: ~Queue() {};

//  utility function to add a node to the top of the stack
void Queue :: push(int data) {

  // allocate memory for a new node
  struct Node *temp = new Node();

  // check for stack overflow
  if (!temp) {
    cout << "There is a Heap Overflow";
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
void Queue :: pop(){
  // allocate memory for temp var
  struct Node *temp;

  if (head == NULL) {
    cout << "Bottom of the stack, nothing to remove";
    exit(1);
  }

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

// utility function to display the contents of the stack from top to bottom
void Queue :: print() const{

  //  display address of the head
  cout << "Head Address: " << head << endl;

  //  pointer to traverse down the linked list
  struct Node *walk;
  walk = head;
  cout << "Contents of the stack: " << endl;
  cout << "--------" << endl;
  while(walk!=NULL){
    cout << walk->data << endl;
    cout << "--------" << endl;
    walk = walk->below;
  }

  getHeadValue();
  getStackSize();
  cout << endl;

}

// utility function to display the stack size
void Queue :: getStackSize() const{
  cout << "The stack size is: " << stackSize << endl;
}

// utility function to display the value at the top of the stack
void Queue :: getHeadValue() const{
  cout << "The head value is: " << head->data << endl;
}
