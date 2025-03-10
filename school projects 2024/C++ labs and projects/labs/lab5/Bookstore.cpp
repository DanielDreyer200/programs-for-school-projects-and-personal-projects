#include "Bookstore.h"

/*************************************************************** 
** File: Bookstore.cpp
** Description: This file contains the Bookstore class function definitions
***************************************************************/

//Constructor - Already implemented for you
Bookstore::Bookstore() {
  cout << "It is your first day managing the UMBC Bookstore.\n";
  cout << "Time to sell some books!\n";
  m_revenue = 0; // money made so far
  m_books = 0; // books available
  m_bookPrice = 0; // price for a single book
  m_manga = 0; // number of manga available
  m_mangaPrice = 0; // price for a single manga
}

//Implement Getters here (get manga count, book price, manga price, revenue)


int Bookstore::GetManga() {return m_manga;}
double Bookstore::GetBookPrice() {return m_bookPrice;}
double Bookstore::GetMangaPrice() {return m_mangaPrice;}
double Bookstore::GetRevenue() {return m_revenue;}



//Getter for m_books already implemented for you
int Bookstore::GetBooks() {return m_books;}

//Implement Setters here (set manga count, book price, manga price, revenue)
void Bookstore::SetManga(int manga) {m_manga = manga;}
void Bookstore::SetbookPrice(int bookPrice ) {m_bookPrice = bookPrice;}

void Bookstore::SetMangaPrice(int mangaPrice) {m_mangaPrice = mangaPrice;}
void Bookstore::SetRevenue(double revenue) {m_revenue = revenue;}




//Setter for m_books already implemented for void ou
void Bookstore::SetBookCount(int books) {m_books = books;}

//Implement SellBook here





//Implement SellManga here

void  Bookstore::SellBook(){

  m_books -= 1;

  m_revenue += m_bookPrice;

}
void  Bookstore::SellManga(){

  m_manga -= 1;

  m_revenue += m_mangaPrice;

}


//SellAll already implemented for you
void Bookstore::SellAll(){
  double revenue = m_books * m_bookPrice + m_manga * m_mangaPrice;
  m_revenue += revenue;
  m_books = 0;
  m_manga = 0;
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  cout << "You just sold books with a total value of: $" << revenue << endl;
}

