//includes that will be needed in the program
#include <stdio.h>
#include "Matrix.h"
#include <stdlib.h>

//main function
int main(){

  //creates values for the matrix for each idividual matrix
  int A_values[2][2] = {{6,4},{8,3}};
  int B_values[2][3] = {{1,2,3},{4,5,6}};
  int C_values[2][3] = {{2,4,6},{1,3,5}};

  //places the values in the ArreyMatrix itself
  Matrix* A = ArreyMatrix(2,2,A_values);
  Matrix* B = ArreyMatrix(2,3,B_values);
  Matrix* C = ArreyMatrix(2,3,C_values);


  //multiplies matrix by intiger
  Matrix* B_mult = multInt(B,3);

  //transposes matrix
  Matrix* C_Transpose = transpose(C);

  //multiplies 2 matrixes
  Matrix* multiple = MultMatrix(B_mult, C_Transpose);

  //adds 2 matrixes together
  Matrix* D= add(A, multiple);

  //displays the matrix for D
  printf("Matrix D: \n");

  //gets values from D and shows user
  equation(D);

  //calss dealocation of each matrix created
  dealocateMatrix(A);
  dealocateMatrix(B);
  dealocateMatrix(C);

  //calls each dealocation for each created matrix variale
  dealocateMatrix(B_mult);
  dealocateMatrix(C_Transpose);
  dealocateMatrix(multiple);
  dealocateMatrix(D);

  //returns 0 and ends
  return 0;









}
