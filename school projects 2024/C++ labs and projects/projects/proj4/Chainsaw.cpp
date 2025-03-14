/******************************************************************************
 ** File:    Chainsaw.cpp
 ** Project: 202 Project 4, fall 2024
 ** Author:  Daniel Dreyer
 ** Section: 35
 ** E-Malil: ddreyer1@umbc.edu
 **
 ** Discription: this file creates weapon chainsaw, the chainsaw does the
 ** GetDamage() value times .5 to 2.5 damage, and returns the total and the
 ** name is returned to the user
 **
 ******************************************************************************/

///includes chainsaw.h file
#include "Chainsaw.h"

//this child class function creates the chainsaw from the parent weapon class function
Chainsaw::Chainsaw(int damage):Weapon(damage){

}

//special attack does the same instance of damge but multiplied by a random value
//between .5 and 2.5 and returns that value rounded down to the lowest int
int Chainsaw::SpecialAttack(){

  //displays to the user the weapons attack message
  cout<<"Your chainsaw shreds the enemy!"<<endl;
  
  //creates a random double between .5 to 2.5
  double v = (rand() % (3))+.5;

  //total damage of the weapon
  int total = GetDamage()*v;

  cout<<"You do "<<total<<" points of damage!"<<endl;
  //returns total
  return total;
  

}

//returns the name of the wepon when the function is called
string Chainsaw::GetName(){return "Chainsaw";}
