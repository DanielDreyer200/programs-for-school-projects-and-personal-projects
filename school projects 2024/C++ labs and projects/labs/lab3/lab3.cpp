/*****************************************
 ** File:    lab3.cpp
 ** Project: CMSC 202 Lab 3, Fall 2023
 **
 ** Lab 3 involves using arrays. In this file you need to
 ** implement the IsUnique() and getLargestNum() functions 
 ***********************************************/

#include <iostream>
using namespace std;

//Global Constants
const int NUM_NUMBERS = 4; //Size of array and count of numbers to read

// Function Name: isUnique
// Pre-conditions: Requires a new number, and an array of numbers
// Post-conditions: Returns true if the new number is not in the array, else false
bool isUnique(int, int[]);




// Function Name: getLargestNum
// Pre-conditions: Requires an array
// Post-conditions: Returns the largest number in the array
int getLargestNum(int[]);

// Implement main HERE*********
int main() {
  // Declare your necessary variable(s)

  
  
  // Declare array (myArray)

  int myarry[]={0];
  
  // Populate Array with unique, non-zero numbers from user for size NUM_NUMBERS

  

  
    //if the input is 0, notifies user and re-prompts

    //if the input is not unique (already in array), notifies user and re-prompts

    //Otherwise, adds to the array

  
  //Iterate through array and display all numbers (not sorted)

  
  //Display largest number in array using getLargestNum


  
  return 0;
}


// Implementation of function that checks input uniqueness (true if unique else false)
// isUnique is provided
bool isUnique(int input, int array1[]){

  //parses through array and checks if passed value exists in array already
  for (int i = 0; i < NUM_NUMBERS; i++){
    if (input == array1[i])
      return false;
  }
  return true;
}

// Implement getLargestNum here
// Function that returns the largest number in an array

