#include "Lipstick.h"

Lipstick::Lipstick(){

  m_brand = nullptr;
  m_name = nullptr;
  m_shade = nullptr;
  
  
}
Lipstick::~Lipstick(){

  delete &m_brand;
  delete &m_name;
  delete &m_shade;
  
}
Lipstick::Lipstick(string brand, string name, string shade){

  m_brand = brand;
  m_name = name;
  m_shade = shade;

}

void Lipstick::DescribeMe(){

}

void Lipstick::ApplyMe(){

  
}
