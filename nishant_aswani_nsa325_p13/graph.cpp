//  File: graph.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 12
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Nov 18 2019


#include "graph.hpp"
#include <iostream>
#include <unordered_set>
#include <stack>
#include <queue>


using namespace std;

Node::Node(char initData): data(initData) {}

char Node::getData() const{
  return data;
}

Graph::Graph(): numVertices(0), numEdges(0) {}

Graph::~Graph(){}

void Graph::addVertex(char data){

  if (dir.find(data) != dir.end()){
    return;
  }

  Node* newVertex = new Node(data);
  dir.insert({data, newVertex});

  ++numVertices;
}

void Graph::addEdge(char source, char destination){
  // obtain vertices from map
  Node* v1 = dir[source];
  Node* v2 = dir[destination];

  // check one of the lists to see if edge already exists
  // validation to avoid duplicated edges
  // could be faster if used map instead of list

  bool duplicatedEdge = false;
  for (auto i = v1->adj.begin(); i != v1->adj.end(); ++i){
    if(*i == v2){
      duplicatedEdge = true;
    }
  }

  if (!duplicatedEdge){
    v1->adj.push_back(v2);
    // v2->adj.push_back(v1);
    ++numEdges;
  }
}

int Graph::getNumVertices() const{
  return numVertices;
}

int Graph::getNumEdges() const{
  return numEdges;
}

void Graph::breadthFirstPrint(char rootChar){
  Node* rootNode = dir[rootChar];

  if (rootNode == nullptr){
    cout << "Invalid root for BFS" << endl;
    return;
  }

  //queue for BFS
  queue <Node*> q;
  //keep track of printed characters
  unordered_set<Node*> visited;

  //push the root node to the queue
  q.push(rootNode);

  while (!q.empty()){

    Node* front = q.front();
    q.pop();

    if (visited.find(front) == visited.end()){
      cout << front->getData() << ",";
      visited.insert(front);
    }

    for (auto i = front->adj.begin(); i!=front->adj.end(); ++i){
      if (visited.find(*i) == visited.end()){
        q.push(*i);
      }
    }
  }
}

// void Graph::depthFirstPrint(char rootChar){
//
//   Node* rootNode = dir[rootChar];
//
//   if(rootNode == nullptr){
//     cout << "Invalid root for DFS" << endl;
//     return;
//   }
//
//   // stack for DFS
//   stack<Node*> stack;
//   // keep track of printed characters
//   unordered_set<Node*> visited;
//
//   // push the root node
//   stack.push(rootNode);
//
//   while(!stack.empty()){
//
//     // obtain the top value and pop it from stack
//     Node* top = stack.top();
//     stack.pop();
//
//     // print the value if it was not visited previously
//     // then add it to the list of visited
//     if (visited.find(top) == visited.end()){
//       cout << top->getData() << ",";
//       visited.insert(top);
//     }
//
//     // place adjacent nodes into stack
//     for (auto i = top->adj.begin(); i != top->adj.end(); ++i){
//       if (visited.find(*i) == visited.end()){
//         stack.push(*i);
//       }
//     }
//   }
// }
