//  File: naryTree.hpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 9
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Nov 4 2019

using namespace std;

class Node{
  public:
    int data;
    Node* child;
    Node* sibling;
    Node(int data);
};

class BST{
  private:
    Node* root;
    void _setRoot(int data);
  public:


    //const deconst
    BST();
    ~BST();

    //driver
    void insertNode(int data, int parent, int level);

    //utility
    Node* getRoot() const;

    //print
    void preOrder() const;
};
