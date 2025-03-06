/******************************************************************************
 ** File:    Hero.cpp
 ** Project: 202 Project 4, fall 2024
 ** Author:  Daniel Dreyer
 ** Section: 35
 ** E-Malil: ddreyer1@umbc.edu
 **
 ** Discription: this file contains code to make the Hero, with health and a
 ** name, along with setting and describing its own attack with a weapon,
 ** getting a random weapon and getting and setting excperience from battles
 ** in game. more simply it creates the hero of the game.
 **
 ******************************************************************************/

//includes the header Hero
#include "Hero.h"

//overladed constructor that sets the name and hp from given variables and
//calls the RandomWeapon() function
Hero::Hero(string name, int hp){

  //sets variables to varibles given
  m_name = name;
  m_health = hp;

  //calls random weapon
  RandomWeapon();
}

//destructor destroys the m_weapon pointer
Hero::~Hero(){

  delete m_weapon;


}

//desplays attack of the hero to player and returns its base damage
int Hero::Attack(){

  cout<<"You punch and do "<<WEAPON_BASE<<" to the enemy."<<endl;

  return WEAPON_BASE;

}

//Gives out the name of the hero when the function is called
string Hero::GetName(){return m_name;}

//sets the name of the hero when the function is called with the given variable
void Hero::SetName(string name){m_name = name;}

//Gives out the hp of the hero when the function is called
int Hero::GetHealth(){return m_health;}

//sets the health of the hero when the function is called with the given variable
void Hero::SetHealth(int hp){m_health = hp;}

//Gives out the experience of the hero when the function is called
int Hero::GetExperience(){return m_experience;}

//sets the experience of the hero when the function is called with the given variable
void Hero::SetExperience(int exp){m_experience = exp;}

//creates a random for the user to use between the 3 options of plank, chainsaw, and shotgun
void Hero::RandomWeapon(){

  //creates an integer of 0-2
  int choice = rand()% 3;

  //if 0 is made then plank is the weapon
  if(choice  == 0){

    m_weapon = new Plank(WEAPON_BASE);

    //if 1 is made then chainsaw is the weapon
  }else if(choice == 1){

    m_weapon = new Chainsaw(WEAPON_BASE);

    //if 2 is made then shotgun is the weapon
  } else if (choice == 2){

    m_weapon = new Shotgun(WEAPON_BASE);

  }


  //gets the name of the weapon chosen
  m_weapon -> GetName();
  
}

//improves the damage of the weapon and decreases the exp of the hero
void Hero::ImproveWeapon(int exp){

  //gets the damager of the weapon and adds one to it
  int v = m_weapon->GetDamage() +1;

  //places the variable to the weapons improve weapon function
  m_weapon->ImproveWeapon(v);

  //subtracts 3 from exp
  exp = exp -3;

  //sets exp to the new exp value
  m_experience = exp;
 

}

//returns the hero's weapons special attack
int Hero::SpecialAttack(){

  return m_weapon->SpecialAttack();
}

//gets the name of the heros weapon
string Hero::GetWeaponName(){

  return  m_weapon->GetName();

}

//overloaded operator that places the hero's health and name into os then returning os
ostream& operator<<(ostream& os, Hero& hero){

  os<<hero.GetName()<<" Health: "<<hero.GetHealth();

  return os;

}
