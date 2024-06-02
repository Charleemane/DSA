
//--Declaration--//
//first declare a data structure that will hold the nodes//
//next declare a pointer as head of list//
//you will have an empty linkedlist once you have a node datastruct and NULL head ptr;

/*#include <iostream>
using namespace std;

class FloatList {
    private:
    
  struct ListNode
  {
	float value;
	struct ListNode *next;
  };
  
  ListNode *head;		
  
    public:
    FloatList ();
  {
	head = NULL;
  }
   ~FloatList ();
  void appendNode (float num);
  void insertNode (float num);
  void deleteNode (float num);
  void displayList ();
};*/



#include<iostream>
using namespace std;

// Create a data structure to be used as node for the list
struct Nodes{
    // Data member
    int value;

    // Pointer
    Nodes *next;
}*head = NULL, *node, *current, *previous, *nextptr; // Declare the head pointer, initialize to NULL

// Nodes *head = NULL, *node, *current, *previous;

// Declare linked list operation function prototypes
void appendNode(int); // Appending a node to the end of the list
void displayList(); // Traverse and display the list
void insertNode(int); // Insertion of a node to the list with some condition (sort)
void deleteNode(int); // Remove a node from the list
void destroyList(); // Destroys (remove from the memory) the entire list

int main(){
    // system("cls");
    int newValue;
    while(true){
        // Input a new value to be inserted to the list
        cout << "Enter a value to be inserted[-1 to end]: ";
        cin >> newValue;
        if(newValue < 0) break; // Stop adding new value to the list
        // Call the function to append the new node
        // appendNode(newValue);
        
        // Call the function to insert the new node in its proper position
        insertNode(newValue);
    }
    displayList();

    cout << "Enter value to be deleted: ";
    cin >> newValue;
    deleteNode(newValue);
    cout << "\nAfter deletion...\n";
    displayList();

    destroyList();
    cout << "\nAfter destroying the list...\n";
    displayList();
}

// Function definitions of the linked list operations
void appendNode(int val){
    node = new Nodes; // Creating the node
    node->value = val; // Set values of data members
    node->next = NULL;

    // Check if the list is empty
    if(head == NULL){
        // The list is empty, point head to new node
        head = node;
    }else{
        // Start from the beginning of the list
        current = head;
        // Traverse the linked list until it reaches the last node
        while(current->next != NULL){
            // Go to the next node in the list
            current = current->next;
        }
        // If the loop reaches the last node, append the new node
        current->next = node;
    }
    cout << "New node is appended...\n";
}

void displayList(){
    current = head; // Assign the head node as the current node
    if(current == NULL){
        cout << "\nList is empty....\n";
    }else{
        cout << "\nDisplaying the values in the list...\n";
        while(current != NULL){ // Traverse the list until last node
            cout << current->value << endl; // Display the data member
            current = current->next; // Go to the next node
        }
        cout << "End of list...\n\n";
    }
}

void insertNode(int val){
    node = new Nodes;
    node->value = val;
    node->next = NULL;

    if(head == NULL){
        head = node;
    }else{
        current = head;
        previous = NULL;
        // < - sort the list ascending
        // > - sort the list descending
        while(current != NULL && current->value < val){
            previous = current;
            current = current->next;
        }
        // If the correct position is found, insert the new node
        if(previous == NULL){
            // Insert the new node in the start of the list
            head = node;
            node->next = current;
        }else{
            // Insert the new node in its correct position
            previous->next = node; // break the node for the meantime
            node->next = current; // Reconnect the nodes to the list
        }
    }
    cout << "New node is inserted...\n";
}

void deleteNode(int val){
    bool found = false;
    if(head == NULL){
        cout << "The list is empty...\n";
    }else{
        // current = head;
        // The condition would be: current->value == val
        if(head->value == val){ // If the the node to be deleted is the first node
            current = head->next;
            delete head;
            head = current;
            // head = current->next;
            // delete current;
            found = true;
        }else{
            current = head;
            previous = NULL;
            // Traverse the list until the value to be deleted is found or until
            // the end of the list
            while(current != NULL && current->value != val){
                previous = current;
                current = current->next;
            }
            // If the node to be deleted is found
            if(current != NULL){
                // Break the link for the meantime then reconnect it
                // by connecting the node before the value to be deleted
                // the the node after the value to be deleted.
                previous->next = current->next;
                // Delete the node
                delete current;
                found = true;
            }

            if(found){
                cout << "Node has been deleted..\n\n";
            }else{
                cout << "Value is not found in the list..\n\n";
            }
        }
    }
}

void destroyList(){
    if(head == NULL){
        cout << "List is empty...";
    }else{
        current = head;
        // Delete all nodes from the list
        while(current != NULL){
            nextptr = current->next;
            delete current;
            current = nextptr;
        }
        cout << "List is now destroyed....\n";
        head = NULL;
    }
}
