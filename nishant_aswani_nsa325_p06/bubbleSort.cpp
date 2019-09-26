//  File: bubbleSort.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Prelab 6
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 30 2019

#include <iostream>

using namespace std;

void swap(int &a, int &b){
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void bubbleSort(int values[10], int size){
  for (int i=0; i<size-1; ++i){
    for (int j=0; j<size-1-i; ++j){
      if (values[j] > values[j+1]) {
        swap(values[j], values[j+1]);
      }
    }
  }

}

int main(){

  int values[10] {4,5,9,10,3,8,6,1,7,2};
  int size = sizeof(values)/sizeof(values[0]);

  cout << "Original Array:" << endl;

  for (int i=0; i<size; ++i){
    cout << values[i] << ", ";
  }
  cout << endl << endl;

  bubbleSort(values, size);

  cout << "Sorted Array:" << endl;

  for (int i=0; i<size; ++i){
    cout << values[i] << ", ";
  }

}
