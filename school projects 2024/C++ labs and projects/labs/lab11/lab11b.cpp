/* Title: lab11a.cpp
      Course: CMSC 202 - Fall 2024
         Description: This introduces templated classes.
*/
#include <iostream>
using namespace std;

template <class T>
class DynamicArray {
public:
  //Constructor for DynamicArray
  DynamicArray() {
    size = 0;
    arr = new T[size];
  }

  //Destructor for DynamicArray
  ~DynamicArray() {
    delete[] arr;
  }
  
  // COMPLETE THIS FUNCTION
  void Push(T val) {


    T temp[size +1];

    for(int i =0; i<size; i++){

      temp[i] = arr[i];
      

    }
    temp[size]= val;
    delete[] arr;

    arr = new T[size +1];

    for(int i=0; i<size+1; i++){

      arr[i] = temp[i];
      
    }
    

    size++;
    // This function should add an element to the front of the dynamic array

    //HINTS:
    // - Create a temporary array with size + 1 elements
    // - Copy arr values to temporary array
    // - Add the new element
    // - Deallocate arr
    // - Reinitialize with size + 1 elements
    // - Copy temporary array values to arr
    // - Increase the size variable
  }

  //Pops (Removes) data from DynamicArray
  void Pop() {
    T temp[size - 1];
    
    for (int i = 0; i < size - 1; ++i) {
      temp[i] = arr[i];
    }
    delete[] arr;
    
    arr = new T[size - 1];
    for (int i = 0; i < size - 1; ++i) {
      arr[i] = temp[i];
    }
    
    --size;
  }

  //Displays data from Dynamic Array
  void Display() {
    cout << "Dynamic Array Elements:" << endl;
    for (int i = 0; i < size; ++i) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
  
private:
  T* arr; //Pointer for dynamically allocated array
  int size; //Size of DynamicArray
};

int main() {
  DynamicArray<int> darr; //Calls constructor
  darr.Display(); //Displays array
  darr.Push(1); //Adds 1 to array
  darr.Display(); //Displays array
  darr.Push(2); //Adds 2 to array
  darr.Push(3); //Adds 3 to array
  darr.Push(4); //Adds 4 to array
  darr.Display(); //Displays array
  darr.Pop(); //Removes last entry in array (4)
  darr.Display(); //Displays array
  
  return 0;
}
