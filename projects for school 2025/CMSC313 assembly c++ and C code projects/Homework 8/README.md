AUTHORING:
Daniel Dreyer UMBC/CMSC 313 Spring 8:30AM

PURPOSE OF SOFTWARE:
this is 2 programs a C and a C++ both with librarys, the purpose of both programs is to solve the given matrix equation in the prompt given to us by the teacher

FILES
C++Test.cpp is the main file for the C++ program, holding the main function
CTest.c is the main file for the C program, holding the main function
Matrixplus.h is the header file for the C++ program, it holds the decliration of functions for the .c file
Matrix.h is the header file for the C program, it holds the decliration of functions for the .c file 
Matrixplus.cpp is the file for the library of the C++ program, it holds the library of all matrix functions needed for the program
Matrix.cpp is the file for the library of the C program, it holds the library of all matrix functions needed for the program
makefile is the make file used for bitvise ssh, the compile commands are also locate in their

BUILD INSTRUCTIONS:
make sure that if you are using a personal computer without bitvise SSH you have the GNU installed to run the program, and follow the instructions in the TESTING METHODOLOGY section
if you are running the program in bitvise SSH the make file will be easier to use and the instructions are in the TESTING METHODOLOGY section

TESTING METHODOLOGY: 
in order to compile and get the program to run all files must be downloaded, if using bitvise SSH the makefile will be used, in order to use the makefile go to its location with all the other files, type "make" and it will compile, to run either the C or C++ type "make run" for the C++ and "make run1" for C
if you are not using bitvisew SSH, please note the Make file will not compile properly. instead, find the location to which you have saved the files and open that location in comand prompt, run the command "g++  -Wall  Matrixplus.cpp C++Test.cpp -o C++Test" then type "C++Test" this will run then compile the C++ program. for the C program run "gcc -std=c99 -m32 -O0 Matrix.c CTest.c -o CTest" to compile and then "CTest" to run.

ADDITIONAL INFORMATION:
if you would like to know further details on each finction themselves their are comments on them in each file.
Also Note that they are different in the format the arrays need to be placed in
