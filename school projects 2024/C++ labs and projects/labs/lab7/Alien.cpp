// File: Alien.cpp
// Date: 10/14/2024 - 10/17/2024
// Description: You are defining the TWO FUNCTIONS ONLY
#include "Alien.h"
#include <iostream>
using namespace std;

/************ YOU ARE ONLY DEFINING TWO FUNCTIONS FOR THIS LAB ************/

// AlienList Constructor
AlienList::AlienList(){
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
}

// AlienList Destructor
AlienList::~AlienList(){
  
  // Loop until m_head is nullptr
  while(m_head != nullptr){
    RemoveHead();
  }
  /* 
   * Note: m_head and m_tail are already nullptr from RemoveHead()
   * m_size is set to 0 from RemovedHead()
   * Adding m_head = nulltr, etc is redundant
   */
}

/******* YOU ARE IMPLEMENTING THIS *******/
// Inserts alien to the end of the list
// HINT: There are TWO conditions to consider when appending
// 1. No nodes in list or 2. Has nodes
// Implement this first
void AlienList::Insert(const string name){

  Alien *temp = new Alien();

  temp -> m_next = nullptr;
  
  
  if(m_head == nullptr){

    m_head = temp;
    m_tail = temp;
    

  }
  else{

    //temp -> m_next = m_head;
    //m_head = temp;

    temp -> m_next = m_head;
    m_head = temp;
    
  }

  m_size++;
  
}

// Displays all data and the list of aliens(Provided)
void AlienList::Display(){
  Alien* it = m_head; // Iterator for linked list
  unsigned int counter = 1; // Counter for number of Xen creatures
  
  cout << "****** Xen Creature Database ******\n";
  cout << "You have " << m_size << " unique Xen creatures recorded!\n";
  
  // Iterator until we get to the end
  while(it != nullptr){
    cout << counter << ": " << it->m_name << endl;
    it = it->m_next;
    counter++;
  }
  
  cout << endl;
}

/******* YOU ARE IMPLEMENTING THIS *******/
// Removes alien with the given name
// Iterate through the list to find the alien to be remove
// HINT: There are FOUR conditions to consider when removing a node.
// No node, head, tail, middle
// One of the conditions is already implemented for you in the class
void AlienList::RemoveAlien(string name){

  Alien *curr = m_head;
  Alien *prev = m_head;

  
    while(curr!= nullptr){

      

      prev = curr;


      curr = curr -> m_next;
    

      prev->m_next = curr -> m_next;


     

      if(curr == m_tail){

        delete curr;

      }if(curr == m_head){

	RemoveHead();

      }if(curr == nullptr){


	return;
	
      }

      
    }

    m_size--;
  

  

  
  
  //prev->m_next = curr -> m_next;
  
  
}

// Removes head of the list
void AlienList::RemoveHead(){
  // Perform if head is not nullptr
  if(m_head != nullptr){
    
    // One element in list condition
    // Sets tail to nullptr
    if(m_head == m_tail){
      m_tail = nullptr;
    }
    
    Alien* temp = m_head;
    m_head = m_head->m_next;
    delete temp;
    m_size--;
  }
}

