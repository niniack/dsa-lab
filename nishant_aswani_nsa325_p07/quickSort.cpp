//  File: quickSort.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Prelab 6
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 30 2019

#include <iostream>

using namespace std;

int selectPivot(int low, int high){
  return high;
}

void swap(int &a, int &b){
  int temp;
  temp = a;
  a = b;
  b = temp;
}

int partition(int values[10], int low, int high){
  int pivotIndex = selectPivot(low, high);
  int pivot = values[pivotIndex];

  int i = low;
  int j = high-1;

  while (i <= j){

    while (values[i] < pivot){
      ++i;
    }

    while (values[j] >= pivot){
      --j;
    }

    if (i == j)
    {
      swap(values[j], values[high]);
      break;
    }

    if(values[i] >= pivot && i < j){
      swap(values[i], values[j]);
    }

  }

  if (values[high] >= values[j]){
    swap(values[i], values[high]);
  }

  return i;

}

void quickSort(int values[10], int low, int high){
  int pi;

  if (low > high) return;

  pi = partition(values, low, high);

  // print sorted
  cout << endl;

  for (int i=0; i<8; ++i){
    cout << values[i] << ", ";
  }
  quickSort(values, low, pi-1);
  quickSort(values, pi+1, high);

}

int main(){

  int values[8] {3,2,4,1,1,1,1,2};
  int size = sizeof(values)/sizeof(values[0]);

  // print original
  cout << "Original Array:" << endl;

  for (int i=0; i<size; ++i){
    cout << values[i] << ", ";
  }
  cout << endl << endl;

  quickSort(values, 0, 7);

  // print sorted
  cout << "Sorted Array:" << endl;

  for (int i=0; i<size; ++i){
    cout << values[i] << ", ";
  }

}
