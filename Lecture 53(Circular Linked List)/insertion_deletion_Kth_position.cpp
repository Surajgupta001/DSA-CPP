#include <iostream>
using namespace std;

class node{
    public:
    int value;
    node *next;

    node (int data){
        value = data;
        next = nullptr;
    }
};

class CircularLinkedList{
    public:
    node *head;
    CircularLinkedList(){
        head = nullptr;
    }
    
    void display(){
        node *temp = head;
        do
        {
            cout<<temp->value<<" ";
            temp = temp -> next;
        } while (temp != head); 
        cout<<endl;
    }

    // insertion of node at the starting of node
    void insertAtStart(int value){

        node *new_node = new node(value);

        if(head == nullptr){
            head = new_node;
            new_node -> next = head; // circular linked list
            return;
        }
        node *tail = head;
        while(tail -> next != head){
            tail = tail -> next;
        }
        // now tail is present to the last node
        tail -> next = new_node;
        new_node -> next = head;
        head = new_node;
    }

    // insertion of node at the starting of node
    void insertAtEnd(int value){
        
        node *new_node = new node(value);

        if(head == nullptr){
            head = new_node;
            new_node -> next = head; // circular linked list
            return;
        }
        node *tail = head;
        while(tail -> next != head){
            tail = tail -> next;
        }
        // here tail will be pointing to last node
        tail -> next = new_node;
        new_node -> next = head; // update the next pointer of new_node to head
    }

    // Deletion of node at starting of node
    void deleteAtStart(){
        if(head == nullptr){
            return;
        }
        node *temp = head;
        node *tail = head;
        while(tail -> next != head){
            tail = tail -> next;
        }
        head = head -> next;
        tail -> next = head;
        free(temp);
    }

    // Deletion of node at ending of node
    void deleteAtEnd(){
        if(head == nullptr){
            return ;
        }
        node *tail = head;
        while(tail -> next -> next != head){
            tail = tail -> next;
        }
        // here tail is pointing to the second last node
        node *temp = tail -> next; // to be deleted
        tail -> next = head;
        free(temp);
    }
};

int main(){

    CircularLinkedList cll;

    // insertion of node at the starting of node
    cll.insertAtStart(3);
    cll.insertAtStart(2);
    cll.insertAtStart(1);
    cll.display();

    // insertion of node at the ending of node
    cll.insertAtEnd(8);
    cll.display();

    // deletion of node at the starting of node
    cll.deleteAtStart();
    cll.display();

    // deletion of node at the ending of node
    cll.deleteAtEnd();
    cll.display();

    return 0;
}