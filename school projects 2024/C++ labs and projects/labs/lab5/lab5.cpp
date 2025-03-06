/************************************************************************
** File: lab5.cpp
** Description: Uses a Bookstore to demonstrate how classes work in C++
************************************************************************/

#include "Bookstore.h"
#include <iostream>
#include <string>

// Declare DisplayInfo here (provided)
void DisplayInfo(Bookstore myBookstore);

int main() {
  // Creates Bookstore object
  Bookstore myBookstore;

  // Constant for number of books and manga
  const int NUM_BOOKS = 435;
  const int NUM_MANGA = 115;
  const double PRICE_BOOK = 14.25;
  const double PRICE_MANGA = 10.50;

  // Use setters to populate member variables of the Bookstore
  // Make 435 books with a price of $14.25 a book using constants
  myBookstore.SetBookCount(NUM_BOOKS);
  myBookstore.SetBookPrice(PRICE_BOOK);
  // Make 115 manga volumes with a price of $10.50 a manga using constants
  myBookstore.SetMangaCount(NUM_MANGA);
  myBookstore.SetMangaPrice(PRICE_MANGA);
  
  // Displays inventory at the bookstore
  DisplayInfo(myBookstore);

  // Sell a single book
  cout << "Selling a copy of Just Mercy!" << endl;
  myBookstore.SellBook();
  DisplayInfo(myBookstore);

  // Sell a single manga
  cout << "Selling a volume of Witch Hat Atelier!" << endl;
  myBookstore.SellManga();
  DisplayInfo(myBookstore);

  // Sells the rest of the items and displays overall revenue
  cout << "Selling all our inventory!" << endl;
  myBookstore.SellAll();

  // Displays the total revenue after selling all of the items
  cout << "\nToday's Revenue: $" << myBookstore.GetRevenue() << "\n" << endl;
  
  return 0;
}

void DisplayInfo(Bookstore myBookstore){

  cout<<"Books Avalible: "<<NUM_BOOKS<<endl;
  cout<<"Manga Avalible: "<<NUM_MANGA<<endl;
  cout<<"Book costs: "<<PRICE_BOOKS<<endl;
  cout<<"manga costs: "<<PRICE_MANGA<<endl;
  cout<<"current revenue: "<<myBookstore.getRevenue()<<endl;
  

}
//Implement displayInfo here
//Displays books and manga available
//Displays book and manga cost per item
//Displays current revenue at store
//Hint use precision or setprecision and fixed to show currency

