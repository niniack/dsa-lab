//  File: naryTree.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 9
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Nov 4 2019


#include "naryTree.hpp"
#include <iostream>

using namespace std;

Node::Node(int initData): data(initData), child(nullptr), sibling(nullptr) {};

BST::BST(): root(nullptr){};
BST::~BST() {};

void BST::_setRoot(int data){
  Node *temp = new Node(data);
  root = temp;
}

void BST::insertNode(int data, int parentData, int parentLevel){

  // first priority is to always set a root node
  if (root == nullptr){
    cout << "Ignoring placement requests, as there is no root. Setting as root." << endl;
    _setRoot(data);
    return;
  }

  Node* walk = root;
  Node* newChild = new Node(data);


  // walk to the desired level where parent resides
  int i = 0;
  while(walk->child != nullptr && i < parentLevel-1){
    ++i;
    walk = walk->child;
  }

  // cout << walk->data << endl;


  // find the parent on that level
  bool foundParent = false;
  while(walk->sibling != nullptr && !foundParent){
    if (walk->data == parentData){
      foundParent = true;
    }
    else{
      walk = walk->sibling;
    }
  }



  // if child exists, set pointer to child
  if (walk->child != nullptr){

    walk = walk->child;

    while(walk->sibling != nullptr){
      walk = walk->sibling;
    }

    walk->sibling = newChild;
  }

  // otherwise assign it as child
  else{
    walk->child = newChild;
  }


}

// void preOrder() const{
//
// }


Node* BST::getRoot() const{
  return root;
}
