//  File: stack.hpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 2 2019

#ifndef STACK_H
#define STACK_H

using namespace std;

struct Node{
    int data;
    Node *below;
};

class Queue{
  public:
    int stackSize;
    Node *head;
  public:
    Queue();
    ~Queue();
    void push(int data);
    void pop();
    void print() const;
    void getStackSize() const;
    void getHeadValue() const;
};

#endif
