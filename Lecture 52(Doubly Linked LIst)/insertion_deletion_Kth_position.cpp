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

class DoublyLiNKedList{
    public:
    node *head;
    node *tail;

    DoublyLiNKedList(){
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

    // Insertion of node at the starting of node
    void insertAtStart(int value){
        node *new_node = new node(value);
        // if Linked List is empty
        if(head == nullptr){
           head = new_node;
           tail = new_node;
           return; 
        }
        // if Linked List is not empty
        new_node -> next = head;
        head -> prev = new_node;
        head = new_node;
        return;
    }

    // Insertion of node at the ending of node
    void insertAtEnd(int value){
        node *new_node = new node(value);
        // if linked list is empty
        if(tail == nullptr){
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

    // Insertion of node at the arbitary of node
    void insertAtArbitayPosition(int value, int k){
        // assuming k is less or equal to length of doubly linked list
        node *temp = head;
        int count = 1;
        while(count < (k-1)){
            temp = temp -> next;
            count ++;
        }
        // temp will be pointing to the node at (k-1)th position
        node *new_node = new node(value);
        new_node -> next = temp -> next;
        temp -> next = new_node;
        new_node -> prev = temp;
        new_node -> next -> prev = new_node;
        return;
    }

    // Deletion of node at the starting of node
    void deleteAtStart(){

        // if linked list is empty
        if(head == nullptr){
            return;
        }
        // if any 1 node is present
        node *temp = head;
        head = head -> next;
        // if doubly linked list had only 1 node
        if(head == nullptr){
            tail = nullptr;
        }
        else{
            head -> prev = nullptr;
        }
        free(temp);
        return;
    }

    // Deletion of node at the ending of node
    void deleteAtEnd(){
        // if linked list is empty
        if(head == nullptr){
            return;
        }
        node *temp = tail;
        tail = tail -> prev;
        if(tail == nullptr){
            head = nullptr;
        }
        else{
            tail -> next = nullptr;
        }
        free(temp);
        return ;
    }

    // Deletion of node at the arbitary of node
    void deleteAtArbitaryPosition(int k){
        // assuming k is less than or equal to length of dll
        node *temp = head;
        int counter = 1;
        while(counter < k){
            temp = temp -> next;
            counter++;
        }
        // now temp is pointing to node at kth position
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        free(temp);
        return;
    }
};

int main(){

    DoublyLiNKedList dll;
    
    // Insertion of node at the starting of node
    // dll.insertAtStart(1);
    // dll.display();
    // dll.insertAtStart(2);
    // dll.display();
    // dll.insertAtStart(3);
    // dll.display();

    // Insertion of node at the ending of node
    dll.insertAtEnd(1);
    dll.display();
    dll.insertAtEnd(2);
    dll.display();
    dll.insertAtEnd(3);
    dll.display();

    // Insertion of node at the arbitary of node
    dll.insertAtArbitayPosition(4,3);
    dll.display();

    // Deletion of node at starting of node
    dll.deleteAtStart();
    dll.display();

    // Deletion of node at ending of node
    dll.deleteAtEnd();
    dll.display();

    // Deletion of node at the arbitary of node
    dll.deleteAtArbitaryPosition(3);
    dll.display();

    return 0;
}