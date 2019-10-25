//  File: main.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 9
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Oct 28 2019


#include "binarySearchTree.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> values {15, 10, 20, 8, 12, 18, 25, 16, 19, 30};
  BST tree;

  for (unsigned int i=0; i<values.size(); ++i){
    tree.insertNode(values[i]);
  }
  cout << endl;

  tree.preOrder(tree.getRoot());
  cout << endl;

  vector<int> removalValues {8, 20, 10, 15};

  for (unsigned int i=0; i<removalValues.size(); ++i){
    tree.deleteNode(tree.getRoot(), removalValues[i]);
    tree.preOrder(tree.getRoot());
    cout << endl;
  }

}
