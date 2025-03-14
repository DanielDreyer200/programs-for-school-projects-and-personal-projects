/*************************************************************************
 ** File:    Line.cpp
 ** Project: 202 Project 3, fall 2024
 ** Author:  Daniel Dreyer
 ** Section: 35
 ** E-Malil: ddreyer1@umbc.edu
 **
 ** Discription: this file contains the functions for the line, getting
 ** the line its on, adding stops that are on any particular line.
 ** calculates the distance between stops on a line and appropriatly displays
 ** the line in the order dictated by the project requirments.
 **
 *************************************************************************/
#include "Line.h"

//default constructor, sets all values to 0 or nullptr
Line::Line(){
  //sets all values to a 0 or nullptr
  m_head = nullptr;
  m_tail = nullptr;
  m_lineName = "";
  m_totalStops = 0;
}

//overloaded constructor that sets m_line name to the line value given
Line::Line(string line){

  m_lineName= line;  
}
//destructor that removes all stops from the line
Line::~Line(){

  //deletes each variable in temp untill it equals nullptr
  if(m_head != nullptr){

    if(m_head == m_tail){

      m_tail = nullptr;

    }
    Stop* temp = m_head;

    m_head = m_head->GetNext();

    delete temp;

    //decreases m_totalStops
    m_totalStops--;

  }
  
}
//returns the name of the given line
string Line::GetLineName(){

  //gets the line name from m+head and places it in m_lineName
  m_head->GetName() = m_lineName;
  
  return m_lineName;
}

//dynamically allocates new stop and adds that value to the end of the linked list
void Line::AddStop(int number, string name){

  //makes temp a stop with the number and name of the stop
  Stop *temp = new Stop(number, name);

  //if nullptr is the tail then set everything to nullptr
  if(m_tail==nullptr){

    m_head = m_tail = temp;

    //m_tail sets the next value to that of temps value then equals temp
  }else{

    m_tail->SetNext(temp);
    m_tail = temp;
  }

  //adds total stop
  m_totalStops++;
}


//values to be used in the next function
int x=0;
int y=0;

//calculates the distance between the given start and given end value per line from a passneger
int Line::CalculateDistance(string  start, string stop) {

  //sets temp to m_head
  Stop* temp = m_head;
  int d =0;

  //while temp is not nullptr continues the function
  while (temp != nullptr) {

    //if temps name is the same as start then set its number to x
    if (temp->GetName() == start){

      x=temp->GetNumber();
      
    }

    //if temps name is the same as start then set its number to y with a +1 and a deduction of x
    if (temp->GetName() == stop){

      y =(temp->GetNumber()+1)- x;
      d=y;

      //return value of d
      return d;

    }

    //sets temp to the next temp value
    temp = temp->GetNext();
  }

  //return -1 if conditions arent met
  return -1; 
    
}
//creates the order for the line itself
void Line::PrintLineDetails(){

  //if there is no stop then tells the user
  if(m_totalStops ==0){

    cout<<" none "<<endl;
    
    }else{

    //sets the line to be the number then the name and then the color its on
    cout<<m_head->GetNumber()<<". "<<m_head->GetName()<<" ("<<GetLineName()<<")"<<endl;

  }

}



