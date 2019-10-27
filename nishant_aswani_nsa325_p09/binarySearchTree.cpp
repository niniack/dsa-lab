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

Node* BST::deleteNode(Node* top, int data){

  // Base case
  if (top == nullptr){
    cout << endl << "Sorry, this node is not available for deletion." << endl;
    return top;
  }

  // if data < top, then move to the left subtree
  // returns the proper node to be successor
  if (data < top->data){
    top->left = deleteNode(top->left, data);
  }

  // if data > top, then move to the right subtree
  // returns the proper node to be successor
  else if (data > top->data){
    top->right = deleteNode(top->right, data);
  }

  // finally if data == top, then we delete that
  else {

    // if left child is empty, return right
    if (top->left == nullptr && top != root){
      Node* temp = top->right;
      delete(top);
      --numberOfNodes;
      return temp;
    }

    // if right child is empty, return left
    else if (top->right == nullptr && top != root){
      Node* temp = top->left;
      delete(top);
      --numberOfNodes;
      return temp;
    }

    // if both children exist, then
    // find min value in right subtree as successor when possible

    // or it is root missing a child
    else{

      // check if final node
      if(top->right == nullptr && top->left == nullptr){
        delete(top);
        root = nullptr;
        return nullptr;
      }

      if (top == root){
        if (top->right == nullptr){
          top->data = top->left->data;
          top->left = deleteNode(top->left, top->left->data);
          return top;
        }

        else if (top->left == nullptr){
          top->data = top->right->data;
          top->right = deleteNode(top->right, top->right->data);
          return top;
        }
      }
      // find successor
      Node* temp = _minNode(top->right);
      // store value of successor in top
      top->data = temp->data;
      // "properly" delete the source of the successor

      // save val to top->right
      if (top->data == top->right->data){
        top->right = deleteNode(top->right, temp->data);
      }

      // don't save val to top->right
      else{
        deleteNode(top->right, temp->data);
      }

    }

  }

  return top;
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
