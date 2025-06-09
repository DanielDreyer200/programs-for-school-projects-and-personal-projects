//includes that will be refrenced/used in the program
#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>


//creates a new matrix
Matrix* CreateMatrix(int rows, int cols) {

  //creates a matrix based on the size of te matrix sent to it
  Matrix* value = malloc(sizeof(Matrix));

  //sets the row and columns to the values given
  value->row = rows;
  value->col = cols;

  //sets the value of the data to the created matrix
  value->data = malloc(rows * sizeof(int*));


  //forloop that goes through each row and places variables in them
  for(int i =0; i< rows; i++){

    value->data[i] = calloc(cols, sizeof(int));

  }

  //returns the new matrix
  return value;

}

//creates a matrix using the function above
Matrix* ArreyMatrix(int rows, int cols, int values[][cols]){


  //creates a matrix based on given values
  Matrix* val = CreateMatrix(rows, cols);

  //for loop to set values to the matrix created
  for(int x=0;x< rows; x++){

    for(int y=0; y< cols; y++){

      val->data[x][y]= values[x][y];



    }

  }

  //returns the value of the new matrix
  return val;

}


//dalocates variables 
void dealocateMatrix(Matrix* matrix){

  //loops through and frees varibles emptying the matrix of its data
  for(int i=0; i< matrix->row;i++){

    free(matrix->data[i]);


  }
  free(matrix->data);

  free(matrix);


}


//adds 2 matrixes together
Matrix* add(Matrix* a, Matrix* bc){

  //creates a new matrix
  Matrix* added = CreateMatrix(a->row, a->col);


  //for loop that goes through each data point of both matrixes and adds them together
  for(int x=0;x< a->row; x++){
    for(int y=0; y< a->col; y++){
      added->data[x][y] = a->data[x][y] + bc->data[x][y];



    }

  }
  //returns the value of the new matrix
  return added;


}
//multiplies a matrix by an integer value
Matrix* multInt(Matrix* b, int intager){

  //creates a matrix with the given rows and columns
  Matrix* multipleInt = CreateMatrix(b->row, b->col);

  // for loop that loops through each data point and multiplies the data by the integer
  for(int x=0;x< b->row; x++){
    for(int y=0; y< b->col; y++){

      multipleInt->data[x][y] = b->data[x][y] * intager;



    }

  }
  //returns the value of the new matrix
  return multipleInt;

}
//transposes the matrix that is sent
Matrix* transpose(Matrix* c){

  //creates a matrix with the length of row and columns
  Matrix* transformed = CreateMatrix(c->col, c->row);

  //takes the data points of the matrix given and switches their x and y coordents
  for(int x=0;x< c->row; x++){
    for(int y=0; y< c->col; y++){

      transformed->data[y][x] = c->data[x][y];



    }

  }
  //returns the value of the new matrix
  return transformed;


}

//multiplies 2 matrixes together
Matrix* MultMatrix(Matrix* b, Matrix* c){
  //creates amatrix of the passed value of both the column of a differnt value passed and the row of the matrixed passed
  Matrix* times = CreateMatrix(b->row, c->col);

  //forloop to loop and set the value of the new matrix to 0
  for(int x=0;x< b->row; x++){
    for(int y=0; y< c->col; y++){

      
      times->data[x][y]=0;


      //loops through one last time with a new for loop, this ten lets it multiply the 2 matrixs and adds that value to the new matrix
      for(int z = 0; z< b->col; z++){

	times->data[x][y] += b->data[x][z] * c->data[z][y];


      }

    }

  }
  //returns the value of the new matrix
  return times;

}

//creates an expression using the final matrix
void equation(Matrix* d){

  //goes through every varriable and desplays them to user
  for(int x=0;x< d->row; x++){
    for(int y=0; y< d->col; y++){

      printf("%d ", d->data[x][y]);



    }
    printf("\n");

  }


}
