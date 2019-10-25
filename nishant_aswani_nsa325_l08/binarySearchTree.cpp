//  File: binarySearchTree.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 8
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Oct 23 2019


#include "binarySearchTree.hpp"
#include <iostream>

using namespace std;

BST::BST(): root(nullptr), numberOfNodes(0) {};
BST::~BST() {};

void BST::_firstInsertion(int data){
  Node* temp = new Node();
  temp->data = data;
  temp->left = nullptr;
  temp->right = nullptr;
  root = temp;
}

// bool BST::_rootIsNull(){
//   bool flag = (root == nullptr) ? true : false;
//   return flag;
// }

void BST::inOrder(Node* root){
  if (root == nullptr){
    return;
  }

  Node* walk = root;
  preOrder(walk->left);
  cout << walk->data << ", ";
  preOrder(walk->right);
}

void BST::preOrder(Node* root){

  if (root == nullptr){
    return;
  }

  Node* walk = root;
  cout << walk->data << ", ";
  preOrder(walk->left);
  preOrder(walk->right);
}

void BST::postOrder(Node* root){
  if (root == nullptr){
    return;
  }

  Node* walk = root;
  postOrder(walk->left);
  postOrder(walk->right);
  cout << walk->data << ", ";
}

void BST::insertNode(int data){

  ++numberOfNodes;

  if (root == nullptr){
    _firstInsertion(data);
  }

  else{
    Node* walk = root;
    Node* temp = new Node();
    bool flag = false;

    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;

    // traverse until both of the children are null
    while(walk != nullptr){

      if (flag){
        return;
      }

      if (data > walk->data){

        if (walk->right != nullptr) walk = walk->right;

        else {
          walk->right = temp;
          flag = true;
        }

      }

      else if (data <= walk->data) {

        if(walk->left != nullptr) walk = walk->left;
        else {
          walk->left = temp;
          flag = true;
        }
      }

    }
  }
}


int BST::getNumNodes() const{
  return numberOfNodes;
}

Node* BST::getRoot() const{
  return root;
}
