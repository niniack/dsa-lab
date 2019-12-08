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

Node::Node(string initData): data(initData) {}

string Node::getData() const{
  return data;
}

Graph::Graph(): numVertices(0), numEdges(0) {}

Graph::~Graph(){}

void Graph::addVertex(string data){

  if (dir.find(data) != dir.end()){
    return;
  }

  Node* newVertex = new Node(data);
  dir.insert({data, newVertex});

  ++numVertices;
}

void Graph::addEdge(string source, string destination){
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

void Graph::topSort(){
  
  //  map to keep track of indegrees
  unordered_map<Node*, int> m;
  //  queue to keep track of sort
  queue <Node*> q;
  //keep track of printed characters
  unordered_set<Node*> visited;

  //  iterate through the adj list of each node to make a table of indegrees
  for (auto i = dir.begin(); i!=dir.end(); ++i){

    Node* current = i->second;

    //  if not already in the map, add it
    if(m.find(current) == m.end()){
      m.insert({current, 0});
    }

    for (auto j=current->adj.begin(); j!=current->adj.end();++j){

      if(m.find(*j) != m.end()){
        ++m[*j];
      }

      else{
        m[*j] = 1;
      }

    }
  }

  //  iterate through the map to find all values with indegree 0
  //  add them to stack
  for (auto i = m.begin(); i != m.end(); ++i){
    if(i->second == 0){
      q.push(i->first);
    }
  }

  while(!q.empty()){
    Node* current = q.front();

    if (visited.find(current) == visited.end()){
      visited.insert(current);
    }

    for (auto i=current->adj.begin(); i!=current->adj.end(); ++i){
      //  decrement indegree count
      --m[*i];

      //  if indegree count == 0 and its not been visited
      //  add it to queue
      if (m[*i] == 0 && (visited.find(*i) == visited.end())){
        q.push(*i);
      }
    }

    // print the
    cout << current->getData() << ",";
    q.pop();
  }
}

void Graph::breadthFirstPrint(string rootChar){
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
