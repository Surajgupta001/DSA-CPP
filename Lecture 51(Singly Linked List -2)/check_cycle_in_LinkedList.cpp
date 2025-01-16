/*
Pattern: Slow and fast pointer
Given head, the head of a linked list determine if the linked list has a cycle in it.
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

bool detectCycle(node *head){

    if(!head){
        return false;
    }

    node *slow = head;
    node *fast = head;

    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
        
        if(slow == fast){
            cout<<slow->value<<endl;
            return true; // i.e. cycle is present.
        }
    }
    return false; // i.e. cycle is not present.
}

void removeCycle(node* &head){ // assuming that the linked lisr has a cycle

    node *slow = head;
    node *fast = head;
    
    do
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    } while (slow -> next != fast-> next);
    
    fast = head;
    while(slow -> next != fast -> next){
        slow = slow -> next;
        fast = fast -> next;
    }

    slow -> next = nullptr;
    
}

int main(){
    
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);
    ll.insertAtTail(7);
    ll.insertAtTail(8);
    ll.display();

    cout<<"Value is: ";
    ll.head -> next -> next -> next -> next -> next -> next -> next -> next = ll.head -> next -> next;
    cout<<detectCycle(ll.head)<<endl;

    removeCycle(ll.head);
    cout<<"After removing cycle: "<<endl;

    cout<<detectCycle(ll.head)<<endl;
    ll.display();

    return 0;

}