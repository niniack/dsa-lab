//  File: main.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 8
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Oct 23 2019


#include "binarySearchTree.hpp"
#include <iostream>

using namespace std;

int main(){

  int values[5] {5,7,3,8,2};
  int size = 5;
  BST tree;

  for (int i=0; i<size; ++i){
    tree.insertNode(values[i]);
  }
  cout << endl;

  cout << "Pre-Order: ";
  tree.preOrder(tree.getRoot());
  cout << endl;

  cout << "Post-Order: ";
  tree.postOrder(tree.getRoot());
  cout << endl;

  cout << "In Order: ";
  tree.inOrder(tree.getRoot());
  cout << endl;

  // cout << tree.getRoot()->left->left->data<< endl;

}
