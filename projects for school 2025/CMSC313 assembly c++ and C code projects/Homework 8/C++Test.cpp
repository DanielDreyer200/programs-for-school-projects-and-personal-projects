//includes that will be needed in the program
#include <iostream>
#include "Matrixplus.h"

//lets namespace std be used throughout the program
using namespace std;




//main function
int main(){


  //creates values for the matrix for each idividual matrix
  //note that the values are placed in order differently then the C program, they are placed from left to right as they appear in the matrix
  int A_values[]= {6,4,8,3};
  int B_values[]= {1,2,3,4,5,6};
  int C_values[]= {2,4,6,1,3,5};
  
  
  //places the values in the matrix itself
  Matrixplus A(2,2,A_values);
  Matrixplus B(2,3,B_values);
  Matrixplus C(2,3,C_values);


  //multiplies matrix by intiger
  Matrixplus* B_mult = B.multiplyInt(3);

  //transposes matrix
  Matrixplus* C_Transpose = C.transpose();

  //multiplies 2 matrixes
  Matrixplus* multiple = B_mult->multiply(*C_Transpose);

  //adds 2 matrixes together
  Matrixplus* D= A.add(*multiple);

  //displays the matrix for D
  cout<<"Matrix D: "<<endl;

  //gets values from D and shows user
  D->equation();

  //deletes all created variables
  delete B_mult;
  delete C_Transpose;
  delete multiple;
  delete D;

  //returns 0 and ends
  return 0;
}
