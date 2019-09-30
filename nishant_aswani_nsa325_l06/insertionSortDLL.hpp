//  File: insertionSort.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 6
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 30 2019

class Node{
  public:
    int data;
    Node *next;
    Node *prev;
    bool operator <= (Node const *nodeB) {
      return this->data <= nodeB->data;
    }
};

class DoubleLinkedList{
  private:
    // pointers and data
    int listSize;
    Node *head;
    Node *tail;

    // aux functions for internal use
    void firstPush(Node *temp);
    void finalPop(Node *temp);
    bool empty() const;
    Node *getHead() const;

  public:
    // constructors and destructors
    DoubleLinkedList();
    DoubleLinkedList(DoubleLinkedList const &list);
    ~DoubleLinkedList();

    // primary methods
    void headPush(int data);
    void tailPush(int data);
    void insertionSort();
    void moveNode(Node *origin, Node *destination);

    // helper methods
    int getListSize() const;
    void printListSize() const;
    void print() const;
};
