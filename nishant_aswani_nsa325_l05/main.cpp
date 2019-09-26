//  File: main.cpp
//  Name: Nishant Aswani
//  Instructor: Cristoforos Vasilatos
//  Assignment: Prelab 5
//  Course: Data Structures and Algorithms (ENGR-UH 3510) Fall 2019
//  Due: Sep 23 2019

#include "josephus.hpp"
#include <iostream>

using namespace std;

int main(){

  int offset;
  int direction;
  int select;
  int programFlag = true;
  DoubleLinkedList dll;

    while (programFlag){
      cout << endl;
      cout << "Menu for the Josephus Simulation" << endl;
      cout << "*******************************" << endl;
      cout << "(1) Push a soldier to the list" << endl;
      cout << "(2) Execute a soldier" << endl;
      cout << "(3) Dispay soldiers" << endl;
      cout << "(4) Exit program" << endl;
      cout << endl;
      cout << "Enter your numerical choice and press return: " << endl;

      if(!(cin >> select)){
        cout << "Didn't enter a number. Exiting..." << endl;
        return 0;
      }

      switch (select) {
        case 1:
          if (!dll.circularFlag){
            dll.linearPush();
          }
          else {
            cout << endl;
            cout << "Sorry adding soldiers is not allowed once execution is initiated."<< endl;
          }
          break;
        case 2:
          cout << "Please enter for (1) for clockwise and (2) for counterclockwise" << endl;
          cin >> direction;
          cout << "Please enter how many away to kill:" << endl;
          cin >> offset;
          cout <<"Direction: "<< direction << " , Offset: " << offset << endl;
          cout << endl;
          dll.executeSoldier(direction, offset);
          break;
        case 3:
          dll.printLinear();
          break;
        case 4:
          cout << endl;
          cout << "End of Program.\n";
          programFlag = false;
          break;
        default:
          cout << endl;
          cout << "Not a valid choice. \n";
          cout << "Choose again.\n";
          cin >> select;
          break;
    }
  }
  return 0;
}
