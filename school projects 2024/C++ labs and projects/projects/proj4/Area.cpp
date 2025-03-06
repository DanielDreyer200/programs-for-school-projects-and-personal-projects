/******************************************************************************
 ** File:    Area.cpp
 ** Project: 202 Project 4, fall 2024
 ** Author:  Daniel Dreyer
 ** Section: 35
 ** E-Malil: ddreyer1@umbc.edu
 **
 ** Discription: this file contains code to make the map, storing each
 ** area individually of the map using the id, name description, and the
 ** north, east, south, and werst directions that connect to this area.
 ** it also checks the direction to see if there is an area in that direction.
 **
 ******************************************************************************/

#include "Area.h"

//overloaded constructor that places the id, name, description and each direction into
//appropriate variables
Area::Area(int id, string name, string desc, int north, int east, int south, int west){

  //sets values to there corisponding values
  m_ID = id;
  m_name = name;
  m_desc = desc;

  //places each direction into the approprate array signified by the enum defining the direction
  m_direction[n] = north;
  m_direction[e] = east;
  m_direction[s] = south;
  m_direction[w] = west;
  
}

//gives the name of the area when the function is called
string Area::GetName(){return m_name;}

//gives the Id of the area when the function is called
int Area::GetID(){return m_ID;}

//gets the description of the area when the function is called
string Area::GetDesc(){return m_desc;}

//takes the char geven and compares it to directional letters and if they match return the value
//of that direction according to the stored value of the array at that char
int Area::CheckDirection(char myDirection){


  //if the given char is N or n returns the value of m_direction at n
  if(myDirection == 'N' || myDirection == 'n'){

    return m_direction[n];

    //if the given char is E or e returns the value of m_direction at e
    }else if(myDirection == 'E'|| myDirection == 'e'){

    return m_direction[e];

    //if the given char is S or s returns the value of m_direction at s
    }else if(myDirection == 'S' || myDirection == 's'){

    return m_direction[s];

    //if the given char is W or w returns the value of m_direction at w
    }else if(myDirection == 'W' || myDirection == 'w'){

    return m_direction[w];

    //if no value is made then -1 id returned
  }else{
    return -1;
    
  }

}

//desplays the area name and description and the possible directions the user is able to take
void Area::PrintArea(){

  //desplays name and description
  cout<<m_name<<endl;
  cout<<m_desc<<endl;

  //desplays avalible route to user
  cout<<"Avalible Routes: ";

  //if the northern value is not -1 then add N to the avalible route
  if(m_direction[n] != -1){

    cout<<"N ";

    //if the eastern value is not -1 then add E to the avalible route
  } if(m_direction[e] != -1){

    cout<<"E ";

    //if the southern value is not -1 then add S to the avalible route
  } if(m_direction[s] != -1){

    cout<<"S ";

    //if the western value is not -1 then add W to the avalible route
  } if(m_direction[w] != -1){

    cout<<"W ";


  }

  //ends the line displayed
  cout<<endl;

}
