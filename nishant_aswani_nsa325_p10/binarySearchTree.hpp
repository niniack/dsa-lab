//  File: binarySearchTree.hpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 9
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Oct 28 2019

#include <list>

using namespace std;

class Node{
  public:
    int data;
    Node* left;
    Node* right;
};

class Diff{
  public:
    Node* parent;
    Node* left;
    Node* right;
    int diff;

    Diff(Node* initParent, Node* initLeft, Node* initRight, int initDiff);
};

class BST{
  private:
    Node* root;
    int numberOfNodes;
    void _firstInsertion(int data);
    void _findKey(Node* &walk, int data, Node* &parent);

  public:

    //list to store differences
    std::list<Diff> diffList;

    //const deconst
    BST();
    ~BST();

    //driver
    void insertNode(int data);
    void deleteNode(Node* top, int data);
    void checkBalance(Node*top);
    int findHeight(Node* top) const;

    //print functions
    void preOrder(Node* top);
    void postOrder(Node* top);
    void inOrder(Node* top);

    //utility
    int getNumNodes() const;
    Node* getRoot() const;
    Node* _getMinNode(Node* top);
    Node* _getMaxNode(Node* top);
};

Node* merge(BST t1, BST t2, int h1, int h2);
void preOrder(Node* top);
