//  File: m1.h
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 2 2019

#ifndef MILESTONE1_H
#define MILESTONE1_H

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
  public:
    Stack();
    ~Stack();
    void push(int data);
    void pop();
    void print() const;
    void getStackSize() const;
  private:
    void getHeadValue() const;
    void getISBN() const;
};

#endif
