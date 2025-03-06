/******************************************************************************
 ** File:    Shotgun.cpp
 ** Project: 202 Project 4, fall 2024
 ** Author:  Daniel Dreyer
 ** Section: 35
 ** E-Malil: ddreyer1@umbc.edu
 **
 ** Discription: this file creates weapon shotgun, this shotgun does a
 ** random instance of damage between 1 and whatever GetDamage() is and multiplies
 ** it by 2 and returns that value, it also gives its name when called
 **
 ******************************************************************************/


//includes the plank.h file
#include "Shotgun.h"


//this child class function creates the shotgun from the parent weapon class function
Shotgun::Shotgun(int damage):Weapon(damage){

}

//special attack does a random instance of damage that is then multiplied by 2
int Shotgun::SpecialAttack(){

  //displays to the user  the wepons attack message
  cout<<"You fire both barrels of the shotgun!"<<endl;
  
  //creates a random instance of damage
  int v = (rand() % GetDamage()) + 1;

  //multiplies v by 2
  int total = v*2;

  cout<<"You do "<<total<<" points of damage!"<<endl;
  //returns the total
  return total;

}

//returns the name of the wepon when the function is called
string Shotgun::GetName(){return "Shotgun";}
