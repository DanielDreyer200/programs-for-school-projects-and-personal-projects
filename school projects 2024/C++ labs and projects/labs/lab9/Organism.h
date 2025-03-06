/*
* Organism.h - 
* Implement Organism.cpp
*/

#ifndef ORGANISM_H //Header guard
#define ORGANISM_H //Header guard
#include <iostream>
#include <string>
using namespace std;

class Organism {
public:
  Organism(); //Default constructor
  Organism(string, string); //Species and FoodChainLevel
  void Description(); //Using the member variables, write a brief description
  string GetSpecies();            //Getter for m_species
  string GetFoodChainLevel();     //Getter for m_foodChainLevel
  void SetSpecies(string);        //Setter for m_species
  void SetFoodChainLevel(string); //Setter for m_foodChainLevel
private:
  string m_species;        //Organism's species classification
  string m_foodChainLevel; //Producer/Consumer/Decomposer
};

#endif //Header guard
