/******************************************************************************
 ** File:    Mandarin.cpp
 ** Project: 202 Project 4, fall 2024
 ** Author:  Daniel Dreyer
 ** Section: 35
 ** E-Malil: ddreyer1@umbc.edu
 **
 ** Discription: this file creates the enemy parent class of the mandarin sets
 ** its name, its hp is damage and description, sets its special attack to a
 ** value and gives a message
 **
 ******************************************************************************/

//includes mandarin.h file
#include "Mandarin.h"

//creates the mandarin name, hp, damage and description of the enemy
Mandarin::Mandarin(string name, int hp, int damage, string desc):Enemy(name, hp, damage, desc){

    
}

//the special attack of the mandarin is set and desplays the special attack
//description to the user
int Mandarin::SpecialAttack(){

  int MANDARIN_SPECIAL = 3;

  cout<<"A Mandarin hammers you with their large arms!"<<endl;
  cout<<"you take "<<MANDARIN_SPECIAL<<" points of damage"<<endl;
  
  
  return MANDARIN_SPECIAL;}
