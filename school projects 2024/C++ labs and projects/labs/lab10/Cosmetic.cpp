#include "Cosmetic.h"

Cosmetic::Cosmetic(){
  m_type =nullptr;
}
Cosmetic::~Cosmetic(){


  delete &m_type;
  
}
void Cosmetic::PrintType(){

cout<<"hi"<<endl;
}
string Cosmetic::GetType(){

  return m_type;
}

void Cosmetic::SetType(string type){m_type = type;}

void Cosmetic::DescribeMe(){

}
void Cosmetic::ApplyMe(){

}
