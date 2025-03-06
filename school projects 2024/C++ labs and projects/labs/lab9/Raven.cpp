#include "Raven.h"
//#include "Organism.h"

Raven::Raven(){

  m_prey = nullptr;
  m_wingSpan = 0;
  
}
Raven::Raven(string species, string FoodChainLevel, string* prey, double wingspan){

  SetSpecies(species);
  SetFoodChainLevel(FoodChainLevel);
  m_wingSpan = wingspan;
  m_prey = prey;

} 



				   
void Raven::Hunt(){

  int choice = rand() %3;

  cout<<"The Raven eats a "<<m_prey[choice]<<" with its "<<GetWingSpan()<<"ft. wingspan!"<<endl;
    } 
string *Raven::GetPrey(){return m_prey;}           
double Raven::GetWingSpan(){return m_wingSpan;}          
void Raven::SetPrey(string* prey){ m_prey = prey;}         
void Raven::SetWingSpan(double wingspan){m_wingSpan = wingspan;}
