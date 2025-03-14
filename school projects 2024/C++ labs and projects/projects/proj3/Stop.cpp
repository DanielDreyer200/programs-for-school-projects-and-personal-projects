/*************************************************************************
 ** File:    Stop.cpp
 ** Project: 202 Project 3, fall 2024
 ** Author:  Daniel Dreyer
 ** Section: 35
 ** E-Malil: ddreyer1@umbc.edu
 **
 ** Discription: this file contains the stored data of each stop, with its
 ** name and number along with setting at giving out m_next which is to
 ** represent the next stop
 **
 *************************************************************************/


#include "Stop.h"

//default constructor that sets elements to default values
Stop::Stop(){

  m_number =0;
  m_name = " ";
  m_next = nullptr;
}
//overloaded constructor that sets the given values to the Stop.h values
Stop::Stop(int number, string name){

  m_number = number;
  m_name = name;    
}

//getters that allows others to get the corisponding values 
int Stop::GetNumber(){return m_number;}
string Stop::GetName(){return m_name;}
Stop* Stop::GetNext(){return m_next;}

//sets m_next to the given stop from a different function
void Stop::SetNext(Stop* newStop){

  m_next = newStop; 
   
}
