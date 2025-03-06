/*
File: Books.cpp
*/

#include "Books.h"

//Default constructor
Books::Books(){
  m_size = 0;
}

//Implement Copy Constructor here
Books::Books(const Books &source) {
  /**************************
  *    Student code here    *
  **************************/

  m_books = source.m_books;
  m_size = source.m_size;
  
  

}

//Implement Overloaded Assignment Operator here
Books &Books::operator=(const Books &source) {
  /**************************
  *    Student code here    *
  **************************/
  m_books = source.m_books;
  m_size = source.m_size;
  

  return *this;
}

//Implement Destructor here
Books::~Books() {
  /**************************
  *    Student code here    *
  **************************/

  
  
  
  for(unsigned i =0; i<m_books.size();i++){

      delete m_books.at(i);

      m_books.at(i) = NULL;
    
  }
 

  

}

int Books::GetSize() {
  return m_size;
}

void Books::Insert(const string &title) {
  // This insert will put the book at the beginning of the vector 
  vector<string*>::iterator it = m_books.begin();
  string *temp = new string(title);
  m_books.insert(it, temp);
  m_size++;
}

void Books::DeleteFirst() {
  if (m_size == 0) {
    cout << "All the Books have been taken!" << endl;
  } else {
    // This will delete the book at the beginning of the vector
    vector<string*>::iterator it = m_books.begin();
    delete m_books.at(0);
    m_books.erase(it);
    m_size--;
  }
}

ostream &operator<<(ostream &os, const Books &source) {
  os << "book Stack Order: (SIZE : " << source.m_size << ")" << endl;
  for (int i = 0; i < source.m_size; i++) {
    os << i + 1 << ". " << *source.m_books[i] << endl;
  }
  return os;
}
