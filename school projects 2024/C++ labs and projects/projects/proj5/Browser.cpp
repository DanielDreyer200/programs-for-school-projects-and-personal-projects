/*************************************************************************
 ** File:    Browser.cpp
 ** Project: 202 Project 5, fall 2024
 ** Author:  Daniel Dreyer
 ** Section: 35
 ** E-Malil: ddreyer1@umbc.edu
 **
 ** Discription: this class defines the information the user interacts
 ** with, it creates the browser and loads the given file into the browser,
 ** it allows user to display the current browser history, go forward to
 ** the next website in the browser history, go back to a different website
 ** in the browser history, allows user to go to a new website including
 ** the given input at the exact timestamp they visited, and finally
 ** exits the program.
 **
 *************************************************************************/

//includes the header file of the browser
#include "Browser.h"

//overloaded constructor, sets the stored file name to the value given and sets current page ti null
Browser::Browser(string filename){

  m_fileName = filename;

  m_currentPage = nullptr;

}

//dealocates the values of the backstack and forwardstack and current page
Browser::~Browser(){

  //when backstack is not empty it deletes what is poped from backstack
  while(!m_backStack.IsEmpty()){

    //gives the data of the backstack's top and deletes the value,
    //the pop will set to next value in backstack
    delete m_backStack.Pop();

  }
  //when forwardstack is not empty it deletes what is poped from forwardstack
  while(!m_forwardStack.IsEmpty()){

    //gives the data of the forwardstack's top and deletes the value,
    //the pop will set to next value in forwardstack
    delete m_forwardStack.Pop();

  }
  //deletes the current page
  delete m_currentPage;
   
}
//loads file and then loads menu
void Browser::StartBrowser(){

  //calls load file 
  LoadFile();

  //calls menu
  Menu();
}

//creates menu that gives user 4 options, display browser history, go back,
//go forward, visit site and then quits, all on users input
void Browser::Menu(){

  //sets variables to 0 
  int i = 0;
  int option =0;

  //while i is 0 itterate though the commands
  while (i==0){

    //switch statment to show each value form the user to the value they chose
    switch(option){

      //desplays menu to user and places there choice to option
    case 0:{

      //displays current page to user
      cout<<"Current Website:"<<endl;
      cout<<*m_currentPage<<endl;
      cout<<endl;

      //tells user the options
      cout<<"What would you like to do? \n1. DisplayBrowser History\n2. Go Back\n3. Go Forward\n4. Visit Site\n5. Quit"<<endl;

      //sets users choice to option
      cin>>option;


      
      break;

    }
      //if 1 calls desplay and sets option to 0
    case 1:{

      Display();

      option =0;

      break;

    }
      //if 2 calls Back with value 1 and sets option to 0
    case 2:{

      Back(1);

      option =0;

      break;

    }
      //if 3 calls forward with value 1 and sets option to 0
    case 3:{

      Forward(1);

      option =0;

      break;

    }
      //if 4 calls NewVisit and sets option to 0
    case 4:{

      NewVisit();

      option =0;

      break;

    }
      //if 5 says end message and sets i to 1
    case 5:{

      cout<<"Ending Browser History Simulator"<<endl;

      i=1;
      break;
    }
      //if wrong input then tells user to try again and sets option to 0
    default:{

      cout<<"try again"<<endl;

      option =0;

      break;
    }


    }



  }
}

//visit creates the frame of the browser gathering from the file data and makes a new
//Navigation Entry with each stored data, places the stored data in current page
//then will place that value into backstack
void Browser::Visit(const string& url, int timestamp){

  //creates a new navigation entry based on the url and timestamp given
  NavigationEntry* newEntry = new NavigationEntry(url, timestamp);

  //if current page is nullptr  then sets the current page to the new entry
  if(m_currentPage == nullptr){

    m_currentPage = newEntry;  
        
  }else{

    //pushes the currentpage after one was recived into back stack
    m_backStack.Push(m_currentPage);

    //sets current page to new entry
    m_currentPage = newEntry;
    
  }
  
  
}
//creates new browser entry based on user input
void Browser::NewVisit(){

  //ignores the pervious user choice 
  cin.ignore();

  //creates a new string variable
  string newURL;

  //asks user the url they would like and places it in the new string url
  cout<<"enter the URL of the new site:"<<endl;
  
  getline(cin, newURL);

  
  //gets the current time (code given)
  auto now = chrono::system_clock::now();
  time_t nowAsTimeT = std::chrono::system_clock::to_time_t(now);
  int64_t timestamp = static_cast<int64_t>(nowAsTimeT);


  //places both newURL and timestamp into visit
  Visit(newURL, timestamp);
  
}

//displays the browser entries for forward and back stack to user
void Browser::Display(){

  //desplays everything in backstack 
  cout<<"**Back Stack**"<<endl;

  //if backstack is empty tells user it is empty
  if(m_backStack.IsEmpty()){

    cout<<"Empty"<<endl;
    

  }else{

    //runs a loop to desplay the position of the website in backstack,
    //while getting each item at that position with the value at i
    int x=1;
    for(long unsigned int i = 0; i<m_backStack.GetSize(); i++){


      //desplays each line to the user with its position and the data
      cout<<x<<". "<<*(m_backStack.At(i))<<endl;

      //increases x by 1
      x++;
    }
    
    
  }

  //desplays everything in forwardstack
  cout<<"**Forward Stack**"<<endl;
  //if forwardstack is empty tells user it is empty
  if(m_forwardStack.IsEmpty()){


    cout<<"Empty"<<endl;


  }else{

    //runs a loop to desplay the position of the website in forwardstack,
    //while getting each item at that position with the value at i
    int x=1;
    for(long unsigned int i = 0; i<m_forwardStack.GetSize(); i++){


      //desplays each line to the user with its position and the data
      cout<<x<<". "<<*(m_forwardStack.At(i))<<endl;

      //increases x by 1
      x++;
    }


  }
  
  
}
//allows user to go back to the previous website
NavigationEntry Browser::Back(int steps){


  //if backstack is not empty creates a forloop that pushes the currentpage
  //into forward stack, and sets the current page to the one that is removed from backstack
  if(!m_backStack.IsEmpty()){

    for(int i = 0; i< steps; i++){

      //places current page into forward stack
      m_forwardStack.Push(m_currentPage);

      //takes out the top of backstack and places it in current page
      m_currentPage = m_backStack.Pop();

      
    }


  }

  //returns the current page
  return *m_currentPage;

}

//allows user to go forward to the previous website
NavigationEntry Browser::Forward(int steps){

  //if forwardstack is not empty creates a forloop that pushes the currentpage
  //into back  stack, and sets the current page to the one that is removed from forwardstack
  if(!m_forwardStack.IsEmpty()){

    for(int i = 0; i< steps; i++){

      //places current page into back stack
      m_backStack.Push(m_currentPage);

      //takes out the top of forwardstack and places it in current page
      m_currentPage = m_forwardStack.Pop();

    }


  }

  //returns the current page
  return *m_currentPage;
}
//gives the current page when called
NavigationEntry Browser::GetCurrentPage() const {

  return *m_currentPage;

}

//loads the file and gets the variables from the file and sets them to visit to creat a new entry
void Browser::LoadFile(){

  //variable to indecate a file
  ifstream inputstream, inputstreamcount;

  //opens the file variable into to files 
  inputstream.open(m_fileName);
  inputstreamcount.open(m_fileName);

  //string variable to incroment by line
  string x;

  //creates string for url and time stamp
  string url;
  string time;

  //creates a while loop to loop through each line of the files
  while(getline(inputstreamcount,x)){

    //sets url and time to the varible given by the file split by the delimiter
    getline(inputstream, url, DELIMITER);
    getline(inputstream, time, '\n');

    //creates the int value of variable time
    int timestamp = stoi(time);

    //sets the variables into visit
    Visit(url, timestamp);
  }

  //closes both files that were open
  inputstream.close();
  inputstreamcount.close();

}
