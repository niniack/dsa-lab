//  File: m1_metro.hpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Prelab 4
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 16 2019

#include <string>

class Node{
public:
  std::string data;
  Node *next;
};

class List{
private:
  int listSize;
  Node *head;
public:
  List();
  ~List();
  void put(int loc, std::string data);
  void print() const;
  void getListSize() const;
};
