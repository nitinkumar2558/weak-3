#include <iostream>
using namespace std;

// Generic Programming - Ignore 

class Node{
    public:
    // Data 
    int data;
    // Pointer to the next Node
    Node * next;
    // Construct that makes the ptr to NULL
    Node(int value){
        next = NULL;
        data = value;
    }
};

class CSLL{
    public:
    Node * head;
    CSLL(){
        head = NULL;
    }
//..................................................................
    // Inserts to the end of the linked list.
    void insert(int value){
        
        // Create a new node
        Node * temp = new Node(value);
        // CHeck if empty list
        if(head == NULL){
            head = temp;
        }  
        else{ // If not empty list. 
            Node * current = head;
            while(current->next != head)
                current = current->next;
            current->next = temp;
        }
        temp->next = head;
    }
//...............................................................
    // Displays the linked list.
    void display(){
        Node * current = head;
        if(current == NULL) {
            cout << "No elements " << endl;
            return;
        }
        while(current->next != head){ // Stopping at head
            cout << current -> data << "->";
            current = current -> next;
        }
        // Printing the last element
        cout << current -> data ;
        cout << endl;
    }
//................................................................
    void InsertAt(int value, int pos){
         // insert at any position 

	  // Reach the place before the pos
        Node * current = head;
        int i =1;
        while(i < pos-1){
            i++;
            current = current->next;
        }

        // Create a node
        Node * temp = new Node(value);
     
        // Moving ptrs like magic ! if not head
  temp->next=current->next;
        current->next = temp;
	
      
    
    }
//.........................................................
    void DeleteAt(int pos){
//reach the position just before the pos element ,,if we have to delete 3rd then we are at 2nd position
        Node * current = head;
   int i=1;
        while(i<pos-1){
      i++;
     current = current->next;
     }

       //difine new pointer store pos address
    Node * ptr;
//new pointer point to node which we have to delete
   ptr=current-> next;
//delete using ptr,currnt
	current->next=ptr->next;
	  
  	// delete ptr
	delete ptr;
    
    }
//,.............................................................
    void Delet(){
        
 // Deletes the last element.

//reach .....second last..... position
        Node * current = head;
        while(current->next->next != head){
            current = current->next;
        }
//make null the pointer which point further
        current->next = head; 
    }
//..................................................................
    void CountItems(){
       
 // Counts the Number of items.
	Node*current=head;
		int i=1;

	while(current->next!=head){
	current=current->next;
	i++;
	}
cout<<"number of elements are"<< i<<endl;

    }
//...............................................................

};

int main(){
    CSLL csll1;
    for(int i= 1; i < 11; i++){
       csll1.insert(i);
    }
    csll1.display();

cout<<"insert 5 at 5th position"<<endl;
    csll1.InsertAt(5,5);
 csll1.display();

cout<<"delete 5th potion element"<<endl;
   csll1.DeleteAt(5);
 csll1.display();

cout<<"deleting last element"<<endl;
    csll1. Delet();
 csll1.display();


   csll1.CountItems();


}

