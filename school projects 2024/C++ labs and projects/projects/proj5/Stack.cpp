
/*Title: Stack.cpp
  Author: Prof. Dixon
  Date: 11/14/2024
  Description: This class defines a templated stack using a linked list
*/
#include <iostream>
#include <stdexcept>
using namespace std;

//Templated node class used in templated linked list
template <class T>
class Node {
public:
  Node( const T& data ); //Constructor
  T& GetData(); //Gets data from node
  void SetData( const T& data ); //Sets data in node
  Node<T>* GetNext(); //Gets next pointer
  void SetNext( Node<T>* next ); //Sets next pointer
private:
  T m_data;
  Node<T>* m_next;
};

//Overloaded constructor for Node
template <class T>
Node<T>::Node( const T& data ) {
  m_data = data;
  m_next = NULL;
}

//Returns the data from a Node
template <class T>
T& Node<T>::GetData() {
  return m_data;
}


//Sets the data in a Node
template <class T>
void Node<T>::SetData(const T& data ) {
  m_data = data;
}

//Gets the pointer to the next Node
template <class T>
Node<T>* Node<T>::GetNext() {
  return m_next;
}

//Sets the next Node
template <class T>
void Node<T>::SetNext( Node<T>* next ) {
  m_next = next;
}

//**********Stack Class Declaration***********
template <typename T> //Indicates linked list is templated
class Stack {
public:
  // Name: Stack (Default constructor)
  // Description: Creates a new Stack object
  // Preconditions: None
  // Postconditions: Creates a new Stack object
  Stack();
  // Name: ~Stack
  // Description: Stack destructor - deallocates all nodes in linked list
  // Preconditions: None
  // Postconditions: All nodes are deleted. Size is 0. No memory leaks.
  ~Stack();
  // Name: Stack (Copy constructor)
  // Description: Creates a new Stack object based on existing stack
  // Preconditions: None
  // Postconditions: Creates a new Stack object from existing stack
  //                 in separate memory space
  Stack(const Stack& source);
  // Name: Stack<T>& operator= (Assignment operator)
  // Description: Makes two stacks identical based on source.
  // Preconditions: None
  // Postconditions: Two stacks with same number of nodes and same values
  //                 in each node in a separate memory space
  Stack<T>& operator=(const Stack& other);
  // Name: Push
  // Description: Adds a new node to the top of the stack
  // Preconditions: None
  // Postconditions: Adds a new node to the top of the stack
  void Push(const T& value);
  // Name: Pop
  // Description: If stack is empty, throw runtime_error("Stack is empty");
  //              Temporarily stores data from node at the top of the stack.
  //              Removes the node from the top of the stack. Returns the stored data.
  // Preconditions: Stack has at least one node
  // Postconditions: See description 
  T Pop();
  // Name: Peek
  // Description: If stack is empty, throw runtime_error("Stack is empty");
  //              Returns the stored data from top node.
  // Preconditions: Stack has at least one node
  // Postconditions: See description
  T Peek() const;
  // Name: At
  // Description: If stack is empty, throw runtime_error("Stack is empty")
  //              Returns stored data from number of the node passed to function.
  //              At(3) would return the data from the fourth node.
  // Preconditions: Stack has at least one node
  // Postconditions: Returns data from number of node starting at m_top
  T At(int num);
  // Name: IsEmpty
  // Description: Returns if the stack has any nodes.
  // Preconditions: Stack has at least one node
  // Postconditions: If stack has no nodes, returns true. Else false.
  bool IsEmpty() const;
  // Name: RemoveBottom
  // Description: If stack is empty, throw runtime_error("Stack is empty")
  //              Temporarily stores data from node at the bottom of the stack.
  //              Removes node from bottom of the stack. Returns the stored data.
  //              Similar to Pop but opposite end of stack
  // Preconditions: Stack has at least one node
  // Postconditions: Removes node from bottom of stack and returns data
  T RemoveBottom();
  // Name: Display
  // Description: If stack is empty, outputs that the stack is empty
  //              Otherwise, iterates through stack and displays data in each node
  // Preconditions: Stack has at least one node
  // Postconditions: Displays data from each node in stack
  void Display();
  // Name: GetSize
  // Description: Returns the number of nodes in the stack
  // Preconditions: None
  // Postconditions: Returns the number of nodes in the stack.
  size_t GetSize() const;  
private:
  Node<T>* m_top; //Top node in stack
  size_t m_size; //Number of nodes in stack
};

//*********************STACK FUNCTIONS IMPLEMENTED HERE******************

/*************************************************************************
 ** File:    Stack.cpp
 ** Project: 202 Project 5, fall 2024
 ** Author:  Daniel Dreyer
 ** Section: 35
 ** E-Malil: ddreyer1@umbc.edu
 **
 ** Discription: this class is the back bone of the program, it allows
 ** for the node from the other files that pass the node, to be removed
 ** from the top, pushed into the stack to check if the stack is empty, to
 ** see what node is at at a spacific point and dealocates all values.
 ** there is also a copy constructor and an assignment operator that is
 ** not used but is avalible to be used, along with a peek function and a
 ** display function, the desplay will be used when interacting with any
 ** of these unused functions.
 **
 *************************************************************************/

//default constructor, sets m_top and m_size to there respective default values
template <class T>
Stack<T>::Stack(){

  //sets m_top to nullptr
  m_top = nullptr;
  //sets m_size to 0
  m_size = 0;
}
//dealocates all values passed to it
template <class T>
Stack<T>::~Stack(){


  //checks to see if the value passed is empty, while not empty removes top node 
  while (!IsEmpty()) {

    Pop();
  }
  //sets m_top and m_size todefault values

  m_top = nullptr;
  m_size = 0;
  
}

//copy constructor, when called sets each node to a temp node and places it in a temp stack,
//then places all of that into the current stack that called it
template <class T>
Stack<T>::Stack(const Stack& source){

  //if the given values m_top is equal to nullptr set m_top to nullptr
  if (source.m_top == nullptr) {

    m_top = nullptr;

  }else{ 
  

    //sets m_size to the m_size of the source
    m_size = source.m_size;

    //creates a temp node equal to the sources givens m_top
    Node<T>* temp = source.m_top;

    //creates a temp stack 
    Stack<T> tempStack;

    //while temp is not nullptr place the data into temp stack, have
    //m_top equal temp, then set both m_top and temp to the next variable,
    //then decrease m_size by one
    while(temp != nullptr){

      //push back tempstack with the data from temp
      tempStack.Push(temp->GetData());

      //set m_top to temp
      m_top = temp;

      //set m_top to next variable
      m_top = m_top->GetNext();

      //set temp to next variable
      temp = temp->GetNext();

      //decrease size by 1
      m_size--;
    
    }

    //while tempstack is not empty, push the poped value from tempstack to
    //this(aka the item that called this coppy constructor)
    while(!tempStack.IsEmpty()){


      //removes the top node from tempstack and places that node into this
      this->Push(tempStack.Pop());
      
    }

  }
  
}

//assignment operator that when called sets each node to a temp node and places it in a temp stack,
//then places all of that into the current stack that called it
template <class T>
Stack<T>& Stack<T>::operator=(const Stack& other){

  //if the given values m_top is equal to nullptr set m_top to nullptr
  if (other.m_top == nullptr) {

    m_top = nullptr;

  }else{

    //sets m_size to the m_size of the other
    m_size = other.m_size;

    //creates a temp node equal to the others given m_top
    Node<T>* temp = other.m_top;

    //creates a temp stack
    Stack<T> tempStack;

    //while temp is not nullptr place the data into temp stack, have
    //m_top equal temp, then set both m_top and temp to the next variable,
    //then decrease m_size by one
    while(temp != nullptr){

      //push back tempstack with the data from temp
      tempStack.Push(temp->GetData());

      //set m_top to temp
      m_top = temp;

      //set m_top to next variable
      m_top = m_top->GetNext();

      //set temp to next variable
      temp = temp->GetNext();

      //decrease size by 1
      m_size--;

    }

    //while tempstack is not empty, push the poped value from tempstack to
    //this(aka the item that called this assignment operator)
    while(!tempStack.IsEmpty()){

      //removes the top node from tempstack and places that node into this
      this->Push(tempStack.Pop());


    }

  }
  //return's this
  return *this;

  
}

//pushes the geven value of a stack tinto a node setting it at the top and increasing size
template <class T>
void Stack<T>::Push(const T& value){

  //creates a new node with the variable of value
  Node<T>* newStack = new Node<T>(value);

  //puts the next variable in new stack as m_top
  newStack -> SetNext(m_top);

  //m_top equals the new stack
  m_top = newStack;

  //increases size by 1
  m_size++;
  
}

//removes the top node of the stack
template <class T>
T Stack<T>::Pop(){

  //if the size is 0 then return runtime error
  if(m_size == 0){

    throw runtime_error("Stack is empty");

  }else{

    //puts m_top to temp node
    Node<T>* temp = m_top;

    //creates a data value that gets the data from temp
    T data =  temp->GetData();

    //sets m_top to next m_top value
    m_top = m_top->GetNext();

    //delete temp
    delete temp;

    //reduce size by 1
    m_size--;

    //returns the value of the data
    return data;
    
  }
 
  
  
}

//peeks at the top of the stack
template <class T>
T Stack<T>::Peek() const {

  //if the stack is not empty sends run time error
  if(IsEmpty()){

    throw runtime_error("Stack is empty");

  }else {


    //returns the value of the m_top
    return m_top->GetData();
    
  }
  
}
//gets value at a spacific time to the user
template <class T>
T Stack<T>::At(int num){

  //if stack is empty, throw run time error
  if(IsEmpty()){

    throw runtime_error("Stack is empty");

  }else{

    //temp is set tot equal m_top
    Node<T>* temp = m_top;

    //iterate through untill the value given is met
    for(int i =0; i< num; i++){

      //sets temp to next temp value
      temp = temp->GetNext();
    }

    //return the data of temp
    return temp->GetData();
  }
  
}
//checks to see is stack is empty
template <class T>
bool Stack<T>::IsEmpty() const{

  //if the size is 0 return true
  if(m_size == 0){

    return true;

  }else{

    return false;
  }
  

}

//removes the bottom node of a stack
template <class T>
T Stack<T>::RemoveBottom(){

  //sets temp to the values of m_top
  Node<T>* temp = m_top;

  //creates variable for data
  T data;

  //if size is 0 throw runtime error
  if(m_size == 0){

    throw runtime_error("Stack is empty");

    //if the next variable of temp is nullptr
  }else if(temp->GetNext() == nullptr){

    //set data to temps data value
    data = temp->GetData();

    //m_top equals temps next node
    m_top = temp->GetNext();

    //delete temp
    delete temp;

    //decrease size by 1
    m_size--;

    //return data
    return data;

  }else{

    //while the second value next of temp is not nullptr, set temp to be next temp node
    while(temp ->GetNext() ->GetNext() != nullptr){

      //temp equals next temp node
      temp = temp->GetNext();

     
    }

    //data equals temp data value
    data = temp->GetData();

    //m_top equals the next m_top node
    m_top = m_top->GetNext();

    //delete temp
    delete temp;

    //decrease size by 1
    m_size--;

    //return data value
    return data;
  }
  
}
//desplays the value of the data when called
template <class T>
void Stack<T>::Display(){

  //if stack is empty tells user its empty
  if(IsEmpty()){

    cout<<"This Is Empty"<<endl;
    

  }else{

    //temp is equal to m_top
    Node<T>* temp = m_top;

    //while temp does not equal nullptr
    while(temp != nullptr){

      //desplay data of temp
      cout<<(temp->GetData())<<endl;

      //sets temp to the next temp node
      temp = temp->GetNext();
    }

    //delete temp
    delete temp;

  }

}
//gives size when called
template <class T>
size_t Stack<T>::GetSize() const {

  //return the size
  return m_size;
}

