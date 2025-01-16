/*
Pattern: Slow and fast pointer
Find the middle element of the linked list.
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

node *findMiddleElement(node* &head){
    node *slow = head;
    node *fast = head;

    while(fast != nullptr && fast -> next != nullptr){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
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

    node *middleNode = findMiddleElement(ll.head);
    cout<<"Middle element of linked list is: "<<middleNode->value<<endl;

    return 0;

}