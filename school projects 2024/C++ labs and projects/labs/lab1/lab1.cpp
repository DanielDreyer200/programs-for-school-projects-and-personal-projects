/*
  File: Lab1.cpp
  project: CMSC 202 Lab 1, fall 2024
  Author: Daniel Dreyer
  Date: 9/4/2024
  Section: 1
  Email: ddreyer1@@umbc.edu

  this file is the lab 1 main function.
  this program asks the users name and age of there dog
  and allows them to chose todo 1 of the 3 different actions
  at 3 different times. before ending while calling them a good owner.

  

*/
#include <iostream>

#include <string>

using namespace std;


//main function

int main(){

  //varriables astablised to be used throughout the program
 
  int i=0;

  int choice;
  
  int age;

  string  Dog;

  //asks user for dogs name and stores there answer
  cout << "What is your dogs name?" << endl;

  getline(cin, Dog);

  //asks users their dogs age and stores the answer

  cout << "enter your dogs age:" << endl;

  cin >> age;

  //when the age is above 25 or below 0 the while statments here will clear
  //the age value entered and ask for a number between 0-25

  while (25< age){

    cout <<"please enter an age between 0-25" << endl;

    cin.clear();
    cin.ignore(256, '\n');
    cin >> age;
    
  }while(age < 0){

    cout <<"please enter an age between 0-25" << endl;

    cin.clear();
    cin.ignore(256, '\n');
    cin >> age;

  }

  //start of next while loop that will help with
  //counting number of times the user has done an
  //activityby incrimenting i by 1 till it reaches 3

  while(i< 3){

    cout <<"choose an activity to do with your dog: \n1. Play fetch with " << Dog <<"\n2. Feed "<< Dog<<"\n3.Pet "<<Dog<<endl;

  cin >> choice;

  //after they make there selection each if statment
  //looks down the list to see if it was a number
  //between 1-3, if it was it will play inact the specified
  //selection and respond accordingly, and incroment i by 1

  if(choice == 1){

    cout << Dog << " picked up the stick and returns to you!" << endl;
    i++;
    
  }else if(choice == 2){


    cout <<"You feed " << Dog << "!" << endl;
    i++;

  }else if(choice == 3){

    cout << Dog << " is happy you pet them!" << endl;
    i++;

  //if the user types the wrong number an error message accures and asks them to try again
    
  }else{

    cout<<"im sorry, thats not a list from our selection, can you try again?" << endl;
    
  }
}
  //tells the user there a great owner and ends the program

  cout<<"you are a good pet owner to "<< Dog <<" keep it up!"<< endl;




}
