#include <iostream>
using namespace std;

class node{

    public:
    int value;
    node* next;

    // constructor
    node(int data){
        value = data;
        next = NULL;
    }
};

// insert function head
void insertAtHead(node* &head, int value){
    node* new_node = new node(value);
    new_node -> next = head;
    head = new_node;
}

// insert function tail
void insertAtTail(node* &head, int value){
    node* new_node = new node(value);
    // traverse of linked list for Tail insertion
    node* temp = head;
    while(temp -> next != NULL){
        temp = temp->next;
    }
    // temp has reached last node
    temp -> next = new_node;
}

// insert function arbitary postion
void insertAtArbitaryPosition(node* &head, int value, int pos){
    if(pos == 0){
        insertAtHead(head,value);
        return;
    }
    node* new_node = new node (value);
    node* temp = head;
    int current_pos = 0;
    while(current_pos != pos-1){
        temp = temp -> next;
        current_pos++;
    }
    // temp is pointing to node at pos-1;
    new_node -> next = temp -> next;
    temp -> next = new_node;
}

// updatation of kth position
void updateAtPosition(node* &head, int kth, int value){
    node* temp = head;
    int curr_pos = 0;
    while(curr_pos != kth){
        temp = temp -> next;
        curr_pos++;
    }
    // temp will be pointing to the kth node
    temp -> value = value;
} 

// Deletation function of HEAD
void deleteAtHead(node* &head){
    node* temp = head; // node to be deleted
    head = head -> next;
    free(temp);
}

// Deletation function of TAIL
void deleteAtTail(node* &head){
    node* second_last = head;
    while(second_last -> next -> next != NULL){
        second_last = second_last -> next;
    }
    // now second_last point to second last node
    node* temp = second_last -> next; // node to be deleted
    second_last -> next = NULL;
    free(temp);
}

// delete of kth position
void deleteAtPosition(node* &head, int pos){
    if(pos == 0){
        deleteAtHead(head);
        return;
    }
    int curr_pos = 0;
    node* prev = head;
    while(curr_pos != pos-1){
        prev = prev -> next;
        curr_pos++;
    }
    // prev is pointing to node at pos-1;
    node* temp = prev -> next;
    prev -> next = prev -> next -> next;
    free(temp);
}

// traverse of linked list
void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp -> value<<" -> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}
int main(){

    node* head = NULL;

    // Insertion of HEAD
    insertAtHead(head,2);
    display(head);
    insertAtHead(head,1);
    display(head);

    // Insertion of TAIL
    insertAtTail(head,3);
    display(head);

    // Insertion of ARBITARY POSITION
    insertAtArbitaryPosition(head,4,1);
    display(head);

    // updatation of kth position
    updateAtPosition(head,2,5);
    display(head);
    
    // Delete at HEAD
    deleteAtHead(head);
    display(head);

    // Delete at TAIL
    deleteAtTail(head);
    display(head);

    // Deletion at arbitary position
    deleteAtPosition(head,1);
    display(head);

    return 0;
}