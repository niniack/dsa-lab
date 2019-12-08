//  File: main.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Prelab 12
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Nov 15 2019

#include "graph.hpp"
#include <iostream>
#include <tuple>

using namespace std;

int main(){

  vector<char> vertices {'a', 'b', 'c', 'd', 'e', 'f',
                      'g', 'h', 'i', 'j', 'k', 'l', 'm'};

  Graph g;

  for(unsigned int i=0; i<vertices.size(); ++i){
    g.addVertex(vertices[i]);
  }

  //adding edges
  g.addEdge('a','b');
  g.addEdge('a','c');
  g.addEdge('b','c');
  g.addEdge('b','d');
  g.addEdge('c','d');
  g.addEdge('m','d');
  g.addEdge('d','e');
  g.addEdge('d','j');
  g.addEdge('j','i');
  g.addEdge('j','k');
  g.addEdge('e','f');
  g.addEdge('e','g');
  g.addEdge('e','h');
  g.addEdge('e','i');
  g.addEdge('k','e');
  g.addEdge('k','i');
  g.addEdge('k','l');
  g.addEdge('f','g');
  g.addEdge('f','i');
  g.addEdge('g','h');
  g.addEdge('g','i');
  g.addEdge('h','i');
  g.addEdge('i','l');
  cout << "# of Vertices: " << g.getNumVertices() << endl;
  cout << "# of Edges: " << g.getNumEdges() << endl;


  cout << "Breadth First List (starting with a): ";
  //breadthFirstPrint(root);
  g.breadthFirstPrint('a');
  cout << endl << endl;

  cout << "Breadth First List (starting with m): ";
  //breadthFirstPrint(root);
  g.breadthFirstPrint('m');
  cout << endl << endl;


  return 0;
}
