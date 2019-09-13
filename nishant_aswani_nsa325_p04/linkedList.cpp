//  File: linkedList.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 16 2019

#include "linkedList.hpp"
#include <iostream>

using namespace std;

List::List(): listSize(0) {};

List :: ~List() {};

void List :: put(int loc, int data){
  Node *walk = new Node();
  Node *temp = new Node();

  if (!temp) {
    cout << "There is a Heap Overflow";
    exit(1);
    }

  temp->data = data;

  if (loc > listSize){
    getListSize();
    cout << "Sorry, there are not enough nodes to acccess index ";
    cout << loc;
    cout << endl;
    return;
  }

  if (listSize>=1){
    walk = head;

    if (loc==0){
      temp->next = head;
      head = temp;
      ++listSize;
    }

    else if (walk->next != nullptr){
      for(int i=0; i<loc-1; ++i){
        walk = walk->next;
      }
      if (walk->next == nullptr) temp->next = nullptr;
      else temp->next = walk->next;
      walk->next = temp;
      ++listSize;
    }

    else {
      temp->next = nullptr;
      head->next = temp;
      ++listSize;
    }
  }

  else{
    head = temp;
    head->next = nullptr;
    ++listSize;
  }

  return;
};

void List :: getListSize() const{
  cout << "The list size is: ";
  cout << listSize << endl;
}

void List :: print() const{
  Node *walk = new Node();
  walk = head;

  getListSize();
  cout << "----------" << endl;

  for (int i=0; i<listSize; ++i){
    cout << walk->data << endl;
    cout << "----------" << endl;
    walk = walk->next;
  }
  cout << endl;

  return;
};
