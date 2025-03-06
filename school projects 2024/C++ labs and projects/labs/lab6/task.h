/*******************************************************************************
* File: task.h                                                                 *
* Project: CMSC202 Lab 6, Fall 2024                                            *
*******************************************************************************/

#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>
using namespace std;

class Task {
 public:
  Task(); //default constructor

  Task(string name, int type); //overloaded constructor

  // GetName() returns the name of the task to be accomplished
  string GetName();

  // GetUrgency() returns a code representing the urgency of the task
  int GetUrgency();

  // SetName() sets m_name to name
  void SetName(string name);

  // SetUrgency() sets m_urgency to urgency
  void SetUrgency(int urgency);

 private:
  string m_name; // name of the task
  int m_urgency; // urgency code of the task (e.g. immediate, soon, distant)
};

#endif
