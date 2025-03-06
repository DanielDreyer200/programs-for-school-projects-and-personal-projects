// File: lab10.cpp
// Desc: This is a lab illustrating polymorphism in C++
// Date: 8/28/2024
// Author: Laboni Goswami

#include "Cosmetic.h"
#include "Lipstick.h"
#include "Eyeshadow.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

  // Instantiation of child objects
  Lipstick lipstick1("MAC", "Frost", "Angel");
  Eyeshadow eyeshadow1("Pat McGrath", "Mothership VI: Midnight Sun", "Blitz Violet Orchid");
  
  // Cosmetic Pointers to child objects (Polymorphism)
  Cosmetic* lipstick1Ptr = &lipstick1;
  Cosmetic* eyeshadow1Ptr = &eyeshadow1;
  
  // Lipstick functions calls
  lipstick1Ptr -> PrintType();
  lipstick1Ptr -> DescribeMe();
  lipstick1Ptr -> ApplyMe();
  
  cout << endl;
  
  // Eyeshadow function calls
  eyeshadow1Ptr -> PrintType();
  eyeshadow1Ptr -> DescribeMe();
  eyeshadow1Ptr -> ApplyMe();
  
  return 0;
}

