//  File: m2_metro.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 4
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 16 2019

#include "m2_metro.hpp"
#include <iostream>

using namespace std;

List::List(): listSize(0) {}; // constructor initializes list with size zero

List :: ~List() {};           // destructor

// functionality to add node to list
void List :: put(int loc, string data){
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

// method to remove node from list
void List :: remove(string stationName){
  Node *walk = new Node();    // pointer to walk along the list
  Node *temp = new Node();    // pointer for deletion of node

  walk = head; // set traversal pointer to head

  // edge case where there are no nodes
  if (listSize == 0 || head == nullptr){
    cout << "Sorry, you cannot remove from an empty list." << endl;
    return;
  }

  // edge case where there is one node
  else if (listSize == 1){

    // error if the single node is not what we want to delete
    if (walk->data != stationName){
      cout << "Sorry, this element does not exist." << endl;
      return;
    }

    // if it matches, delete the node
    else {
      // set head to null
      head = nullptr;
      // free up the memory
      delete(walk);
      // decrement list size
      --listSize;
    }
  }

  // if there exists at least one node
  else {

    // walk along the list as long as the next value is not the needed value
    while (walk->next->data != stationName){
      walk = walk->next;
      if (walk->next == nullptr){
        cout << "Sorry, this element does not exist." << endl;
        return;
      }
    }

    // set temp to the node needing to be deleted, which is next
    temp = walk->next;

    // point the current node to the node after the one being deleted
    walk->next = temp->next;

    // remove the link for the node to be deleted
    temp->next = nullptr;

    // free up memory using delete keyword
    delete(temp);

    // and decrement counter
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
