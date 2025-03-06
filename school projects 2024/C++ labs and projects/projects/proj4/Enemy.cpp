/******************************************************************************
 ** File:    Enemy.cpp
 ** Project: 202 Project 4, fall 2024
 ** Author:  Daniel Dreyer
 ** Section: 35
 ** E-Malil: ddreyer1@umbc.edu
 **
 ** Discription: this file creates the enemy parent class for the program,
 ** it is the parent tot the enemys in the program, it will create an enemy with
 ** name, hp damage and description, creates a random attack chance for it to be
 ** a special attack.
 **
 ******************************************************************************/
//include enemy.h file
#include "Enemy.h"

//creates an enemy with a name, hp, damage and desc,  these variables are then
//placed into the subsequent variables associated
Enemy::Enemy(string name, int hp, int damage, string desc){

  m_name = name;
  m_health = hp;
  m_damage = damage;
  m_desc = desc;

  
}
//destructor that is needed for child classes
Enemy::~Enemy(){

}

//gives a 25% chance to have the enemy attack with a special attack,
//otherwise just hitting with a regular attack
int Enemy::Attack(){

  //creates a random number between 0 to 3
  int v = rand() % 4;

  //if it is 0 then special attack is called
  if(v == 0){

    
    return SpecialAttack();
    

    //if anything else is picked sesplay to user that the creature attacks, then returns damage
  }else{

    cout<<GetName()<<" Attacks!"<<endl;
    
    return m_damage;

  }
}

//will give name of enemy when called
string Enemy::GetName(){return m_name;}

//will geyt health of enemy when called
int Enemy::GetHealth(){return m_health;}

//will set helath to the given hp value
void Enemy::SetHealth(int hp){m_health = hp;}

//will get damage of enemy when called
int Enemy::GetDamage(){return m_damage;}

//will get description of enemy when called 
string Enemy::GetDesc(){return m_desc;}

//makes an operator of os that places the name of enemy and
//the health and the damage to the eenmy and returns that os
ostream&  operator<<(ostream& os, Enemy& enemy){

  os << enemy.GetName()<<": Health: "<<enemy.GetHealth()<<" Damage: "<<enemy.GetDamage()<<endl;

  return os;
}
