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

void reversePrint(node *head){
    // base case
    if(head == nullptr) return;

    // recursive case
    reversePrint(head -> next);
    cout<<head -> value<<"->";
}

int main(){

    LinkedList ll;
    cout<<"Inserting element: ";
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.display();

    cout<<"Reverse Order is: ";
    reversePrint(ll.head);

    return 0;
}