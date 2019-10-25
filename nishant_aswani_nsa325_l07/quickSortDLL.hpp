//  File: quickSortDLL.hpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Lab 6
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Oct 7 2019

class Data{
  public:
    Data();
    Data(double initSpeed, int initICA, int initICB);
    ~Data();
    double speed;
    int ica;
    int icb;
    int getAverage();
};

class Node{
  public:
    int position;
    Data stats;
    Node *next;
    Node *prev;
};

class DoubleLinkedList{
  private:
    // pointers and data
    int listSize;
    Node *head;
    Node *tail;
    static int position;  //static variable to assign indices

    // aux functions for internal use
    void firstPush(Node *temp);
    void finalPop(Node *temp);
    bool empty() const;

    Node *partition(Node *low, Node *high);
    void swapNodeContent(Node *nodeA, Node *nodeB);

  public:
    // constructors and destructors
    DoubleLinkedList();
    DoubleLinkedList(DoubleLinkedList const &list);
    ~DoubleLinkedList();

    // primary methods
    void headPush(Data stats);
    void tailPush(Data stats);
    void quickSort(Node *low, Node *high);

    // helper methods
    Node *getHead() const;
    Node *getTail() const;
    int getListSize() const;
    void printListSize() const;
    void print() const;
};
