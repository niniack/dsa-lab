//  File: main.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 2 2019

#include "m1.h"
#include <iostream>

using namespace std;


int main(){

  int choice;
  bool menuOn = true;
  Stack stack;

  while (menuOn != false){
    cout << endl;
    cout << "*******************************" << endl;
    cout << " 1 - Print all the inventory information." << endl;
    cout << " 2 - Add a book to inventory." << endl;
    cout << " 3 - Remove a book from inventory." << endl;
    cout << " 4 - Print the number of books for sale." << endl;
    cout << " 5 - Exit." << endl;
    cout << " Enter your numerical choice and press return: " << endl;

    cin >> choice;

    switch (choice)
    {
      case 1:
        cout << endl;
        cout << "These are the available books: " << endl;
        stack.print();
        break;

      case 2:
      {
        int sn = 0;
        cout << endl;
        cout << "What is your serial number?" << endl;
        cin >> sn;
        stack.push(sn);
        break;
      }

      case 3:
        cout << endl;
        cout << "Removing a book from inventory..." << endl;
        stack.pop();
        break;

      case 4:
        cout << endl;
        stack.getStackSize();
        break;

      case 5:
        cout << endl;
        cout << "End of Program.\n";
        menuOn = false;
        break;

      default:
        cout << endl;
        cout << "Not a Valid Choice. \n";
        cout << "Choose again.\n";
        cin >> choice;
        break;
    }
  }
return 0;
}
