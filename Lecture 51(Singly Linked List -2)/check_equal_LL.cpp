/*
Given 2 linked lists, tell if they are equal or not. Two linked list are equal if they have the same data and data the arrangment of data is also the same.
*/ 
/*
Linked List equal means: 
1. nodes have equal value.
2. length should be same.
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

    // constructor
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

bool checkEqualLinkedList(node *head1, node *head2){
    node *ptr1 = head1;
    node *ptr2 = head2;
    while(ptr1 != nullptr && ptr2 != nullptr){
        if(ptr1 -> value != ptr2 -> value){
            return false;
        }
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }
    // at this point either ptr1 is null, or ptr2 is null, or both are null
    return (ptr1 == nullptr && ptr2 == nullptr);
}

int main(){

    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);

    LinkedList ll2;
    ll2.insertAtTail(1);
    ll2.insertAtTail(2);
    ll2.insertAtTail(3);
    ll2.insertAtTail(4);
    ll2.insertAtTail(5);

    ll1.display();
    ll2.display();

    cout<<checkEqualLinkedList(ll1.head, ll2.head)<<endl;
    return 0;
}