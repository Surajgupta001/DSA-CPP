/*
Given the head of a singly linked list, revserse the node of the list at a time, and return the modified list.
*/ 

#include <iostream>
using namespace std;

class node{
    public:
    int value;
    node *next;

    node(int data){
        value = data;
        next = nullptr;
    }
};

class LinkedList{
    public:
    node *head;

    LinkedList(){
        head = nullptr;
    }

    void insertAtTail(int value){

        node *new_node = new node(value);
        if(head == NULL){ // linkedlist is empty
        head = new_node;
        return;
        }

        node *temp = head;
        while(temp -> next != nullptr){
            temp = temp -> next;
        }
        temp -> next =  new_node;
    }
    
    void display(){
        node *temp = head;
        while(temp != NULL){
            cout<<temp -> value<<"->";
            temp = temp -> next;
        }
        cout<<"NULL"<<endl;
    }
};

node* revserseKLL(node* &head, int k){
    node *prevptr = nullptr;
    node *currptr = head;

    int counter = 0; // for counting first k nodes
    while( currptr != nullptr && counter < k){ // reversing first k node
        node *nextptr = currptr -> next;
        currptr -> next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        counter++;
    }
    // currptr will give us (k+1)th node
    if(currptr != nullptr){
        node *new_head = revserseKLL(currptr, k);
        head -> next = new_head;
    }
    return prevptr; // prevptr wiil give the new_head of connected lnkedlists
}

int main(){

    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);
    ll.display();

    ll.head = revserseKLL(ll.head,3);
    ll.display();

    return 0;
}