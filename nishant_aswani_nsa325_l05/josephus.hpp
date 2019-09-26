//  File: josephus.hpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 5
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 23 2019

class Node{
  public:
    int data;
    Node *next;
    Node *prev;
};

class DoubleLinkedList{
  private:
    int listSize;         //track list size
    static int position;  //static variable to assign indices
    Node *currentSoldier; //pointer to point at soldier to offset from

    Node *head;
    Node *tail;
    //utility function to handle corner case of first push
    void _firstPush(Node *temp);
    //utility function to handle making list circular
    void _makeCircular();
    void _removeNode(Node *walk);
    void _finalExecution(Node *walk);

  public:
    bool circularFlag = false ;   //flag to check if the list is circular

    DoubleLinkedList();
    ~DoubleLinkedList();

    void linearPush();
    void executeSoldier(int direction, int offset);

    void getListSize() const;
    void printLinear() const;
};
