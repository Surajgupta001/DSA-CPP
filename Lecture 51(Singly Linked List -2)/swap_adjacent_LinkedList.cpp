/*

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

node *swapAdjacent(node* &head){
    // base case
    if(head == nullptr || head -> next == nullptr) return head;
    // recursive case
    node *secondNode = head -> next;
    head -> next = swapAdjacent(secondNode -> next);
    secondNode -> next = head; // reversing the link between first and second node
    return secondNode;
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

    ll.head = swapAdjacent(ll.head);
    ll.display();

    return 0;

}