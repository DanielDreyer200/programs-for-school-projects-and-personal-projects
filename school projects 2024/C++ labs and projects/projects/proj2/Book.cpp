/*************************************************************************
 ** File:    Book.cpp
 ** Project: 202 Project 2, fall 2024
 ** Author:  Daniel Dreyer
 ** Section: 35
 ** E-Malil: ddreyer1@umbc.edu
 **
 ** Discription: this file contains the getters and setters for the books
 **directed in this program. along with a function to organize them
 **correctly.
 *************************************************************************/

//the includes used in the program to get the values for getters and setters
#include "Library.h"
#include "Book.h"

//standared namespace std
using namespace std;

//default constructor
Book::Book(){
  
  

}
//overloaded constructor that sets values for year title author and score
Book::Book(int year, string title, string author, double score){

  SetYear(year);
  SetTitle(title);
  SetAuthor(author);
  SetScore(score);
  
}

//getters that returns the year, title, author and score of each book
int Book::GetYear(){return m_year;}
string Book::GetTitle(){return m_title;} 
string Book::GetAuthor(){return m_author;}
double Book::GetScore(){return m_score;}

//setters that set the year, title, author and score of each book
void Book::SetYear(int year){m_year = year;} 
void Book::SetTitle(string title){m_title = title;} 
void Book::SetAuthor(string author){m_author = author;} 
void Book::SetScore(double score){m_score = score;}

//displays all the variables properly in the format described (year) title by author with a score score
void Book::DisplayBook(){

  cout<<m_title<<" ("<<m_year<<")"<<" by "<<m_author<<" with a score of "<<m_score<<endl;  
  
}
