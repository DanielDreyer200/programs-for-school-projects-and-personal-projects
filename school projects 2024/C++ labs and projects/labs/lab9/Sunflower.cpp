#include "Sunflower.h"


Sunflower::Sunflower(){} //Default constructor
Sunflower::Sunflower(string species, string FoodChainLevel, string petalColor){

  SetSpecies(species);

  SetFoodChainLevel(FoodChainLevel);
  
  m_petalColor = petalColor;
}
				  
void Sunflower::Description(){
  cout<<"the sunflower is "<<GetPetalColor()<<" petals this spring!"<<endl;
  

} //Using m_petalColor, displays Sunflower desc to	\
		    match the sample output
//Replacing parent class function
string Sunflower::GetPetalColor(){ return m_petalColor;}     //Getter for m_petalColor
void Sunflower::SetPetalColor(string petalColor){ m_petalColor = petalColor;}
