/*
File: lab12.cpp
*/

#include "Books.h"

int main() {
  // Default Constructor Called
  Books collection1;

  //Adds several books into collection1
  collection1.Insert("The Giver");
  collection1.Insert("All the Lights We Cannot See");
  collection1.Insert("The Odyssey");   
  collection1.Insert("Romeo and Juliet");
  collection1.Insert("The Kite Runner");  

  //Displays books in collection1 using overloaded << operator
  cout << "\nCollection 1:\n"
       << collection1 << endl;

  cout << "Collection 1 COPY (copy constructor) with 2 items deleted\n"
       << endl;
  //Calls copy constructor
  Books collection1Copy(collection1); // Calls the collection copy constructor
  collection1Copy.DeleteFirst(); //Deletes first book from copy of collection 1
  collection1Copy.DeleteFirst(); //Deletes first book from copy of collection 1
  cout << collection1Copy; // Calls overloaded << operator, outputs the m_books list

  // Test 1. order1 and order1Copy must have different memory addresses
  //         AND  # of items in m_books(Deep Copy)
  if ((&collection1 != &collection1Copy) //Checks memory address for deep copy
      && collection1.GetSize() != collection1Copy.GetSize()){ //Makes sure different sizes
    cout << "Copy constructor test PASSED" << endl;
  } else {
    cout << "Copy constructor test FAILED" << endl;
  }

  //Creates new collection using default constructor
  Books collection2;

  //Adds several books to collection2
  collection2.Insert("Bridgerton");
  collection2.Insert("Harry Potter");
  collection2.Insert("The Hunger Games");

  //Calls overloaded << operator to display all books
  cout << "\nCollection 2:\n"
       << collection2 << endl;

  cout << "Collection 2 COPY (overloaded assignment operator) with 3 Books inserted\n"
       << endl;
  
  //Creates new collection using default constructor
  Books collection2Copy;
  collection2Copy = collection2; // Calls the overloaded assignment operator to copy collection2
  //Adds several books to copy
  collection2Copy.Insert("The Maze Runner"); //Adds new book to copy
  collection2Copy.Insert("Percy Jackson and the Olympians"); //Adds new book to copy
  collection2Copy.Insert("The Selection"); //Adds new book to copy
  cout << collection2Copy << endl; //Displays copy using << operator

  // Test 2. collection2 and collection2Copy must have different memory addresses and size
  if ((&collection2 != &collection2Copy) //Checks memory addresses
      && collection2.GetSize() != collection2Copy.GetSize()) { //Checks size
    cout << "Overloaded Assignment Operator test PASSED" << endl;
  } else {
    cout << "Overloaded Assignment Operator test FAILED" << endl;
  }
  
  cout << "Do not forget to run this in Valgrind!" << endl;
}
