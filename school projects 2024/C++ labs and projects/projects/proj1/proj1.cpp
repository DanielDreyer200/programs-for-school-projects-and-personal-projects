/*****************************************************************
** File:    Proj1.cpp
** Project: 202 Project 1, fall 2024
** Author:  Daniel Dreyer
** Section: 10/1063
** E-Malil: ddreyer1@umbc.edu
**
** Discription: this file contains the main driver function of the
** project and 5 other functions for project 1. this program allows
** the user to choose between 4 options, 1. opens a file the user
** enters, 2. displays the immage of a submitted file to the user,
** 3. plays a game of spot the difference with the users inputted
** picture comparing it to the input of an augmented picture that
** changes 1 value in the picture, 4. ends the program.
**
******************************************************************/



#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <cstdlib>


using namespace std;


//decliration of global constant row as a constant used throughout program
const int row = 10;

//decliration of global constant col as a constant used throughout program

const int col =21;

//global constant for inputstream and picture for file loading capibilities
ifstream inputstream;
string picture;

//string global 2D array used to stor images constantly throught program
string file[row][col]={"  "};

//uploadimage
//resives input from user to get file, and places it in an array
int uploadimage(string picture);

//DisplayArt
//takes users image that was in array and displays it to the user
int DisplayArt();

//changeValue
//creates a character that is then placed in the submitted image displaying it
//back to user
int changeValue();

//check
//has user guess which area the change occured and responds if user is right or not
void check(int x, int y);

//clearArry
//clears the array and replaces everything with a space
int clearArry();

//main
//runs the function that allows user to interact with program
int main(){

  //variable in main
  int choice =0;

  //do- while with switch to allow for replication till user is ready to exit  
    do{
      
      switch(choice){
      case 0:{

	//displays menu to user and lets them choose an option
	cout<<"Please Choose 1 Option\n1. Open File\n2.Display Art\n3.Play Game\n4.Exit"<<endl;


        cin >> choice;

	//if users option is above 5 it will make them choose another
	if(int(choice) < 5){

	choice = choice;
	  
	}else{

	cout<<"invalid selection please try again"<<endl;

	choice=0;
	} 

	
	break;
      }case 1:{

	 //asks for file name to place globle constant as
	  cout<<"enter a file:"<<endl;

	  cin>>picture;

	  uploadimage(picture);

	  //if file is opened program will run otherwise it will show error message
	  if(inputstream.is_open()){

	    DisplayArt();

	  }else{

	    cout << "Unable to open file"<<endl;

	    
	  }  

	  choice = 0;


	  break;
       }case 3:{


	  //displays users image with that of the changed image
	  
	  //if file is opened program will run otherwise it will show error message
	  if(inputstream.is_open()){

	    DisplayArt();
	    
	    changeValue();
 
	  }else{

	    cout << "Unable to open file"<<endl;
	   
	  }
 
	  choice = 0;

	  break;


	}case 2:{

	   //displays users image
	   
	   //if file is opened program will run otherwise it will show error message
	   if(inputstream.is_open()){

	     DisplayArt();

	   }else{

	     cout << "Unable to open file"<<endl;
	   }
	  
	   choice = 0;
	   break;


	 }case 4:{

	    //changes value of choice to be over the amount allowing for program to end
	    choice= 5;


	break;


	  }

      }
      
    }while(choice <5);

      
 
}

//uploadimage
//resives input from user to get file, and places it in an array
int uploadimage(string picture){

  clearArry();

  //variables in uploadimage
  int x,y;
  string shape;

  //opens users image
  inputstream.open(picture);  

  //places users image in array
  while(inputstream >> x){
    inputstream >> y >> shape;


    file[x][y] = string(shape);

    
  }

  return 0;
}
//DisplayArt
//takes users image that was in array and displays it to the user
int DisplayArt(){

  //puts array in a visual format to display back to user
  cout<<"   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20"<<endl;
    for(int i= 0;i<row;i++){

      cout<<i;

      for(int t=0;t<col;t++){

	cout<<"  "<<file[i][t];

      }

      cout<<endl;

    }
  
  return 0;

}

//changeValue
//creates a character that is then placed in the submitted image displaying it
//back to user
int changeValue(){

  
  
  //variables used in changeValue
  char ch;
  int random;

  int x,y;

  //creates a random variable between 33 and 126
  srand(time(0));

  random = (rand() % 93)+33;

  //places a random variable between 0-10 for x
  x= rand() % 10;
  //places a random variable between 0-21 for y
  y= rand() % 21;

  //changes variable random to its character counterpart
  ch = char(random);

  //places the new character in the array at the x and y variable
  file[x][y] = ch;

  //displays the changed version of the array to user
  cout<<"   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20"<<endl;
  for(int i= 0;i<row;i++){

    cout<<i;

    for(int t=0;t<col;t++){
 
      cout<<"  "<<file[i][t];

    }

    cout<<endl;

  }
  //calls the check function placing the value for x and y in it
  check(x,y);
  
  return 0;

}

//check
//has user guess which area the change occured and responds if user is right or not
void check(int x, int y){

  //variables in check
  int rowx;

  int coly;

  //asks the user for the row they think the change is in
  cout<<"what is change in the row?"<<endl;

  cin>>rowx;

  //asks the user for the collum they think the change is in
  cout<<"what is the change in the column?"<<endl;

  cin>>coly;

  //if statment that checks to see if there guess is correct, if not asks them again
  if(rowx == x && coly ==y){

      cout<<"Correct!"<<endl;

      //calls upload picture to reinstate the original picture
      uploadimage(picture);
      
    }else{

      cout<<"Try Again"<<endl;

      //allows for check to run again
      check(x,y);
    }
    
}

//clearArry
//clears the array and replaces everything with a space
int clearArry(){

  //closes the file
  inputstream.close();

  //changes the array to be just spaces again
  for(int i= 0;i<row;i++){

    for(int t=0;t<col;t++){

      file[i][t]={" "};

    } 
  }

  return 0;
}
