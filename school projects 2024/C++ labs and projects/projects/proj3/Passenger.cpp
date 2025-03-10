/*************************************************************************
 ** File:    Passenger.cpp
 ** Project: 202 Project 3, fall 2024
 ** Author:  Daniel Dreyer
 ** Section: 35
 ** E-Malil: ddreyer1@umbc.edu
 **
 ** Discription: this file contains the stored data of each passenger,
 ** storing line, number, and each start location, and final destination
 **
 *************************************************************************/

#include "Passenger.h"


//default constructor that sets values to default values
Passenger::Passenger(){

  m_number = 0;
  m_line = " ";
  m_startLocation = " ";
  m_finalDestination = " ";
}
//sets the geven variables to the passenger.h equivlent
Passenger::Passenger(int number, string line, string startLocation, string finalDestination){

  m_number = number;
  m_line = line;
  m_startLocation = startLocation;
  m_finalDestination = finalDestination;

}

//get statments that get the Passenger.h values for its specific name 
int Passenger::GetNumber(){return m_number;}
string Passenger::GetLine(){return m_line;}
string Passenger::GetStartLocation(){return m_startLocation;}
string Passenger::GetFinalDestination(){return m_finalDestination;}

//sets the given number to the number of passengers
void SetNumber(int number){number = number;}

//displays passengers as there number then the start location then the final destinatiom
void Passenger::DisplayPassenger(){

  cout<<"Passenger "<<m_number<<": "<<m_startLocation<<" to "<<m_finalDestination<<endl;
  
}
