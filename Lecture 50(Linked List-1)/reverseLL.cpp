/*
Given the head of a singly linked list, and print the reversed list.
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

node *reverseLL(node* &head){
    node *prevptr = nullptr;
    node *currptr = head;
    
    // curr_ptr->next = prev_ptr;
    // move all 3 ptrs by one step ahead
    // repeat this process until curr_ptr != nullptr
    while(currptr != nullptr){
        node *nextptr = currptr -> next;
        currptr -> next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }

    // when this loops ends, prevptr pointing to my last node which is new head
    node *new_head = prevptr;
    return new_head;
}

int main(){

    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.display();

    ll.head = reverseLL(ll.head);
    ll.display();

    return 0;
}