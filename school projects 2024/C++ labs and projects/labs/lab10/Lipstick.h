// File: Lipstick.h
// Desc: This is one of the child classes for lab 10
// Date: 8/28/2024
// Author: Laboni Goswami

#ifndef LIPSTICK_H
#define LIPSTICK_H
#include "Cosmetic.h"
#include <iostream>
using namespace std;

class Lipstick : public Cosmetic {
public:
  // Constructor
  // Preconditions: None
  // Postconditions: None
  Lipstick();
  
  // Destructor
  // Preconditions: None
  // Postconditions: None
  ~Lipstick();
  
  // Overloaded Constructor
  // Preconditions: None
  // Postconditions: Member variables initialized
  Lipstick(string brand, string name, string shade);
  
  // DescribeMe() - gives description of given lipstick
  // Preconditions: has a brand, name, and shade
  // Postconditions: None
  void DescribeMe();
  
  // ApplyMe() - applies the lipstick
  // Preconditions: None
  // Postconditions: None
  void ApplyMe();
private:
  string m_brand; //Brand of Lipstick
  string m_name; //Name of Lipstick
  string m_shade; //Shade (color) of Lipstick
};

#endif

