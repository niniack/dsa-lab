//  File: quickSortDLL.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 6
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Oct 7 2019

#include "quickSortDLL.hpp"
#include <iostream>

using namespace std;

Data::Data(double initSpeed, int initICA, int initICB): speed(initSpeed), ica(initICA), icb(initICB) {};

Data::Data() {};
Data::~Data() {};

int Data::getAverage(){
  int avg;
  avg = (ica+icb)/2;
  return avg;
}

////////////////////////////////////////////////////////////////////////////////

DoubleLinkedList::DoubleLinkedList(): listSize(0) {};

int DoubleLinkedList::position = 0;

DoubleLinkedList::DoubleLinkedList(DoubleLinkedList const &list): listSize(0), head(nullptr) {

  if (list.empty()){
    return;
  }

  headPush(list.getHead()->stats);

  Node *walkOriginal = list.getHead()->next;

  int originalListSize = list.getListSize();

  for (int i=0; i < originalListSize-1; ++i){
    tailPush(walkOriginal->stats);
    walkOriginal = walkOriginal->next;
  }

};

DoubleLinkedList::~DoubleLinkedList() {};    // destructor

void DoubleLinkedList::headPush(Data stats){

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
  temp->stats = stats;

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

void DoubleLinkedList::tailPush(Data stats){

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
  temp->stats = stats;

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

  cout << "lowPos" << low->position << endl;
  cout << "pa" << pa->position << endl;
  cout << "highPos" << high->position << endl;
  cout << endl;


  if (pa->next != NULL){
    quickSort(low, pa->prev);
    quickSort(pa->next, high);
  }

  else {
    quickSort(low, pa->prev);
    // quickSort(pa->next, high);
  }

}

Node *DoubleLinkedList::partition(Node *low, Node *high){

  int pivot = high->stats.getAverage();

  Node *walkForward = low;
  Node *walkBackward = high->prev;

  while (walkForward->position <= walkBackward->position){

    while (walkForward->stats.getAverage() < pivot && walkForward->position < walkBackward->position){
      walkForward = walkForward->next;
    }

    while (walkBackward->stats.getAverage() >= pivot && walkForward->position < walkBackward->position){
      walkBackward = walkBackward->prev;
    }

    if (walkForward->position == walkBackward->position){
      swapNodeContent(walkBackward, high);
      break;
    }

    if (walkForward->stats.getAverage() >= pivot && walkForward->position < walkBackward->position){
      swapNodeContent(walkForward, walkBackward);
    }

  }

  if (high->stats.getAverage() >= walkBackward->stats.getAverage()){
    swapNodeContent(walkForward, high);
  }

  return walkForward;
}

void DoubleLinkedList::swapNodeContent(Node *nodeA, Node *nodeB){

  Data temp = nodeA->stats;
  nodeA->stats = nodeB->stats;
  nodeB->stats = temp;
  cout << "Swapping Node " << nodeA->stats.getAverage() << " with " << nodeB->stats.getAverage();
  cout << endl;
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
    cout << walk->stats.getAverage() << endl;
    cout << endl;
    cout << "--------" << endl;
    walk = walk->next;
  }

  cout << "----------------------" << endl;

}
