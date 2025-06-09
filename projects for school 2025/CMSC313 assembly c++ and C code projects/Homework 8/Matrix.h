//guard
#ifndef METRIX_H 
#define METRIX_H


//defines the variables of the program
typedef struct {


  //varriables for column and row and a 2D array
  int row;
  int col;

  int** data;
  
  //defines this for matrix
}Matrix;

//creates a basic matrix
Matrix* CreateMatrix(int row, int col);
//creates a matrix using variables from a 2D array
Matrix* ArreyMatrix(int row, int col, int value[][col]);
//destructor when called
void dealocateMatrix(Matrix* m);
//function to add 2 matrixes together
Matrix* add(Matrix* a, Matrix* bc);
//function to multiply a matrix by an integer
Matrix* multInt(Matrix* b, int intager);
//function to transpose a matrix
Matrix* transpose(Matrix* c);
//function to multiply 2 matrixes together
Matrix* MultMatrix(Matrix* b, Matrix* c);
//statment  to print final results
void equation(Matrix* d);

//ends guard
#endif
