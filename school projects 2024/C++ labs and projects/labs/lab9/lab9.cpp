#include "Organism.h" //Parent class
#include "Raven.h" //Child class 1
#include "Sunflower.h" //Child class 2
#include <time.h> //For seeding random number
#include <cstdlib> //For srand and rand
using namespace std;

int main() {
  srand(time(NULL)); //Seeds random number generator
  string PREY[3] = {"Beetle", "Caterpillar", "Lizard"}; //List of prey for Raven class
  
  //Parent class example
  cout << "Parent Class Example" << endl;
  Organism myOrganism("Canis lupus familiaris", "Consumer"); //Creates organism
  myOrganism.Description(); //Calls parent class function
  cout << "****END****" << endl << endl;

  //Child class example 1
  cout << "Child Class Example (Raven)" << endl;
  Raven myRaven("Corvus corax", "Consumer", PREY, 3.3);
  myRaven.Description(); //Calls parent class function (use)
  myRaven.Hunt(); //Calls child class function (extend)
  cout << "****END****" << endl << endl;

  //Child class example 2
  cout << "Child Class Example (Sunflower)" << endl;
  Sunflower mySunflower("Helianthus annuus", "Producer", "Yellow");
  mySunflower.Description(); //Calls child class function (replace)
  mySunflower.Organism::Description(); //calls parent class function (use)
  cout << "****END****" << endl << endl;
  
  return 0;
}
