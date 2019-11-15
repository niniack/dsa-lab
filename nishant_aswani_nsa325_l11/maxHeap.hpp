//  File: maxHeap.hpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 11
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Nov 11 2019

#include <queue>

class Node{
  public:
    Node* left;
    Node* right;
    Node* parent;
    int data;
    Node (int initData);
};


class maxHeap{
  private:
    Node* root;
    int size;
    void swap(Node* a, Node* b);

  public:
    maxHeap();
    ~maxHeap();

    //driver methods
    void buildHeap(int values[], int size);
    void insertKey(int data);
    void heapify(Node* insert);

    //utility methods
    Node* breadthFirst(Node* top) const;
    bool isEmpty() const;
    void preOrderPrint(Node *top) const;
    Node* getRoot() const;

};
