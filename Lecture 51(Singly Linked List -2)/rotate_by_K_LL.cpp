/*
Given the head of a linked list, rotate the list to the right by k places.
*/ 
#include <iostream>
using namespace std;
#include <vector>

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
        if(head == NULL){ // linked List is empty
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

node *rotateByK(node* &head, int k){

    // step1. Find length of ll
    int n = 0;
    // step2. Find tail node
    node *tail = head; 

    while(tail -> next){
        n++; // finding length
        tail = tail -> next; // finding last nide
    }
    n++; // for including last node

    k = k %n;
    if(k == 0){
        return head;
    }
    tail -> next = head;
    // 3. traverse n-k nodes
    node *temp = head;
    for(int i=1;i<n-k;i++){
        temp = temp -> next;
    }
    // temp is now pointing (to n-k)th node
    node *newhead = temp -> next;
    temp -> next = nullptr;
    return newhead;
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

    ll.head = rotateByK(ll.head,3);
    ll.display();

    return 0;

}