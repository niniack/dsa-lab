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
    string data;
  public:
    // could have been implemented as a map as well
    list<Node*> adj;
    Node(string initData);
    string getData() const;
};

class Graph{
  private:
   // lookup map for all nodes based on string to avoid iterating
    unordered_map<string, Node*> dir;
    int numVertices;
    int numEdges;

  public:
    Graph();
    ~Graph();

    // driver methods

    void addVertex(string data);
    void addEdge(string source, string destination);

    // utility methods
    int getNumVertices() const;
    int getNumEdges() const;
    void breadthFirstPrint(string rootChar);
    void topSort();


};
