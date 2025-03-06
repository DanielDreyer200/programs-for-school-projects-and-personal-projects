/*************************************************************************
 ** File:    Metro.cpp
 ** Project: 202 Project 3, fall 2024
 ** Author:  Daniel Dreyer
 ** Section: 35
 ** E-Malil: ddreyer1@umbc.edu
 **
 ** Discription: this file contains the main programing of the project
 **the file do multiple things, first it will ask for the user to pick
 **between 1. display lines- which desplays the lines of each train.
 **2. display passengers by line- displays the passengers on the train and
 **the line they are on. 3. calculates the earnings of the line- will
 **calculate how much each line earned by how many stops each person took.
 **4. will exit the program. to get all of this info tho, the program will
 **first load each file sepratly and break down each commponent and place
 **it in its respective vector.
 **
 *************************************************************************/
#include "Metro.h"
//default constructor sets variables to default perammeters, then
//loads both lines and passengers then calls main menu
Metro::Metro(){

  //veriables set to default
  m_fileLines = " ";
  m_filePass = " ";
  
  //loads the lines and passengers of the files
  LoadLines();
  LoadPasses();

  //calls mainmenu
  MainMenu();
}

//overloaded constructor will take the 2 files given and place the varible
//into its header variables, load lines and passengers then loads main menu
Metro::Metro(string fileLine, string filePass){

  //sets header variable to given file
  m_fileLines = fileLine;
  m_filePass = filePass;

  //loads the lines and passengers of the files
  LoadLines();
  LoadPasses();

  //calls mainmenu
  MainMenu();

}
//destructor at the end of the program will break down each part of the vectors and delete them
Metro::~Metro(){

  //variables to set size
  int x = m_lines.size();
  int y = m_passengers.size();

  //for loop that deleates each value in m_passengers
  for(int i=0; i<y;i++){

    delete m_passengers[i];

  }
  
  //for loop that deletes each value in m_lines
  for(int i=0; i<x;i++){

    delete m_lines[i];

  }
  
}
//populates a vector with the given files information
void Metro::LoadLines(){

  //variable to load files
  ifstream inputstream,inputstreamcount;

  //opens the file into 2 different variables
  inputstream.open(m_fileLines);
  inputstreamcount.open(m_fileLines);

  //variables to place each portion of the file into
  string number;
  string line;
  string station;

  //variable to be used as a way of counting what line we are at in the file
  string x;

  //while loop for each line in the file
  while(getline(inputstreamcount, x, '\n')){

    //getline commands to get portions of the line and place them into appropriate variables
    getline(inputstream, number, ',');
    getline(inputstream, line, ',');
    getline(inputstream, station, '\n');

    //creates T which is a line with each iteration having the classification of what Lines states
    Line* T = new Line(line);

    //places the string version of number and station into Line AddStop function
    T->AddStop(stoi(number),station);

    //places T in vector
    m_lines.push_back(T);

    
  }
  //closes both files
  inputstream.close();
  inputstreamcount.close();
}
//populates a vector with the given files information
void Metro::LoadPasses(){

  //file variables
  ifstream inputstream, inputstreamcount;

  //opens both instances of files
  inputstream.open(m_filePass);
  inputstreamcount.open(m_filePass);

  //variables to place each portion of the file into
  string number;
  string line;
  string startLocation;
  string finalDestination;

  //variable to be used as a way of counting what line we are at in the file
  string x;

  //while loop for each line in the file
  while(getline(inputstreamcount, x, '\n')){

    //getline commands to get portions of the line and place them into appropriate variables
    getline(inputstream, number, ',');
    getline(inputstream, line, ',');
    getline(inputstream, startLocation, ',');
    getline(inputstream, finalDestination, '\n');

    //creates a new passenger with variables int of numbers, line, startlocation, finaldestination
    Passenger* P = new Passenger(stoi(number), line, startLocation, finalDestination);

    //places P in a vector
    m_passengers.push_back(P);
  }
  //closes all files
  inputstream.close();
  inputstreamcount.close();
}

//returns the index of a line based on the color accociated with it
int Metro::LineToIndex(string name){

  //if statments for each possible color the line can be, along with the corisponding number associated
  if(name == "red"){

    return 0;
    
  }else if(name == "green"){

    return 1;

  }else if(name == "blue"){

    return 2;

  }else if(name == "yellow"){

    return 3;
    
  }else if(name == "silver"){

    return 4;

  }else if(name == "orange"){

    return 5;
  }else{}

  //genaric return statment of -1 incase of error
  return -1;

}

//main menu that asks user for an option to which they will choose to
//display lines, display passengers by lines, calculate earnings by line or quit
void Metro::MainMenu(){

  //welcoms user
  cout<<"*******************************\nWelcome to the Washington DC Metro"<<endl;

  //variables used with default perameters
  int i=0;
  int c=0;

  //while i = 0 the switch statment will run
  while(i==0){

    //for any value c the default or case of the switch statment runs
    switch(c){

      //asks user what option they would like and sets it as c
    case 0:{

      cout<<"What would you like to do?:\n1. Display Lines\n2. Display Passengers by Line\n3. Calculate Earnings by Line\n4. Quit"<<endl;
      cin>>c;

      break;
      
    }

      //display lines sets c back to 0
    case 1:{

      DisplayLines();
      c=0;
      break;
    }

      //display passengers sets c back to 0
    case 2:{

      DisplayPassengers();

      c=0;
      break;
    }
      //displays caculate earnings sets c back to 0
    case 3:{

      CalcEarnings();

      c=0;
      break;
    }
      //sets i to 1
    case 4:{

      i=1;
      
      break;
    }
      //invalid input message theat then sets c =0
    default:{

      cout<<"wrong value entered please try again"<<endl;
      c=0;
      

    }


    }
  }

}
//displays lines and the corisponding stations that are associated with it
void Metro::DisplayLines(){

  //gets size of the vector
  int x =m_lines.size();

  //for red line train displays all lines to user in the correct order
  cout<<endl;
  cout<<"** RED Line Train**"<<endl;
  cout<<endl;
  for(int i = 0; i< x;i++){

    if(m_lines[i]->GetLineName() == "red"){

      m_lines[i]->PrintLineDetails();

    }
  }

  //for Green line train displays all lines to user in the correct order
  cout<<endl;
  cout<<"**GREEN Line Train**"<<endl;
  cout<<endl;
  for(int i = 0; i< x;i++){


    if(m_lines[i]->GetLineName() == "green"){

      m_lines[i]->PrintLineDetails();

    }
  }
  //for blue line train displays all lines to user in the correct order
  cout<<endl;
  cout<<"**BLUE Line Train**"<<endl;
  cout<<endl;
  for(int i = 0; i< x;i++){


    if(m_lines[i]->GetLineName() == "blue"){

      m_lines[i]->PrintLineDetails();

    }
  }
  //for yellow line train displays all lines to user in the correct order
  cout<<endl;
  cout<<"**YELLOW Line Train**"<<endl;
  cout<<endl;
  for(int i = 0; i< x;i++){


    if(m_lines[i]->GetLineName() == "yellow"){

      m_lines[i]->PrintLineDetails();

    }
  }
  //for silver line train displays all lines to user in the correct order
  cout<<endl;
  cout<<"**SILVER Line Train**"<<endl;
  cout<<endl;
  for(int i = 0; i< x;i++){


    if(m_lines[i]->GetLineName() == "silver"){

      m_lines[i]->PrintLineDetails();

    }
  }
  //for orange line train displays all lines to user in the correct order
  cout<<endl;
  cout<<"**ORANGE Line Train**"<<endl;
  cout<<endl;
  for(int i = 0; i< x;i++){


    if(m_lines[i]->GetLineName() == "orange"){

      m_lines[i]->PrintLineDetails();

    }
  }
}
//displays passengers in order of there apearence on the train, for each line
void Metro::DisplayPassengers(){

  //gets size of passenger line
  int x = m_passengers.size();

  //passengers of red line train are shown in order of apearence in the vector to user
  cout<<endl;
  cout<<"** Red Line Train**"<<endl;
  cout<<"Passengers:"<<endl;
  for(int i=0; i<x;i++){

    // uses the index to check if m_passengers line is the same as the color
    if(LineToIndex(m_passengers[i]->GetLine())== 0){

    
    m_passengers[i]->DisplayPassenger();

    }

  }
  //passengers of green line train are shown in order of apearence in the vector to user
  cout<<endl;
  cout<<"** Green Line Train**"<<endl;
  cout<<"Passengers:"<<endl;
  for(int i=0; i<x;i++){

    // uses the index to check if m_passengers line is the same as the color
    if(LineToIndex(m_passengers[i]->GetLine())== 1){


      m_passengers[i]->DisplayPassenger();

    }

  }
  //passengers of blue line train are shown in order of apearence in the vector to user
  cout<<endl;
  cout<<"** Blue Line Train**"<<endl;
  cout<<"Passengers:"<<endl;
  for(int i=0; i<x;i++){

    // uses the index to check if m_passengers line is the same as the color
      if(LineToIndex(m_passengers[i]->GetLine())== 2){


	m_passengers[i]->DisplayPassenger();

      }

  }
  //passengers of yellow line train are shown in order of apearence in the vector to user
  cout<<endl;
  cout<<"** Yellow Line Train**"<<endl;
  cout<<"Passengers:"<<endl;
  for(int i=0; i<x;i++){

    // uses the index to check if m_passengers line is the same as the color
    if(LineToIndex(m_passengers[i]->GetLine())== 3){


      m_passengers[i]->DisplayPassenger();

    }

  }
  //passengers of silver line train are shown in order of apearence in the vector to user
  cout<<endl;
  cout<<"** Silver Line Train**"<<endl;
  cout<<"Passengers:"<<endl;
  for(int i=0; i<x;i++){

    // uses the index to check if m_passengers line is the same as the color
    if(LineToIndex(m_passengers[i]->GetLine())== 4){


      m_passengers[i]->DisplayPassenger();

    }

  }
  //passengers of orange line train are shown in order of apearence in the vector to user
  cout<<endl;
  cout<<"** Orange Line Train**"<<endl;
  cout<<"Passengers:"<<endl;
  for(int i=0; i<x;i++){

    // uses the index to check if m_passengers line is the same as the color
    if(LineToIndex(m_passengers[i]->GetLine())== 5){


      m_passengers[i]->DisplayPassenger();

    }

  }
  
}
//calculates the earnings of each line based on the amount of stops the passengers take
void Metro::CalcEarnings(){

  //gets size of each vector
  int x=m_passengers.size();
  int y=m_lines.size();

  //variables for each total of each line
  int rtotal = 0;
  int gtotal = 0;
  int btotal= 0;
  int ytotal= 0;
  int stotal= 0;
  int ototal=0;

  //value to represent the distance between stops
  int d;
  //for loops to iterate through each vector in there entirety comparing to one another
  for(int t = 0; t<x;t++){

    for(int i = 0; i< y;i++){

      //gets the start and end of each m_passages
      string start = m_passengers[t]->GetStartLocation();

      string end = m_passengers[t]->GetFinalDestination();


      //sets m_lines to the calculate function with the start and end of the m_passengers vector and places the value in d
      d = m_lines[i]->CalculateDistance(start,end);


      //if d<0 then it is disregarded
      if(d<0){

	//else it takes d and checks if both the m_lines name and m_passengers line are
	//both the same color then adds d to the total each time that color is
	//brought up for both vectors
      }else{

	//if statment for red line and red line passengers
	if(m_passengers[t]->GetLine()== "red" && m_lines[i]->GetLineName()== "red"){

	    rtotal += d;

	    //if statment for green line and green line passengers
	}if(m_passengers[t]->GetLine()== "green"&& m_lines[i]->GetLineName()== "green"){

	    gtotal += d;

	    //if statment for blue line and blue line passengers
	}if(m_passengers[t]->GetLine()== "blue"&& m_lines[i]->GetLineName()== "blue"){

	    btotal += d;

	    //if statment for yellow line and yellow line passengers
	}if(m_passengers[t]->GetLine()== "yellow"&& m_lines[i]->GetLineName()== "yellow"){

	    ytotal += d;

	    //if statment for silver line and silver line passengers
	}if(m_passengers[t]->GetLine()== "silver"&& m_lines[i]->GetLineName()== "silver"){

	    stotal += d;

	    //if statment for orange line and orange line passengers
	}if(m_passengers[t]->GetLine()== "orange"&& m_lines[i]->GetLineName()== "orange"){

	    ototal += d;

	  }
	
      }
      
    }
  }

 
  //sets a fixed percision, making any variable that can go to .00 to .00
  cout<<fixed<<setprecision(2)<<endl;
  //desplays details for red line train's total and total stops
  cout<<"** Red Line Train**"<<endl;
  cout<<"total Earnings: $"<<rtotal*PER_STOP<<endl;
  cout<<"total stops is: "<<rtotal<<endl;

  //desplays details for green line train's total and total stops
  cout<<endl;
  cout<<"** Green Line Train**"<<endl;
  cout<<"total Earnings: $"<<gtotal*PER_STOP<<endl;
  cout<<"total stops is: "<<gtotal<<endl;

  //desplays details for blue line train's total and total stops
  cout<<endl;
  cout<<"** Blue Line Train**"<<endl;
  cout<<"total Earnings: $"<<btotal*PER_STOP<<endl;
  cout<<"total stops is: "<<btotal<<endl;

  //desplays details for yellow line train's total and total stops
  cout<<endl;
  cout<<"** Yellow Line Train**"<<endl;
  cout<<"total Earnings: $"<<ytotal*PER_STOP<<endl;
  cout<<"total stops is: "<<ytotal<<endl;

  //desplays details for silver line train's total and total stops
  cout<<endl;
  cout<<"** Silver Line Train**"<<endl;
  cout<<"total Earnings: $"<<stotal*PER_STOP<<endl;
  cout<<"total stops is: "<<stotal<<endl;

  //desplays details for orange line train's total and total stops
  cout<<endl;
  cout<<"** Orange Line Train**"<<endl;
  cout<<"total Earnings: $"<<ototal*PER_STOP<<endl;
  cout<<"total stops is: "<<ototal<<endl;
}
