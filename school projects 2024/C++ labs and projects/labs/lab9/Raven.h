/*
* Raven.h - 
* Implement Raven.cpp
*/

#ifndef RAVEN_H //Header Guard
#define RAVEN_H //Header Guard
#include "Organism.h" //Parent class
#include <iostream>
#include <string>
using namespace std;

//constants
const int PREYLISTSIZE = 3; //The prey array will only be 3 elements big

class Raven : public Organism {
public:
  Raven(); //Default constructor
  Raven(string, string, string*, double); //Species, FoodChainLevel, wingSpan and prey
  void Hunt(); //Picks a random string out of the m_prey array and
  //             use that to print out the output according to sample output
  string *GetPrey();              //Getter for m_prey
  double GetWingSpan();           //Getter for m_wingSpan
  void SetPrey(string*);         //Setter for m_prey
  void SetWingSpan(double);       //Setter for m_wingSpan
private:
  string *m_prey;             //Array of prey
  double m_wingSpan;          //Wingspan in ft
};

#endif
