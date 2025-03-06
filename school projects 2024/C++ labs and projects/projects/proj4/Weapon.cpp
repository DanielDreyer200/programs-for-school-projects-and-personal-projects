/******************************************************************************
 ** File:    Weapon.cpp
 ** Project: 202 Project 4, fall 2024
 ** Author:  Daniel Dreyer
 ** Section: 35
 ** E-Malil: ddreyer1@umbc.edu
 **
 ** Discription: this file contains code to make the weapons, this parent
 ** function calls the damage both improved and regular damage for each weapons
 ** child class
 **
 ******************************************************************************/

//includes the wapon.h file
#include "Weapon.h"

//oveerloaded constructor places the given damage to the damage of the wepeon
Weapon::Weapon(int damage){

  m_damage = damage;
  
}
//destructor needed because child classes exist
Weapon::~Weapon(){
  
}

//returns the damage of the weapon
int Weapon::Attack(){


  return m_damage;

}

//gives the damage of the attack to a function that calls it
int Weapon::GetDamage(){return m_damage;}

//sets the given improved damage to the damage of the weapon
void Weapon::ImproveWeapon(int improve_damage){

  m_damage = improve_damage;


}
