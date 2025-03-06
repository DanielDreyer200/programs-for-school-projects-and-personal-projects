/*
* Sunflower.h - 
* Implement Sunflower.cpp
*/

#ifndef SUNFLOWER_H //Header Guard
#define SUNFLOWER_H //Header Guard
#include "Organism.h" //Parent class
#include <iostream>
#include <string>
using namespace std;

class Sunflower : public Organism {
public:
  Sunflower(); //Default constructor
  Sunflower(string, string, string);//Species, FoodChain, and petalColor
  void Description(); //Using m_petalColor, displays Sunflower desc to match the sample output
                      //Replacing parent class function
  string GetPetalColor();     //Getter for m_petalColor
  void SetPetalColor(string); //Setter for m_petalColor
private:
  string m_petalColor; //String holds color of the petals
};
#endif
