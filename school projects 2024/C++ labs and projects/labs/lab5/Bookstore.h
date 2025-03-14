/***************************************************************
** Topic: Lab 5
** File: Bookstore.h
** Description: This file contains the Bookstore class declaration
***************************************************************/

#ifndef BOOKSTORE_H //Header Guards
#define BOOKSTORE_H //Header Guards

#include <iostream>
#include <string>
using namespace std;



// Declare the Bookstore class here
// Make sure to include a generic constructor,
// getters and setters for all member variables,
// and the functions described in the document

class Bookstore {

public:
  //Constructor for Bookstore (implementation provided)

  Bookstore();

  //Getters
  //Getter for Books Available (implementation provided)

  int getBooks(){

    return m_books;
    
  } 
  
  //Getter for total Manga Available
  
  int getManga(){

    return m_manga;

  }

  
  
  //Getter for Book Price

  double getBookPrice(){

    return m_bookPrice;

  }
  
  //Getter for Manga Price

  double getMangaPrice(){

    return m_mangaPrice;

  }
  
  //Getter for Revenue
  double getRevenue(){

    return m_revenue;

  }
  
  //Setters
  //Sets Number of Books Available (implementation provided)
  int setBooks(int m_books){

    return m_books = m_books;

  }
  //Sets Number of Manga Available
  int setmanga(int m_manga){

    return m_manga = m_manga;

  }
  //Sets Book Price
  double setBookPrice(double m_bookPrice){

    return m_bookPrice = m_bookPrice;

  }
  
  //Sets Manga Price
  double setMangaPrice(double m_mangaPrice){

    return m_mangaPrice = m_mangaPrice;

  }
  //Sets Total Revenue
  double setRevenue(double m_revenue){

    return m_revenue = m_revenue;

  }
  
  //Other
  //Sell Book

  void SellBook();
  
  //Sell a Manga
  void SellManga();

  //Sell All (implementation provided)

  void SellAll();
  
//Declare five member variables
//(book count, manga count, book price, manga price, revenue)
private:
  int m_books;
  int m_manga;

  double m_bookPrice;
  double m_mangaPrice;
  double m_revenue;




};

#endif //End of Header Guards
