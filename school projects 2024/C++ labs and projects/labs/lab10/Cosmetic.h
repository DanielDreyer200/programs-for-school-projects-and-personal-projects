// File: Cosmetic.h
// Desc: This is the parent class for lab 10
// Date: 8/28/2024
// Author: Laboni Goswami

#ifndef COSMETIC_H
#define COSMETIC_H
#include <iostream>
using namespace std;

class Cosmetic {
public:
  // Constructor
  // Preconditions: None
  // Postconditions: None
  Cosmetic();
  
  // Destructor
  // Preconditions: None
  // Postconditions: None
  ~Cosmetic();
  
  // printType() - Prints object's type
  // Preconditions: Object exists
  // Postconditions: Object's type is printed
  virtual void PrintType();
  
  // getType() - returns type
  // Preconditions: type is initialized
  // Postconditions: None
  string GetType();
  
  // setType() - sets value of type
  // Preconditions: None
  // Postconditions: None
  void SetType(string type);
  
  // describeMe() - gives description of the cosmetic
  // Preconditions: None
  // Postconditions: None
  virtual void DescribeMe() = 0; // <- Declares as purely virtual function
  
  // applyMe() - applies the cosmetic
  // Preconditions: Object exists
  // Postconditions: None
  virtual void ApplyMe() = 0; // <- Declares as purely virtual function
  
private:
  string m_type; //Type of Cosmetic
};

#endif
