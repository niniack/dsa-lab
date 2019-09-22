//  File: main.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Prelab 5
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 23 2019

#include "abstractDeque.hpp"
#include <iostream>

using namespace std;

int main(){

  int data;
  int select;
  int flag = true;
  Deque deque;

    while (flag){
      cout << endl;
      cout << "Menu for Double-Ended Queue Data Type with a Doubly Linked List" << endl;
      cout << "*******************************" << endl;
      cout << "(1) Add a value to the front" << endl;
      cout << "(2) Add a value to the back" << endl;
      cout << "(3) Remove a value from the front" << endl;
      cout << "(4) Remove a value from the back" << endl;
      cout << "(5) Display the contents of the double-ended queue" << endl;
      cout << "(6) Exit program" << endl;
      cout << endl;
      cout << "Enter your numerical choice and press return: " << endl;

      if(!(cin >> select)){
        cout << "Didn't enter a number. Exiting..." << endl;
        return 0;
      }

      switch (select) {
        case 1:
          cout << "Please enter an integer to push:" << endl;
          cin >> data;
          deque.headPush(data);
          break;
        case 2:
          cout << "Please enter an integer to push:" << endl;
          cin >> data;
          deque.tailPush(data);
          break;
        case 3:
          deque.headPop();
          break;
        case 4:
          deque.tailPop();
          break;
        case 5:
          deque.print();
          break;
        case 6:
          cout << endl;
          cout << "End of Program.\n";
          flag = false;
          break;
        default:
          cout << endl;
          cout << "Not a Valid Choice. \n";
          cout << "Choose again.\n";
          cin >> select;
          break;
    }
  }
  return 0;
}
