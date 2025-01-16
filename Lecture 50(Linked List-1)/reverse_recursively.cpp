/*
Given the head of a singly linked list, reverse the list and return the reversed list.
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
    
    // currptr -> next = prevptr;
    // move all 3 ptrs by one step ahead
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

node *reverseLLRecursion(node *&head){
    // base case
    if(head == nullptr || head -> next == nullptr){
        return head;
    }
    // recursive case
    node *new_head = reverseLLRecursion(head -> next);
    head -> next -> next = head;
    head -> next = nullptr;
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

    ll.head = reverseLLRecursion(ll.head);
    ll.display();

    return 0;
}