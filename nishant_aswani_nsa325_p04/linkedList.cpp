//  File: linkedList.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Prelab 4
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 16 2019

#include "linkedList.hpp"
#include <iostream>

using namespace std;

List::List(): listSize(0) {}; // constructor initializes list with size zero

List :: ~List() {};           // destructor

void List :: put(int loc, int data){
  Node *walk = new Node();    // pointer to walk along the list
  Node *temp = new Node();    // pointer to make new node

  // heap overflow if mem allocation is not allowed
  if (!temp || !walk) {
    cout << "There is a Heap Overflow";
    exit(1);
    }

  // assign data to new node
  temp->data = data;

  // if index is greater than list size, then it cannot be inserted
  if (loc > listSize){
    getListSize();
    cout << "Sorry, there are not enough nodes to access index ";
    cout << loc;
    cout << endl << endl;
    return;
  }

  // check for whether it is the first node being inserted
  // the else takes care of first node case
  if (listSize>=1){
    walk = head;

    // if the index is zero, make it the head
    if (loc==0){
      temp->next = head;
      head = temp;
      ++listSize;
    }

    // if there is more than one node, walk along the list
    else if (walk->next != nullptr){
      // traverse the linked list
      for(int i=0; i<loc-1; ++i){
        walk = walk->next;
      }

      // assume A->C, adding B

      // link B->C
      temp->next = walk->next;

      // link A->B
      // result is A->B->C
      walk->next = temp;
      ++listSize;
    }

    // if there is just one node and node is inserted after
    // point new node to null and point head to new node
    else {
      temp->next = nullptr;
      head->next = temp;
      ++listSize;
    }
  }

  // since it is the first node,it becomes the head
  // and also points to null
  else{
    head = temp;
    head->next = nullptr;
    ++listSize;
  }

  return;
};

// utility function to remove a node from the top of the stack
void List :: pop(){
  // allocate memory for temp var
  struct Node *temp;

  if (head == NULL) {
    cout << "Bottom of the stack, nothing to remove";
  }
  else{
    // move the head to the temp variable
    temp = head;

    // set the new head to the value below the old head
    head = head->next;

    // remove the link of the old head to the new head
    temp->next = NULL;

    // free the old head from memory
    delete(temp);
    --listSize;
  }
}

// helper method for obtaining list size
void List :: getListSize() const{
  cout << "The list size is: ";
  cout << listSize << endl;
}

// helper method for printing
void List :: print() const{
  // pointer for traversal
  Node *walk = new Node();
  // point pointer to head
  walk = head;

  // display list size
  getListSize();
  cout << "----------" << endl;

  // traverse list and print data at each node
  for (int i=0; i<listSize; ++i){
    cout << walk->data << endl;
    cout << "----------" << endl;
    walk = walk->next;
  }
  cout << endl;

  return;
};
