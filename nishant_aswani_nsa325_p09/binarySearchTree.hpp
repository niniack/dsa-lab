//  File: binarySearchTree.hpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 9
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Oct 28 2019

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
    Node* _minRightNode(Node* root);

  public:
    //const deconst
    BST();
    ~BST();

    //driver
    void insertNode(int data);
    Node* deleteNode(Node* root, int data);

    //print functions
    void preOrder(Node* root);
    void postOrder(Node* root);
    void inOrder(Node* root);

    //utility
    int getNumNodes() const;
    Node* getRoot() const;
};
