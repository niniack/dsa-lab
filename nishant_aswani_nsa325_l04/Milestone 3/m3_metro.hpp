//  File: m3_metro.hpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 4
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
  void remove(std::string stationName);
  void print() const;
  void reverse();
  void getListSize() const;
};
