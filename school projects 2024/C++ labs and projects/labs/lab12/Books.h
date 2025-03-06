/*
File: Books.h
Header file for the Books class
*/
#ifndef BOOKS_H
#define BOOKS_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Books
{
public:
  // Default Constructor
  Books();

  // Copy Constructor
  Books(const Books &source);

  // Overloaded Assignment Operator
  Books &operator=(const Books &source);

  // Destructor
  ~Books();

  // Getter for the size of the Book stack
  int GetSize();

  // Inserts a Book onto the Book stack
  void Insert(const string &book);

  // Removes the top Book on the stack
  void DeleteFirst();

  // Friend Function, overloaded << operator
  friend ostream &operator<<(ostream &os, const Books &source);

private:
  int m_size;               // Number of Books in the stack
  vector<string *> m_books; // Vector of Books
};

#endif
