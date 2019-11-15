//  File: maxHeap.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 11
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Nov 11 2019


#include "maxHeap.hpp"
#include <iostream>

using namespace std;

Node::Node(int initData): left(nullptr), right(nullptr), data(initData) {};

maxHeap::maxHeap(): root(nullptr), size(0){}

maxHeap::~maxHeap(){}

void maxHeap::buildHeap(int values[], int size){
    for (int i=0; i<size; ++i){
      insertKey(values[i]);
    }
}

void maxHeap::swap(Node* a, Node* b){
  int temp = a->data;
  a->data = b->data;
  b->data = temp;
}

Node* maxHeap::breadthFirst(Node* top) const{
  Node* walk = top;

  if (walk == nullptr){
    return nullptr;
  }

  queue <Node*> q;

  // add root to queue
  q.push(top);

  // while queue has values
  while( !q.empty() ){

    // obtain the front
    walk = q.front();

    // if it has a free child, we will add it there
    if (walk->left == nullptr || walk->right == nullptr){
      return walk;
    }

    // otherwise remove from queue
    q.pop();

    // add its children to queue
    if(walk->left != nullptr){
      q.push(walk->left);
    }

    if(walk->right != nullptr){
      q.push(walk->right);
    }
  }

  return walk;

}

void maxHeap::heapify(Node* insert){

  Node* walk = insert;
  while (walk != nullptr && walk != root){

    if(walk->data > walk->parent->data){
      swap(walk, walk->parent);
    }

    walk = walk->parent;
  }
}


void maxHeap::insertKey(int data){

  Node* insert = new Node(data);

  //  first insert
  if (root==nullptr){
    root = insert;
    ++size;
  }

  else{
    // returns a node with at least one missing child
    Node* last = breadthFirst(root);

    // attempt insert at left first
    if (last->left == nullptr){
      last->left = insert;
      insert->parent = last;
    }

    //  otherwise right
    else if (last->right == nullptr){
      last->right = insert;
      insert->parent = last;
    }

    // fix heap
    heapify(insert);

  }

}

void maxHeap::preOrderPrint(Node* top) const{

  if (top == nullptr){
    return;
  }

  Node* walk = top;
  cout << walk->data << ", ";
  preOrderPrint(walk->left);
  preOrderPrint(walk->right);
}

bool maxHeap::isEmpty() const{
  return (root == nullptr);
}

Node* maxHeap::getRoot() const{
  return root;
}
