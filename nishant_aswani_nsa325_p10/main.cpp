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
  vector<int> valuesT1 {1,2,3,4,5};
  vector<int> valuesT2 {9,7,15};

  BST t1;
  BST t2;

  for (unsigned int i=0; i<valuesT1.size(); ++i){
    t1.insertNode(valuesT1[i]);
  }

  for (unsigned int i=0; i<valuesT2.size(); ++i){
    t2.insertNode(valuesT2[i]);
  }

  int h1 = t1.findHeight(t1.getRoot());
  int h2 = t2.findHeight(t2.getRoot());


  Node* mergedRoot = merge(t1, t2, h1, h2);
  preOrder(mergedRoot);
  cout << endl;

  t1.preOrder(t1.getRoot());
  cout << endl;
  t2.preOrder(t2.getRoot());
  cout << endl;


















  // cout << endl;
  // cout << "Pre-order: ";
  // t1.preOrder(t1.getRoot());
  // cout << endl;
  //
  // cout << endl;
  // cout << "Pre-order: ";
  // t2.preOrder(t2.getRoot());
  // cout << endl;
  //
  // vector<int> removalValues {1, 8, 30, 20, 16, 12, 18, 25, 15, 19, 10};
  //
  // for (unsigned int i=0; i<removalValues.size(); ++i){
  //   tree.deleteNode(tree.getRoot(), removalValues[i]);
  // }

}
