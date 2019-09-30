//  File: insertionSort.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 6
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 30 2019

#include "insertionSortDLL.hpp"
#include <iostream>

using namespace std;

DoubleLinkedList::DoubleLinkedList(): listSize(0) {};

DoubleLinkedList::DoubleLinkedList(DoubleLinkedList const &list): listSize(0), head(nullptr) {

  if (list.empty()){
    return;
  }

  headPush(list.getHead()->data);

  Node *walkOriginal = list.getHead()->next;

  int originalListSize = list.getListSize();

  for (int i=0; i < originalListSize-1; ++i){
    tailPush(walkOriginal->data);
    walkOriginal = walkOriginal->next;
  }

};

DoubleLinkedList::~DoubleLinkedList() {};    // destructor

void DoubleLinkedList::headPush(int data){
  // pointer used for new node
  Node *temp = new Node();

  // check for heap overflow
  if (!temp) {
    cout << "There is a Heap Overflow";
    exit(1);
  }

  // assign data to node
  temp->data = data;

  // if list is empty
  if (listSize == 0){
    firstPush(temp);
  }

  else{
    // point the next of new node to old head
    temp->next = head;
    // point the prev of new node to null
    temp->prev = nullptr;
    // point the prev of old head to new node
    head->prev = temp;
    // formalize the new node as head
    head = temp;
    // increment list size
    ++listSize;
  }

};

void DoubleLinkedList::tailPush(int data){

  // pointer used for new node
  Node *temp = new Node();

  // check for heap overflow
  if (!temp) {
    cout << "There is a Heap Overflow";
    exit(1);
  }

  // assign data to node
  temp->data = data;

  // if list is empty
  if (listSize == 0){
    firstPush(temp);
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

void DoubleLinkedList::firstPush(Node *temp){
  // point head and tail to new node
  tail = temp;
  head = temp;
  // new node points to null
  temp->next = nullptr;
  temp->prev = nullptr;
  // increment list size
  ++listSize;
}

void DoubleLinkedList::insertionSort(){
  int  insertVal;
  Node *walkForward = getHead()->next;
  Node *walkBackward = walkForward;

  while (walkForward->next != nullptr){
    insertVal = walkForward->data;

    while (walkBackward->prev != nullptr){
      if (walkBackward->prev->data <= insertVal){
        break;
      }
      walkBackward = walkBackward->prev;
    }

    moveNode(walkForward, walkBackward);
    walkForward = walkForward->next;
  }


}

void DoubleLinkedList::moveNode(Node *origin, Node *destination){

  Node *temp;

  temp = origin;

  if(origin == destination){
    return;
  }

  // fix links of original location
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;

  if (destination == head){
    temp->next = destination;
    destination->prev = temp;
    temp->prev = nullptr;
    head = temp;
  }

  else{
    // fix links at new location
    destination->prev->next = temp;
    temp->next = destination;
    temp->prev = destination->prev;
    destination->prev = temp;
  }

}

void DoubleLinkedList::finalPop(Node *temp){
  // point head and tail to null
  // node should already be pointing to null
  head = nullptr;
  tail = nullptr;
  // delete node
  delete(temp);
  // decrement list size
  --listSize;
}

bool DoubleLinkedList::empty() const{
  return (head == nullptr);
}

Node *DoubleLinkedList::getHead() const{
  return (head);
}

int DoubleLinkedList::getListSize() const{
  return listSize;
}

void DoubleLinkedList::printListSize() const{
  cout << "The que has " << listSize << " elements" << endl << endl;
}


void DoubleLinkedList::print() const{
  Node *walk;
  walk = head;

  cout << endl;
  printListSize();

  cout << "Contents of the doubly-linked list:" << endl;
  cout << "--------" << endl;

  while(walk!=nullptr){
    cout << walk->data << endl;
    cout << "--------" << endl;
    walk = walk->next;
  }

}
