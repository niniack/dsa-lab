//  File: josephus.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 5
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 23 2019

#include "josephus.hpp"
#include <iostream>

using namespace std;

DoubleLinkedList::DoubleLinkedList(): listSize(0) {}; // constructor initializes list with size zero

DoubleLinkedList::~DoubleLinkedList() {};    // destructor

int DoubleLinkedList::position = 0;

void DoubleLinkedList::linearPush(){

  // increment the static position value
  ++position;

  // pointer used for new node
  Node *temp = new Node();

  // check for heap overflow
  if (!temp) {
    cout << "There is a Heap Overflow";
    exit(1);
  }

  // assign data to node
  temp->data = position;

  // if list is empty
  if (listSize == 0){
    _firstPush(temp);
  }

  else{
    // point the next of new node to null
    temp->next = nullptr;
    // point the prev of new node to old tail
    temp->prev = tail;
    // point the old tail to the new node
    tail->next = temp;
    // formalize the new node as tail
    tail = temp;
    // increment list size
    ++listSize;
  }

};

void DoubleLinkedList::executeSoldier(int direction, int offset){
  //convert list to circular if not already done so
  if (!circularFlag){
    _makeCircular();
  }

  // make a walking pointer
  Node *walk;

  // set walker to current soldier
  walk = currentSoldier;

  // check if execution is possible
  if(listSize==0){
    cout << "All soldiers have been killed..." << endl;
    cout << "Death is inevitable to all." << endl << endl;

    cout << "You should exit the program..." << endl;
    return;
  }

  // check if it is the final execution
  else if(listSize==1){
    _finalExecution(walk);
  }

  // otherwise carry on as usual
  else{
    //clockwise = 1;  is in direction of next
    if (direction == 1){
      for(int i=0; i<offset; ++i){
        walk = walk->next;
      }
      _removeNode(walk);
    }

    //anti clockwise = 2; is in direction of previous
    else if (direction == 2){
      for(int j=0; j<offset; ++j){
        walk = walk->prev;
      }
      _removeNode(walk);
    }

    else {
      cout << "Not a valid direction. \n";
      return;
    }
  }
}

void DoubleLinkedList::_firstPush(Node *temp){
  // point head and tail to new node
  tail = temp;
  head = temp;
  // new node points to null
  temp->next = nullptr;
  temp->prev = nullptr;
  // increment list size
  ++listSize;
}

void DoubleLinkedList::_removeNode(Node *walk){
  // make temp variable to store node to be deleted
  Node *temp;
  // set temp to node to be deleted
  temp = walk;

  // pre-emptively set the currentSoldier to the "next" in listSize
  currentSoldier = walk->next;
  cout << "The current soldier is: "<< currentSoldier->data << endl;

  if (head == walk){
    head = walk->next;
  }

  if (tail == walk){
    tail = tail->next;
  }

  // update linkages of other nodes
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  // remove linkages of node to be deleted
  temp->next = nullptr;
  temp->prev = nullptr;
  // deallocate node
  delete(temp);
  // decrease list size
  --listSize;

  // print the list of soldiers
  printLinear();

}

void DoubleLinkedList::_makeCircular(){
  // obtain the tail value and point its next to head
  tail->next = head;
  // obtain the head value and point its previous to tail
  head->prev = tail;
  // set the position of the currentSoldier to head
  currentSoldier = head;
  // set the circular flag to true
  circularFlag = true;
}

void DoubleLinkedList::_finalExecution(Node *walk){
  // remove all linkages safely
  head = nullptr;
  tail = nullptr;
  walk->next = nullptr;
  walk->prev = nullptr;
  // deallocate the pointer
  delete(walk);
  // decrement size
  --listSize;
  printLinear();

}

void DoubleLinkedList::getListSize() const{
  cout << "The list has " << listSize << " soldiers" << endl << endl;
}

void DoubleLinkedList::printLinear() const{
  Node *walk;
  walk = head;

  cout << endl;
  getListSize();

  cout << "Contents of the double-ended queue: " << endl;
  cout << "--------" << endl;

  for(int i=0; i<listSize; ++i){
    cout << walk->data << endl;
    cout << "--------" << endl;
    walk = walk->next;
  }

}
