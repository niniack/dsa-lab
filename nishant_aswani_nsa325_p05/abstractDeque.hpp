//  File: abstractDeque.hpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Prelab 5
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 23 2019

class Node{
  public:
    int data;
    Node *next;
    Node *prev;
};

class Deque{
  private:
    int listSize;
    Node *head;
    Node *tail;
    void firstPush(Node *temp);
    void finalPop(Node *temp);

  public:
    Deque();
    ~Deque();

    void headPush(int data);
    void headPop();
    void tailPush(int data);
    void tailPop();

    void getListSize() const;
    void print() const;
};
