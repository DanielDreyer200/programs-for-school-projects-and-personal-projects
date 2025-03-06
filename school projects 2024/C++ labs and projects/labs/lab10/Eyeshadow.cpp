#include "Eyeshadow.h"

Eyeshadow::Eyeshadow(){

  m_brand = nullptr;
  m_palette = nullptr;
  m_shade = nullptr;
  
}

Eyeshadow::~Eyeshadow(){

  delete &m_brand;
  delete &m_palette;
  delete &m_shade;

}

Eyeshadow::Eyeshadow(string brand, string palette, string shade){

  m_brand = brand;
  m_palette = palette;
  m_shade = shade;

}
void Eyeshadow::DescribeMe(){

  cout<<"hi"<<endl;
  
}
void Eyeshadow::ApplyMe(){

}
