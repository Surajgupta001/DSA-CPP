/*
Given the head of a sorted linked list, delete all duplicate such that each element appear only once. Rerurn the linked list sorted as well.
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
        if(head == nullptr){ // linkedlist is empty
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
        while(temp != nullptr){
            cout<<temp -> value<<"->";
            temp = temp -> next;
        }
        cout<<"NULL"<<endl;
    }
};

void deleteDuplicateNodes(node* &head){
    node *curr_node = head;
    while(curr_node){
        while(curr_node -> next && curr_node -> value == curr_node -> next -> value){
            // delete curr_node -> next
            node *temp = curr_node -> next; // node to be deleted
            curr_node -> next = curr_node -> next -> next;
            free(temp);
        }
        // this loop ensd when current node and next node value are different
        // or linked list ends
        curr_node = curr_node -> next;
    }
}

int main(){

    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(3);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.display();

    deleteDuplicateNodes(ll.head);
    ll.display();

    return 0;
}