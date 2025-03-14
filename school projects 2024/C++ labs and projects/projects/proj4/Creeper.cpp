/******************************************************************************
 ** File:    Creeper.cpp
 ** Project: 202 Project 4, fall 2024
 ** Author:  Daniel Dreyer
 ** Section: 35
 ** E-Malil: ddreyer1@umbc.edu
 **
 ** Discription: this file creates the enemy parent class of the creeper sets
 ** its name, its hp is damage and description, sets its special attack to a
 ** value and gives a message
**
******************************************************************************/
//include creeper.h file
#include "Creeper.h"

//sets the name, hp, damage and description from the enemy class to the creeper
Creeper::Creeper(string name, int hp, int damage, string desc):Enemy(name, hp, damage, desc){
  
}

//special attack is returned from the creeper and desplays the creeper
//special attack description
int Creeper::SpecialAttack(){

  int CREEPER_SPECIAL = 4;

  cout<<"A Creeper takes a large bite out of you!"<<endl;

  cout<<"you take "<<CREEPER_SPECIAL<<" points of damage"<<endl;
  
  return CREEPER_SPECIAL;}
