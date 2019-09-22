//  File: abstractDeque.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Prelab 5
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 23 2019

#include "abstractDeque.hpp"
#include <iostream>

using namespace std;

Deque::Deque(): listSize(0) {}; // constructor initializes list with size zero

Deque::~Deque() {};    // destructor

void Deque::headPush(int data){
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

void Deque::tailPush(int data){

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

void Deque::firstPush(Node *temp){
  // point head and tail to new node
  tail = temp;
  head = temp;
  // new node points to null
  temp->next = nullptr;
  temp->prev = nullptr;
  // increment list size
  ++listSize;
}

void Deque::headPop(){
  // pointer to handle node to be deleted
  Node *temp;
  temp = head;
  // if there are no nodes, do nothing
  if(listSize==0){
    cout << "Sorry, there are no elements to deque" << endl;
    return;
  }

  else if(listSize==1){
    finalPop(temp);
  }

  else{
    // access head to be deleted
    temp = head;
    // set head to next node
    head = temp->next;
    // remove linkage of node to be deleted
    temp->next = nullptr;
    // set prev of new head to null
    head->prev = nullptr;
    // delete old head
    delete(temp);
    // decrement list size
    --listSize;
  }
}

void Deque::tailPop(){
  // pointer to handle node to be deleted
  Node *temp;
  temp = tail;
  // if there are no nodes, do nothing
  if(listSize==0){
    cout << "Sorry, there are no elements to deque" << endl;
    return;
  }

  else if(listSize==1){
    finalPop(temp);
  }

  else{
    // access tail to be deleted
    temp = tail;
    // set tail to prev node
    tail = temp->prev;
    // remove linkage of node to be deleted
    temp->prev = nullptr;
    // set next of new tail to null
    tail->next = nullptr;
    // delete old tail
    delete(temp);
    // decrement list size
    --listSize;
  }
}

void Deque::finalPop(Node *temp){
  // point head and tail to null
  // node should already be pointing to null
  head = nullptr;
  tail = nullptr;
  // delete node
  delete(temp);
  // decrement list size
  --listSize;
}

void Deque::getListSize() const{
  cout << "The que has " << listSize << " elements" << endl << endl;
}


void Deque::print() const{
  Node *walk;
  walk = head;

  cout << endl;
  getListSize();

  cout << "Contents of the double-ended queue: " << endl;
  cout << "--------" << endl;

  while(walk!=nullptr){
    cout << walk->data << endl;
    cout << "--------" << endl;
    walk = walk->next;
  }

}
