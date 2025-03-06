#include <iostream>
#include <string>
#include "task.h"
#include <vector>

using namespace std;


Task::Task(){

  string name;
  int type;

  
}

Task::Task(string name, int type){}


string Task::GetName(){return m_name;}

int Task::GetUrgency(){return m_urgency;}

void Task::SetName(string name){name = m_name;}

void Task::SetUrgency(int type){m_urgency = type;}

