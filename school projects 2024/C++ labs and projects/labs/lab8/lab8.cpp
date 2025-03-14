//Title:  Lab 8 - Debugging
//Author: AJ Boyd
//Course: CMSC 202
//Desc:   For this lab, you will use GDB to find where the errors occur.
//        None of the errors are in main(). You should not edit main in any way.
//        You MUST use GDB to get credit for this lab

/* When corrected, this program should output:
The team is empty!
This team has 5 players.
Ana->Soldier:76->Roadhog->Juno->Genji->END
This team has 3 players.
Roadhog->Juno->Genji->END
 */

#include <iostream>
#include <string>
using namespace std;

struct Node {
public:
  string m_info; //Data
  Node* m_next; //Node pointer
  //int m_size = 0;
};

class LinkedList {
public:
  LinkedList(); //constructor
  ~LinkedList(); //destructor
  void InsertEnd(string data); //Insert function
  void RemoveFront(); //Remove the first node
  void Display(); //Display function
private:
  Node* m_head; //Track front of linked list
  int m_size; //Track size of linked list
};

LinkedList::LinkedList() { // Constructor for linked list
  m_head = nullptr;// set all member vars to default values
  m_size = 0;
}

LinkedList::~LinkedList() { // Destructor for linked list
  while (m_size > 0) {      // While the list is not empty, Remove the first node
    RemoveFront();
  }
}

void LinkedList::InsertEnd(string data) {
  Node *newNode = new Node; //Dynamically allocates a new node
  newNode->m_info = data; //Populates data in new node
  newNode->m_next = nullptr; //Sets m_next in new node to nullptr
  //Possible Cases:
  //list is empty
  if (m_size == 0) {
    m_head = newNode;

    //m_size++;
    
  } else {
    //List not empty
    Node* cur = m_head; // lastNode will point at last Node of the list
    while (cur->m_next != nullptr) { // iterate lastNode through list
      cur = cur->m_next;
    }
    cur->m_next = newNode; // link the (old) last node to the new one
  }

  m_size++;
}

//No errors in RemoveFront
void LinkedList::RemoveFront() {
  //Possible cases:
  //List has no nodes
  if(m_size == 0){
    cout << "No nodes to remove" << endl;
    return;
  }
  //List has one Node
  if(m_size == 1){ // Delete m_head, set to nullptr, and decrement m_size
    delete m_head;
    m_head = nullptr;
    m_size--;
    return;
  }
  //List has multiple nodes
  Node* temp = m_head; // temp keeps track of first Node to prevent leaks when moving m_head
  m_head = m_head->m_next; // move m_head to the next Node in the list
  delete temp; // delete the old first Node
  temp = nullptr; // temp isn't needed anymore, nullptr
  m_size--; // update size
}

void LinkedList::Display() {
  //Possible Cases:
  //List is empty
  if (m_size == 0) {
    cout << "The team is empty!" << endl;
  } else {
    //List has nodes
    cout << "This team has " << m_size << " players." << endl;
    Node* temp = m_head; // temp iterates list to print m_info for each Node
    while (temp != nullptr) {
      cout << temp->m_info << "->";
      temp = temp->m_next;
    }//end while
    cout << "END" << endl;
  }//end else
}

//No errors in main
int main() {
  LinkedList list; //Create a new linked list
  list.Display(); //Empty list
  list.RemoveFront(); //Attempt to remove a Node from an empty list
  
  // Insert several nodes into the linked list
  list.InsertEnd("Ana");
  list.InsertEnd("Soldier:76");
  list.InsertEnd("Roadhog");
  list.InsertEnd("Juno");
  list.InsertEnd("Genji");
  list.Display(); //Should display 5 nodes

  //Remove nodes from the list
  list.RemoveFront();
  list.RemoveFront();
  list.Display(); //Should display 3 nodes

  return 0;
}
