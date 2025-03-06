/******************************************************************************
 ** File:    Mannequin.cpp
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

//include mannequin. h file
#include "Mannequin.h"

//creates a mannequin with a name, hp, damage, and description
Mannequin::Mannequin(string name, int hp, int damage, string desc):Enemy(name, hp, damage, desc){

  
}

//special attack value is returned and desplays the mammequin's special attack
//description to user
int Mannequin::SpecialAttack(){

  int MANNEQUIN_SPECIAL = 2;

  cout<<"The Mannequin smashes with their kick!"<<endl;

  cout<<"you take "<<MANNEQUIN_SPECIAL<<" points of damage"<<endl;
  
  
  return MANNEQUIN_SPECIAL;}
