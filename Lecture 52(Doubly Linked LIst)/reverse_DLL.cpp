/*
Given the head of a doubly linked list, reverse it.
*/ 
#include <iostream>
using namespace std;

class node{
    public:
    int value;
    node *prev;
    node *next;

    // construtor
    node (int data){
        value = data;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList{
    public:
    node *head;
    node *tail;

    DoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void display(){
        node *temp = head;
        while(temp != nullptr){
            cout<<temp -> value<<" ";
            temp = temp -> next;
        }
        cout<<endl;
    }

    void insertAtEnd(int value){
        node *new_node = new node(value);
        // check if linked list is empty
        if(head == nullptr){
            head = new_node;
            tail = new_node;
            return;
        }
        // if linked list is not empty
        tail -> next = new_node;
        new_node -> prev = tail;
        tail = new_node;
        return;
    }
};

void reverseDll(node *&head, node *&tail){
    node *currptr = head;
    while(currptr){
        node *nextptr = currptr -> next;
        currptr -> next = currptr -> prev;
        currptr -> prev = nextptr;
        currptr = nextptr;
    }
    // swaping head and tail pointer
    node *newHead = tail;
    tail = head;
    head = newHead;
}
int main(){

    DoublyLinkedList dll;
    cout<<"Inserted Linked List: ";
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.insertAtEnd(4);
    dll.display();

    cout<<"Reversed Linked List: ";
    reverseDll(dll.head, dll.tail);
    dll.display();

    return 0;
}