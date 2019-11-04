//  File: main.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 9
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Oct 28 2019


#include "naryTree.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main(){
  BST t1;

  // implemenetation: void insertNode(int data, int parentData, int parentLevel);
  // level 1 is where the root node resides

  t1.insertNode(2, 0, 0);
  t1.insertNode(7, 2, 1);
  t1.insertNode(5, 2, 1);
  t1.insertNode(8, 7, 2);
  t1.insertNode(10,7, 2);
  t1.insertNode(6, 7, 2);
  // t1.insertNode(9, 5, 2);



  cout << "TEST: "<< t1.getRoot()->data << endl;
  cout << "TESTONE: " << t1.getRoot()->child->data<< endl;
  cout << "TESTTWO: " << t1.getRoot()->child->sibling->data<< endl;
  cout << "TESTTHREE: " << t1.getRoot()->child->child->sibling->data<< endl;
  // cout << "TESTTHREE: " << t1.getRoot()->child->child->sibling->sibling->data<< endl;


  // cout << "testTwo " << t1.getRoot()->child->sibling->child->child->data << endl;
}
