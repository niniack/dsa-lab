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
  // vector<int> values {15, 10, 20, 18, 25, 16, 19, 30};
  vector<int> values {10, 5, 15, 4, 8, 3, 7, 6, 20, 30};
  // vector<int> values{1,2,3,4,5,6,7,8};

  BST tree;

  for (unsigned int i=0; i<values.size(); ++i){
    tree.insertNode(values[i]);
  }

  cout << endl;
  int height = tree.findHeight(tree.getRoot());
  cout << "Height of the Tree is: " << height << endl;
  cout << "Pre-order: ";
  tree.preOrder(tree.getRoot());
  cout << endl <<endl;

  tree.checkBalance(tree.getRoot());

  // int diffListSize = tree.diffList.size();

  for (auto i : tree.diffList){
    cout << "diff: " << i.diff << ", ";
    cout << "parent: " << i.parent->data<< ", ";

    auto left = (i.left)? i.left->data:0;
    cout << "left: " << left<< ", ";

    auto right = (i.right)? i.right->data:0;
    cout << "right: " << right<< ", ";

    cout << endl;
  }
}
