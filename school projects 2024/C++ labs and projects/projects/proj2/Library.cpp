/*************************************************************************
 ** File:    Library.cpp
 ** Project: 202 Project 2, fall 2024
 ** Author:  Daniel Dreyer
 ** Section: 35
 ** E-Malil: ddreyer1@umbc.edu
 **
 ** Discription: this file contains the main programing of the
 **fuction, it will load the file given by the user upon start up,
 **then it will display a menu, this menu will let the user choose 1
 **of 5 options, 1. to display the library of the file given, 2.
 **search through the titles of the books ad display the corisponding
 **titles to the user. 3. add a book of the users choice to the waitlist.
 **4. display the waitlist to the user.
**
*************************************************************************/
//the inclusion of Library.h is all we need, everything is stated is included in there, along with
//variables we will need throughout the program
#include "Library.h"


//default constructer 
Library::Library(){

}
//default overloaded constructer that will load the input file from proj2.cpp
Library::Library(string filename){

  cout << "Loading Books..." << endl;

  LoadCatalog(filename); 

  
}

//loads the given file from proj2.cpp into an array, combining the title, the year, the author and its score together
void Library::LoadCatalog(string filename){

    
  //initializes input stream  
  ifstream inputstream;

  //opens the file in inputstream to be read by the program
  inputstream.open(filename);

  //variables to label each individual component of the program, based on its various segments
  string m_year;
  string m_title;
  string m_author;
  string m_score;

  //forloop to place each individual aspect of the book into the particular array portion it is associated with
  for(int i = 0; i< NUM_BOOKS;i++){

    //gets the line of each book seperating each component by its delimeter and placing the element in the corisponding variable
    getline(inputstream, m_year, DELIMETER);
    getline(inputstream, m_title, DELIMETER);
    getline(inputstream, m_author, DELIMETER);
    getline(inputstream, m_score, '\n');


    //places each element into the array that will then set them into each componemt of the array for every book through the loop
    m_bookCatalog[i].SetYear(stoi(m_year));
    m_bookCatalog[i].SetTitle(m_title);
    m_bookCatalog[i].SetAuthor(m_author);
    m_bookCatalog[i].SetScore(stod(m_score));    
    
  }

  //tells the user it has been loaded
  cout << "Done! all "<<NUM_BOOKS<<" books are Loaded!"<< endl;
  
}

//a variable that is used to determin if the program should close or not
int i=0;

//main menu that lets the user choose a choice and preform the main actions of the program
void Library::MainMenu(){

  //variable setting the different choices of the program from the user
  int c=0;
  
  do{
    
    switch(c){

    case 0:{

      //gives user their choices
      cout<<"What Would You Like To Do?\n1. Display All Books\n2. Search Catalog For Book Title\n3  Add Book To Waitlist\n4. Display Waitlist \n5. Quit"<<endl;

      //places there choice in variable
      cin>>c;
      
      break;
     
    }
    case 1:{

      //opens DisplayBooks function
      DisplayBooks();

      cout<<endl;
      
      //resets to c = 0
      c=0;

      break;

    }
    case 2:{

      //opens search catalog function
      SearchCatalog();

      cout<<endl;

      //resets c to 0
      c=0;

      break;

    }
    case 3:{

      //opens add book function
      AddBook();
      
      cout<<endl;

      //resets c to 0
      c=0;

      break;

    }
    case 4:{

      //opens  display waitlist function
      DisplayWaitList();

      cout<<endl;

      //resets c to 0
      c=0;

      break;

    }
    case 5:{

      //tells user thanks for using the umbc library
      cout<<"Thank You For Visiting the UMBC Library"<<endl;

      //sets i to 1 to end the program
      i=1;

      break;
      
    }

    default:{

      //any value that isnt 0-5 will cause the message
      cout<<"sorry that command isnt recognized, please try again"<<endl;

      //resets to c to 0
      c=0;
      }

    }

    //creates the peramoter for the do while loop
  }while(i == 0);

}

// declairs x as 0 so it can be incromented seperatly for the function bellow
int x=0;

//displays the books to user in incroments of 10 with a way to continue to see the next 10
void Library::DisplayBooks(){

  //variable for the users choice
  string choice;

  //displays books in incroments of 10
  for(int i=0; i<INCR;i++){

    //if the books were to ever reach past NUM_BOOKS then it would end the for loop
    if(x>NUM_BOOKS-1 ){


      i=11;

      //desplays the books in order of the files executed lines
    }else{

      cout<<x+1<<". ";

      m_bookCatalog[x].DisplayBook();

      //incroments x 
      x+=1;
    }
  }
  //asks user to press Q or N for actions
  cout<<"N for next page Q to quit"<<endl;

  //gets users choice
  cin>>choice;

  //if N or n it will play the function again but with x incromnted sice the last page
  if(choice == "N" || choice == "n"){

    //plays display function
    DisplayBooks();

    //if Q or q it will set x to 0 and then open the mainmenu to user
  }else if(choice == "Q" || choice == "q"){

    
    x=0;
    
    }
  
}
//will let user search for anything they type and compare it to the titles in the program then display them to the user
void Library::SearchCatalog(){

  //variables used 
  int y=0;
  string titles;

  cout<<endl;

  //asks user for title
  cout<<"what title would you like to find?"<<endl;

  //sets users input to title
  cin>>titles;

  
  //a for loop takes the title given compares it to all books in file and displays the ones it is back to them
  for(int i = 0; i< NUM_BOOKS;i++){

    //finds the title given by user in the titles of the other books
    size_t found =m_bookCatalog[i].GetTitle().find(titles);

    //compares the titles to thar of rhe other books, those that match will go through
    if(found!=string::npos){

      //displays only the books with the same value of title given by user
      cout<<i+1<<". ";
      m_bookCatalog[i].DisplayBook();

      //incroments y by 1
      y +=1;
    }

  }
  //if y stays 0 then no books were found with that title
  if(y ==0){

    cout<<"no books with that name exists"<<endl;

    //resets y to 0
    y=0;
    
  }
  
}

//total to be used by 2 functions to express the total amount of books in waitlist
int total = 0;

//adds the book the user chooses to waitlist
void Library::AddBook(){

  //sets the total waitlist value to equal total variable
  m_waitCount = total;

  //lets program continue as long as waitlist is less then max wait
  if(m_waitCount < MAX_WAIT){

    //variable
    int z;

    //asks user for a number
    cout<<"what would you like to add (-1 for list)"<<endl;

    cin>>z;

    //degreases users value by 1 to mach the number displayed to user
    int t = z-1;

    //if the user value is -1 then display books and then re displays add books
    if(z ==-1){

      DisplayBooks();

      AddBook();

      //if its less then -1 then there us an error code that will then reload add book
    }else if (z <-1){

      cout<<"please try again that is out of the range"<<endl;

      AddBook();

      //if value is over NUM_BOOKS then 
    }else if (z > NUM_BOOKS){

      cout<<"please try again that is out of the range"<<endl;

      AddBook();

      //if the number is between 1-NUM_BOOKS then it will run to see if it exist in the wait list, if it does then it will be discarded and the user will be asked to pick a new one
    }else if (0<z && z<= NUM_BOOKS){
      
      if(BookExist(m_bookCatalog[t]) == true){

	cout<<m_bookCatalog[t].GetTitle()<<" already exist please try again"<<endl;
	AddBook();
	
      }else{

	//sets the waitlist to the book that was choosen
	m_waitList[m_waitCount] = m_bookCatalog[t];

	//incroments total to add 1 to the counter
	total++;

      }
    }else{

      //if any other variable is picked then it will display the same error message and re open add book
      cout<<"please try again that is out of the range"<<endl;

      AddBook();

    }

  }else{

    //if there are a max number of books, an message will appear and the user will be sent to the main menu
    cout<<"sorry you can not proform this action as you are maxed out on your waitlist"<<endl;
   
  }

}
//will check to see if the book already exists and tell add book if it does
bool Library::BookExist(Book book){

  //used for detection of if the book exists in waitlist
  int p= 0;


  //incroments through all the books in waitlist and determins if they equal the choosen book
  for(int i =0; i< MAX_WAIT;i++){

    // if the y are the same p = 1
    if(m_waitList[i].GetTitle() == book.GetTitle()){

      p =1;
    }else{
      
    }
      
  }

  //if p =1 then it will return true if not it will return false
  if(p == 1){

    return true;

  }else{

    return false;

  }
  
  return 0;
}
//displays the waitlist to the user
void Library::DisplayWaitList(){
  //labels to the user that this is the waitlist
  cout<<"*****WAITLIST*****"<<endl;
  //incromnts through all the waitlist book array, if i < total the for loop breaks and it stops displaying the array further
  for(int i = 0; i<MAX_WAIT;i++){

    if(total <= i){

    break;
    
    }else{
      //displays what currently is in the waitlist array
    cout<<i+1<<". ";
    m_waitList[i].DisplayBook();
    }

    //if the first variable is 0 in the year portion of the array that means there is nothing in the array, thus displaying a message to user that there is nothing in there waitlist
  }if(m_waitList[0].GetYear()==0){

    cout<<"populate the waitlist for books to appear!"<<endl;

  }
  
}

