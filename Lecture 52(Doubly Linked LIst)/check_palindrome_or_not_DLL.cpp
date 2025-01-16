/*
Given the head of a doubly linked list, find if it's a palindrome or not.
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

    bool isPalindrome(node *head, node *tail){
        while(head != tail && tail != head->prev){
            if(head -> value != tail -> value){
                return false;
            }
            else{
                head = head -> next;
                tail = tail -> prev;
            }
        }
        return true;
    }
};
int main(){

    DoublyLinkedList dll;
    cout<<"Inserted Linked List: ";
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.insertAtEnd(3);
    dll.insertAtEnd(2);
    dll.insertAtEnd(1);
    dll.display();

    cout<<"isPalindrome: "<<dll.isPalindrome(dll.head, dll.tail)<<endl;

    return 0;
}