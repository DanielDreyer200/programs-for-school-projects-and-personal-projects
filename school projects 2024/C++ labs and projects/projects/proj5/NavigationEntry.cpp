/*************************************************************************
 ** File:    NavigationEntry.cpp
 ** Project: 202 Project 5, fall 2024
 ** Author:  Daniel Dreyer
 ** Section: 35
 ** E-Malil: ddreyer1@umbc.edu
 **
 ** Discription: this class defines the information of visiting a website
 ** it will place the given url and timestamp and place it as variables
 ** for the navigation entry, it will then  (when called) give out the url
 ** that was stored and the time that is stored converted to be read easily
 ** by a person, lastly this file places all given data to a singular
 ** line that connects the url and time to the user.
 **
 *************************************************************************/

//includes the header file and iostream and iomanip to be used in this file
#include "NavigationEntry.h"
#include<iostream>
#include <iomanip>

//default constructor
NavigationEntry::NavigationEntry(){}

//overloaded constructer, sets url and timestamp given to private variables
NavigationEntry::NavigationEntry(const string& url, const int& timestamp){

  //sets given url to m_url
  m_url = url;
  //sets given timestamp to m_timeStamp
  m_timeStamp = timestamp;


}
//gives the stored url when called
string NavigationEntry::GetURL() const {return m_url;}

//gives the timestamp when called
int NavigationEntry::GetTimeStamp() const {return m_timeStamp;}

//sets the url to the given variable when called
void NavigationEntry::SetURL(const string& url){m_url = url;}

//sets the timestamp of the given variable when called
void NavigationEntry::SetTimeStamp(const int& time){m_timeStamp = time;}

//if called will check to see if url is empty, if so return true
bool NavigationEntry::IsEmpty() const{

  //if m_url is empty return true else false
  if(m_url.empty()){

    return true;

  }
  return false;
}
//Display timestamp is provided in header file

//friend takes the url places it in the proper displayed format and adds the timestamp to the end
ostream& operator<<(ostream& os, NavigationEntry& Entry){

  os<<"URL: "<<Entry.GetURL()<<" Visited on: "<<Entry.DisplayTimeStamp(Entry.GetTimeStamp())<<endl;

  //returns the data stored in os
  return os;
}
