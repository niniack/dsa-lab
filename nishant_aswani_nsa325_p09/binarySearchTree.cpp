//  File: binarySearchTree.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 9
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Oct 28 2019


#include "binarySearchTree.hpp"
#include <iostream>

using namespace std;

BST::BST(): root(nullptr), numberOfNodes(0) {};
BST::~BST() {};

void BST::inOrder(Node* top){
  if (top == nullptr){
    return;
  }

  Node* walk = top;
  preOrder(walk->left);
  cout << walk->data << ", ";
  preOrder(walk->right);
}

void BST::preOrder(Node* top){

  if (root == nullptr){
    cout << "Tree is empty" << endl;
  }

  if (top == nullptr){
    return;
  }

  Node* walk = top;
  cout << walk->data << ", ";
  preOrder(walk->left);
  preOrder(walk->right);
}

void BST::postOrder(Node* top){
  if (top == nullptr){
    return;
  }

  Node* walk = root;
  postOrder(walk->left);
  postOrder(walk->right);
  cout << walk->data << ", ";
}

Node* BST::_minNode(Node* top){
  Node* walk = top;

  while (walk && walk->left !=  nullptr){
    walk = walk->left;
  }

  return walk;

}

void BST::_findKey(Node* &walk, int data, Node* &parent){
  while (walk != nullptr && walk->data != data){

    parent = walk;

    // if given key is less than the current node, go to left subtree
		// else go to right subtree
		if (data < walk->data){
      walk = walk->left;
    }
		else{
      walk = walk->right;
    }
  }
}

void BST::deleteNode(Node* top, int data){

  // parent of to be deleted
  Node* parent = nullptr;
  // node to be deleted
  Node* walk = top;

  // updated parent and walker to correct position
  // based on key
  _findKey(walk, data, parent);

  // if node to be deleted is null, then return null
  if (walk == nullptr){
    cout << endl;
    cout << "Sorry, value " << data << " was not found in the tree!" << endl;
    cout << endl;
    return;
  }

  // Case 1: leaf node
  if (walk->left == nullptr && walk->right == nullptr){

    // if not root node
    if (walk != root){
      // sever the link
      if (parent->left == walk){
        parent->left = nullptr;
      }

      else {
        parent->right = nullptr;
      }
    }

    // if it is root, set root to null
    else{
      root = nullptr;
    }

    // delete the leaf
    delete(walk);
  }

  // Case 2: has two children
  else if (walk->left && walk->right){

    // find the successor in right subtree
    Node* successor = _minNode(walk->right);
    // temp store value of succesor in node
    int val = successor->data;
    // delete the node where successor value was taken
    deleteNode(top, val);
    // store value to node
    walk->data = val;
  }

  // Case 3: has one child
  else {
    // check which side is not null
    Node* child = (walk->left)? walk->left : walk->right;

    // if to be deleted is not root
    if (walk != root){
      if (walk == parent->left){
        parent->left = child;
      }
      else{
        parent->right = child;
      }
    }

    else{
      root = child;
    }

    delete(walk);
  }

  cout << "Pre-order: ";
  preOrder(getRoot());
  cout << endl;
}

void BST::_firstInsertion(int data){
  Node* temp = new Node();
  temp->data = data;
  temp->left = nullptr;
  temp->right = nullptr;
  root = temp;
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

        if (walk->right != nullptr) {
          walk = walk->right;
        }

        else {
          walk->right = temp;
          flag = true;
        }

      }

      else if (data <= walk->data) {

        if(walk->left != nullptr) {
          walk = walk->left;
        }

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
