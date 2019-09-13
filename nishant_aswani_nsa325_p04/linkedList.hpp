//  File: linkedList.hpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 16 2019

class Node{
public:
  int data;
  Node *next;
};

class List{
private:
  int listSize;
  Node *head;
public:
  List();
  ~List();
  void put(int loc, int data);
  void print() const;
  void getListSize() const;
};
