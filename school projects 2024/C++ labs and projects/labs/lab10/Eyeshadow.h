// File: Eyeshadow.h
// Desc: This is one of the child classes for lab 10
// Date: 8/28/2024
// Author: Laboni Goswami

#ifndef EYESHADOW_H
#define EYESHADOW_H
#include "Cosmetic.h"
#include <iostream>
using namespace std;

class Eyeshadow : public Cosmetic {
public:
  // Constructor
  // Preconditions: None
  // Postconditions: None
  Eyeshadow();
  
  // Destructor
  // Preconditions: None
  // Postconditions: None
  ~Eyeshadow();
  
  // Overloaded Constructor
  // Preconditions: None
  // Postconditions: Member variables initialized
  Eyeshadow(string brand, string palette, string shade);
  
  // DescribeMe() - gives description of given eyeshadow
  // Preconditions: has a brand, palette, and shade
  // Postconditions: None
  virtual void DescribeMe();
  
  // ApplyMe() - applies eyeshadow
  // Preconditions: None
  // Postconditions: None
  virtual void ApplyMe();
  
private:
  string m_brand; //Brand of Eyeshadow
  string m_palette; //Palette of Eyeshadow
  string m_shade; //Shade of Eyeshadow
};

#endif
