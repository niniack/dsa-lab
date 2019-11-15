//  File: maxHeap.hpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 9
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Nov 11 2019


class maxHeap{
 private:
    int size;
    int maxSize;
    int* dataArray;
    void swap(int a, int b);

  public:
    maxHeap();
    maxHeap(int initMaxSize);
    ~maxHeap();

    //driver methods
    void buildHeap(int values[], int size);
    void insertKey(int data);
    void heapSort();
    void heapify(int max);

    //utility methods
    bool isEmpty() const;
    void printHeap() const;

};
