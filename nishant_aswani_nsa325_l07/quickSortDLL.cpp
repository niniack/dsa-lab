//  File: quickSortDLL.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 6
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Oct 7 2019

#include "quickSortDLL.hpp"
#include <iostream>

using namespace std;

DoubleLinkedList::DoubleLinkedList(): listSize(0) {};

int DoubleLinkedList::position = 0;

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
  temp->data = data;

  temp->position = position;

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
  temp->data = data;

  temp->position = position;

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

void DoubleLinkedList::quickSort(Node *low, Node *high){

  Node *pa;

  if (low->position >= high->position) return;

  pa = partition(low, high);

  if (pa->next != NULL){
    quickSort(low, pa->prev);
    quickSort(pa->next, high);
  }
}

Node *DoubleLinkedList::partition(Node *low, Node *high){

  int pivot = high->data;

  Node *walkForward = low;
  Node *walkBackward = high->prev;

  while (walkForward->position <= walkBackward->position){

    while (walkForward->data < high->data){
      walkForward = walkForward->next;
    }

    while (walkBackward->data >= high->data){
      walkBackward = walkBackward->prev;
    }

    if (walkForward->position == walkBackward->position){
      swapNodeContent(walkBackward, high);
    }

    if (walkForward->data >= pivot && walkForward->position < walkBackward->position){
      swapNodeContent(walkForward, walkBackward);
    }

  }

  if (high->data >= walkBackward->data){
    swapNodeContent(walkForward, high);
  }

  return walkForward;
}

void DoubleLinkedList::swapNodeContent(Node *nodeA, Node *nodeB){

  int temp = nodeA->data;
  nodeA->data = nodeB->data;
  nodeB->data = temp;

  this->print();
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


Node *DoubleLinkedList::getTail() const{
  return (tail);
}

int DoubleLinkedList::getListSize() const{
  return listSize;
}

void DoubleLinkedList::printListSize() const{
  cout << "The DLL has " << listSize << " elements" << endl << endl;
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
    cout << endl;
    cout << "--------" << endl;
    walk = walk->next;
  }

  cout << "----------------------" << endl;

}
