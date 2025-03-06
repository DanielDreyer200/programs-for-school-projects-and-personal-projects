#include "Organism.h"

Organism::Organism(){}
Organism::Organism(string species, string FoodChainLevel){

  m_species = species;
  m_foodChainLevel = FoodChainLevel;
  

}

void Organism::Description(){

  
  cout<<"The "<<GetSpecies()<<" is a "<<GetFoodChainLevel()<<endl;
    

}
string Organism::GetSpecies(){return m_species;

}
string Organism::GetFoodChainLevel(){return m_foodChainLevel;}     //Getter for m_foodChainLevel
void Organism::SetSpecies(string species){m_species = species;}        //Setter for m_species
void Organism::SetFoodChainLevel(string FoodChainLevel){m_foodChainLevel = FoodChainLevel;}
