//includes that will be refrenced/used in the program
#include "Matrixplus.h"
#include <iostream>

//program used namespace std througout
using namespace std;

//default constructor
Matrixplus::Matrixplus(int rows, int cols) {

  //sets rows  and columns based on given values
  setRow(rows);
  setCol(cols);

  //sets data to be an array
  data = new int*[row];

  //for loop to loop the array so each value is 0
  for(int i =0; i< row; i++){

      data[i]=new int[col]{0}; 

    }

}



//constructs a matrix with rows and columns and the an array, creating a 2D array matrix 
Matrixplus::Matrixplus(int rows, int cols, int* values){
  
  //sets rows  and columns based on given values
  setRow(rows);
  setCol(cols);

  //sets data to be an array
  data = new int*[row];

  //double for-loop's loops throough the intire array setting the value to the position in data creating its matrix, not that by x (row number) multiplied by number of colums and adding y (column number) we get the position of each value
  for(int x=0;x< row; x++){

    data[x] = new int[col];
    for(int y=0; y< col; y++){

      data[x][y]= values[x * cols + y];



    }

  }


}



//destructor, breaks apart each value in a matrix at the end, right before the program ends
Matrixplus::~Matrixplus(){


  //loops through the matrix and deletes each component
  for(int i =0; i< row; i++){

    delete[] data[i];

  }
  delete[] data;

}

//gets the amount in row and column
int Matrixplus::getRow() const{return row;}
int Matrixplus::getCol()const{return col;}

//sets given row and column values
void Matrixplus::setRow(const int& rows) {row = rows;}
void Matrixplus::setCol(const int& cols){col = cols;}


//adds 2 different matrixes together
Matrixplus* Matrixplus::add(const Matrixplus& other) const{

  //creates a matrix to be added based on the row and collumns given
  Matrixplus* added = new Matrixplus(row, col);

  //for loop that goes through each data point of both matrixes and adds them together
  for(int x=0;x< row; x++){
    for(int y=0; y< col; y++){

      added->data[x][y] = data[x][y]+other.data[x][y];



    }

  }
  //returns the value of the new matrix
  return added;
  
  
}

//multiplies a matrix by an integer value
Matrixplus* Matrixplus::multiplyInt(int multiple) const{

  //creates a matrix with the given rows and columns
  Matrixplus* multipleInt = new Matrixplus(row, col);

  // for loop that loops through each data point and multiplies the data by the integer
  for(int x=0;x< row; x++){
    for(int y=0; y< col; y++){

      multipleInt->data[x][y] = data[x][y] * multiple;

    }

  }
  //returns the value of the new matrix
  return multipleInt;
  
}

//transposes the matrix that is sent
Matrixplus* Matrixplus::transpose() const{

  //creates a matrix with the length of row and columns
  Matrixplus* transformed = new Matrixplus(col, row);

  //takes the data points of the matrix given and switches their x and y coordents
  for(int x=0;x< row; x++){
    for(int y=0; y< col; y++){

      transformed->data[y][x] = data[x][y];



    }

  }
  //returns the value of the new matrix
  return transformed;

  
}

//multiplies 2 matrixes together
Matrixplus* Matrixplus::multiply(const Matrixplus& other) const{

  //creates amatrix of the passed value of both the column of a differnt value passed and the row of the matrixed passed
  Matrixplus* times = new Matrixplus(row, other.col);

  //forloop to loop and set the value of the new matrix to 0
  for(int x=0;x< row; x++){
    for(int y=0; y< other.col; y++){

      times->data[x][y]=0;

      //loops through one last time with a new for loop, this ten lets it multiply the 2 matrixs and adds that value to the new matrix
      for(int z = 0; z< col; z++){

	times->data[x][y] += data[x][z]*other.data[z][y];


      }

    }

  }

  //returns the value of the new matrix
  return times;
  
}

//creates an expression using the final matrix
void Matrixplus::equation() const{

  //goes through every varriable and desplays them to user
  for(int x=0;x< row; x++){
    for(int y=0; y< col; y++){

      cout<<data[x][y]<<" ";



    }
    cout<<endl;

  }


}



