/*****************************************
 ** File:    lab4.cpp
 ** Project: CMSC 202 Lab 4, Fall 2024
 **
 ** Lab 4 involves passing data to void functions
 ** by reference and by using pointers.
 **
 ***********************************************/
#include<iostream>
using namespace std;

// Write One Constant:
// CONVERTER - Converts centimeters to meters and meters to centimeters
const int CONVERTER = 100;

// Write two Function Prototypes for two functions described
void  toMeters(double &length);
void  toCentimeters(double *pointlength);

//Main is provided
int main(){
  double length = 0.0; // Input for converting
  int choice = 0; // Menu choice

  cout << "Welcome to Length Conversion tool " << endl;
 
  do {
    cout << "Please select below: " << endl;
    cout << "1. Convert from centimeters to meters" << endl;
    cout << "2. Convert from meters to centimeters" << endl;
    cout << "3. Exit"<< endl;
    cin >> choice; 
    
    // Check for validation
    if (choice < 1 || choice > 3) {
      while (choice < 1 || choice > 3) {
        cout << "\nInvalid selection. Please re-enter: " << endl;
        cin >> choice;
      }
    }
    if (choice == 1){
      cout<<"\nLength in centimeters: " ;
      cin >> length;
      toMeters(length); //function call
      cout << "Length in meters: " << length << endl;
    }
    
    if (choice == 2){
      cout<<"\nLength in meters: " ;
      cin >> length;
      toCentimeters(&length); //function call
      cout << "Length in centimeters: " << length << endl;
    }
    
    cout << endl;
    
  }while(choice != 3);
  cout << "Have a good one!" << endl;  
  return 0;
}

// Write function toMeters here
// Convert from centimeters to meters using pass by reference

void toMeters(double &length){

  
  length = length/CONVERTER;

  
  
}





// Write function toCentimeters here
// Convert from meters to centimeters using pointers


void toCentimeters(double *pointlength){

  
  

  
  *pointlength = *pointlength *CONVERTER;
  
 
}
