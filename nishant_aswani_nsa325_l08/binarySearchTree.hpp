//  File: binarySearchTree.hpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 8
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Oct 23 2019

class Node{
  public:
    int data;
    Node* left;
    Node* right;
};

class BST{
  private:
    Node *root;
    int numberOfNodes;
    void _firstInsertion(int data);

  public:
    //const deconst
    BST();
    ~BST();

    //driver
    void insertNode(int data);

    //print functions
    void preOrder(Node* root);
    void postOrder(Node* root);
    void inOrder(Node* root);

    //utility
    int getNumNodes() const;
    Node* getRoot() const;
};
