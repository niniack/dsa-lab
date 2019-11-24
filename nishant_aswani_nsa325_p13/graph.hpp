//  File: graph.hpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 12
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Nov 18 2019

#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

class Node{

  private:
    char data;
  public:
    // could have been implemented as a map as well
    list<Node*> adj;
    Node(char initData);
    char getData() const;
};

class Graph{
  private:
   // lookup map for all nodes based on character to avoid iterating
    unordered_map<char, Node*> dir;
    int numVertices;
    int numEdges;

  public:
    Graph();
    ~Graph();

    // driver methods

    void addVertex(char data);
    void addEdge(char source, char destination);

    // utility methods
    int getNumVertices() const;
    int getNumEdges() const;
    void breadthFirstPrint(char rootChar);
    // void depthFirstPrint(char rootChar);


};
