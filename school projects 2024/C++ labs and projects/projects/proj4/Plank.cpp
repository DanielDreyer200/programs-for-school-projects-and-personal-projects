/******************************************************************************
 ** File:    Plank.cpp
 ** Project: 202 Project 4, fall 2024
 ** Author:  Daniel Dreyer
 ** Section: 35
 ** E-Malil: ddreyer1@umbc.edu
 **
 ** Discription: this file creates weapon plank, this plank does 2 instances
 ** of damage between 1 and whatever GetDamage() is and adds them together as
 ** their special attack, it also gives its name when called
 **
 ******************************************************************************/

//includes the plank.h file
#include "Plank.h"


//this child class function creates the plank from the parent weapon class function
Plank::Plank(int damage):Weapon(damage){

  
}

//special attack does 2 instances  and adds them together and returns thier total,
//along with displaying text of the weapons attack message
int Plank::SpecialAttack(){

  //displays to user the weapons attack message
  cout<<"You bash twice with your plank!"<<endl;

  //creates 2 instances of random damage
  int v = (rand() % GetDamage())+1;

  int t = (rand() % GetDamage())+1;

  //adds the 2 random damage instances together
  int total = v + t;

  cout<<"You do "<<total<<" points of damage!"<<endl;
  //returns the total
  return total;
}

//returns the name of the wepon when the function is called
string Plank::GetName(){return "Plank";}
