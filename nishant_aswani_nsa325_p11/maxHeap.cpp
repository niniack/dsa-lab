//  File: maxHeap.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 9
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Nov 11 2019


#include "maxHeap.hpp"
#include <iostream>

using namespace std;


maxHeap::maxHeap(): size(0), maxSize(10){}
maxHeap::maxHeap(int initMaxSize): size(0),
                                   maxSize(initMaxSize-1),
                                   dataArray(new int[initMaxSize]){}
maxHeap::~maxHeap(){}

void maxHeap::buildHeap(int values[], int size){
  for (int i=0; i<size; ++i){
    insertKey(values[i]);
  }
}

void maxHeap::insertKey(int data){

  if (size < maxSize){
    int index = size + 1;

    while(index > 1 && dataArray[index/2] <= data){
      dataArray[index] = dataArray[index/2];
      index = index/2;
    }

    dataArray[index] = data;
    ++size;

    dataArray[0] = size;
  }
}

void maxHeap::heapSort(){
  int index = size;

  int temp = 0;
  while(index > 1){
    temp = dataArray[1];
    dataArray[1] = dataArray[index];
    dataArray[index] = temp;
    --index;
    heapify(index);
  }
}

void maxHeap::heapify(int max){
  // set index to top of array
  int index = 1;

  // while index is within the heap
  while(index < max){
    int leftChild = index*2;
    int rightChild = leftChild+1;
    int greaterChild = index;

    // if left child is within bounds and greater than current index, set new greater child
    if (leftChild <= max && dataArray[leftChild] > dataArray[greaterChild]){
      greaterChild = leftChild;
    }

    // if right child is within bounds and greater than current greater child, set new greater child
    if (rightChild <= max && dataArray[rightChild] > dataArray[greaterChild]){
      greaterChild = rightChild;
    }

    if (leftChild > max && rightChild > max){
      break;
    }

    swap(index, greaterChild);
    index = greaterChild;
  }
}

void maxHeap::swap(int a, int b){
  int temp;
  temp = dataArray[a];
  dataArray[a] = dataArray[b];
  dataArray[b] = temp;
}

void maxHeap::printHeap() const{
  for (int i=1; i<size+1; ++i){
    cout << dataArray[i] << ", ";
  }
  cout << endl;
}

bool maxHeap::isEmpty() const{
  return (size==0);
}
