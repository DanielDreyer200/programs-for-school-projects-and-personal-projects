/* Title: lab11a.cpp
   Course: CMSC 202 - Fall 2024
   Description: This introduces templated functions.
*/
#include <iostream>
using namespace std;

// COMPLETE THIS FUNCTION
template <class T, class V>
int compare(T first, V second) {

  if(first>second){

    return 1;
    
  }else if (first<second){

    return -1;
  }else if(first == second){

    return 0;
  }
  
  // The function should return:
  // 1 if first is greater than second
  // -1 if first is less than second
  // 0 if first and second are equal
}

int main() {
  char a = '1';
  char b = 'C';
  int c = 10;
  double d = 20.0;
  float e = 20.0f;
  
  cout << "Comparing " << a << " and " << b << ": "
       << compare(a, b) << endl;
  cout << "Comparing " << b << " and " << c << ": "
       << compare(b, c) << endl;
  cout << "Comparing " << c << " and " << d << ": "
       << compare(c, d) << endl;
  cout << "Comparing " << d << " and " << e << ": "
       << compare(d, e) << endl;
  
  return 0;
}
