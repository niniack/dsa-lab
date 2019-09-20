//  File: m2.h
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 2 2019

#ifndef MILESTONE2_H
#define MILESTONE2_H

using namespace std;

class Node{
  public:
    long int data;
    Node *below;
};

class Stack{
  public:
    int stackSize;
    int isbn = 123456789;
    Node *head;
    Node *tail;
  public:
    Stack();
    ~Stack();
    void push(int data);
    void pop();
    void print() const;
    void getStackSize() const;
  private:
    void getHeadValue() const;
    void getTailValue() const;
    void getISBN() const;
};

#endif
