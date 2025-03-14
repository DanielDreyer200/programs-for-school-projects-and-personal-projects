/*******************************************************************************
* File: lab6.cpp                                                               *
* Project: CMSC202 Lab 6, Fall 2024                                            *
* Author: [YOUR NAME HERE]                                                     *
* Date:                                                                        *
* Email:                                                                       *
*                                                                              *
* Makes a todo list using user input, then displays it.                        *
*******************************************************************************/

#include "task.h"
#include <vector>

// sets IMMEDIATE = 0, SOON = 1, DISTANT = 2
enum URGENCY_CODE { IMMEDIATE, SOON, DISTANT  };

// Please write FillTodoList.
// Ask the user how many tasks they want to add.
// For each task, ask the user for the name and urgency (0-2).
// Create a Task object with the information and add it to the vector.
// You may have to use:
//   if(cin.peek() == '\n') cin.ignore(256, '\n');
// to clear the buffer.
void FillTodoList(vector<Task> &todoList) {


  int type;
  string urgency;
  int amount;

  string name;
  
  cout<<"how many tasks would you like to add?"<<endl;
  cin>> amount;

 
    for(int i= 0; i< amount;i++){

      cout<<"item "<<i+1<<":"<<endl;
      getline(cin, name);

      cout<<"how urgant\n 2 = distant 1=soon 3 = immediate"<<endl;

     
      if(cin.peek()=='\n'){

	cin.ignore(256,'\n');
      }else{

	getline(cin, urgency);

      }

      //if(urgency == 1){

	
	
      //}

      type = stoi(urgency);


      Task tasks;

      Task(name,type);
      

      
      
      
      todoList.push_back(tasks);
      
      
    }

    
  
}


// Please write DisplayWithoutIterator.
// Display the number of tasks on the todo list.
// For each task, display the name and urgency.
// Use a switch statement to display the urgency.
// Don't forget to display the name as well.
void DisplayWithoutIterator(vector<Task> &todoList) {

  for(int i= 0; i<todoList.size();){

    
    cout<<"the task is:"<<todoList[i]<<endl;
    cout<<"and it is labeled"<<endl;
    switch(todoList[i+1]>-1) {
    case IMMEDIATE:
      cout << "!! Immediate: ";
      break;
    case SOON:
      cout << "!  Soon: ";
      break;
    case DISTANT:
      cout << "-  Distant: ";
      break;
    default:
      cout << "-  None: ";
      break;
    }

    i== i+2;
    
  }
  
}


// Please write DisplayWithIterator.
// This function is the same as the one above, but uses an iterator to display
// the todo list.
void DisplayWithIterator(vector<Task> &todoList) {

}


// Here is some free code! Use it wisely!
/*
  switch(FILL THIS IN) {
  case IMMEDIATE:
  cout << "!! Immediate: ";
  break;
  case SOON:
  cout << "!  Soon: ";
  break;
  case DISTANT:
  cout << "-  Distant: ";
  break;
  default:
  cout << "-  None: ";
  break;
  }
*/


// Main
// Provided.

int main() {
  vector<Task> todoList;
  FillTodoList(todoList);
  
  cout << "Displaying Todo List without iterator:" << endl;
  DisplayWithoutIterator(todoList);
  cout << endl << "Displaying Todo List with iterator:" << endl;
  DisplayWithIterator(todoList);

  cout << endl << "What a good-looking todo list!" << endl;
  return 0;
}




