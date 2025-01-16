/*
Given the head of a linked list, delete every alternate element from the list starting from the second element.
*/
#include <iostream>
using namespace std;

class node{
    public:
    int value;
    node *next;

    node(int data){
        value = data;
        next = NULL;
    }
};

class LinkedList{
    public:
    node *head;

    LinkedList(){
        head = NULL;
    }
    void insertAtTail(int value){

        node *new_node = new node(value);
        // linked List is empty
        if(head == NULL){
        head = new_node;
        return;
        }
        // traverse of linked list for tail insertion
        node *temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        // temp has reached last node
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

void deleteAlternateNode(node* &head){
    node *curr_node = head;
    while(curr_node != NULL && curr_node -> next != NULL){
        node* temp = curr_node -> next; // this is the node to be deleted
        curr_node -> next = curr_node -> next -> next;
        free(temp);
        curr_node = curr_node -> next;
    }
}

int main(){

    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.display();

    deleteAlternateNode(ll.head);
    ll.display();

    return 0;
}