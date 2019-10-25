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

Node* BST::_minRightNode(Node* root){
  Node* walk = root;

  while (walk->left !=  nullptr){
    walk = walk->left;
  }

  return walk;

}

Node* BST::deleteNode(Node* root, int data){

  // Base case
  if (root == nullptr){
    return root;
  }

  Node* temp = nullptr;

  // if data < root, then move to the left subtree
  // returns the proper node to be successor
  if (data < root->data){
    root->left = deleteNode(root->left, data);
  }

  // if data > root, then move to the right subtree
  // returns the proper node to be successor
  else if (data > root->data){
    root->right = deleteNode(root->right, data);
  }

  // finally if data == root, then we delete that
  else {

    // if left child is empty, return right
    if (root->left == nullptr){
      temp = root->right;
      delete(root);
      --numberOfNodes;
      return temp;
    }

    // if right child is empty, return left
    else if (root->right == nullptr){
      temp = root->left;
      delete(root);
      --numberOfNodes;
      return temp;
    }

    // if both children exist, then
    // find min value in right subtree as successor
    else{
      // find successor
      temp = _minRightNode(root->right);
      
      // store value of successor in root
      root->data = temp->data;

      // "properly" delete the source of the successor
      root->right = deleteNode(root->right, temp->data);
    }

  }

  return root;
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
