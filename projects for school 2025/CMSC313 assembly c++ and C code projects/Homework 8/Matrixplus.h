//guards
#ifndef MATRIXPLUS_H
#define MATRIXPLUS_H

// everything will be using namespace std
using namespace std;

//class name


class Matrixplus{

  //public functions to be used by .cpp
 public:

  //default constructor
  Matrixplus(int row, int col);

  //constructor for a matrix
  Matrixplus(int row, int col, int* value);

  //destructor
  ~Matrixplus();

  //getters
  int getRow() const;
  int getCol() const;

  //setters
  void setRow(const int& rows);
  void setCol(const int& cols);

  //function to add 2 matrixes together
  Matrixplus* add(const Matrixplus& other) const;
  //function to multiply a matrix by an integer
  Matrixplus* multiplyInt(int multiple) const;
  //function to transpose a matrix
  Matrixplus* transpose() const;
  //function to multiply 2 matrixes together
  Matrixplus* multiply(const Matrixplus& other) const;

  //statment  to print final results
  void equation() const;

  //private variables only this and functions who call it can use
 private:

  //variables for 2D array and row and column
  int** data;

  int row;

  int col = 0;

};
//ends guard
#endif
