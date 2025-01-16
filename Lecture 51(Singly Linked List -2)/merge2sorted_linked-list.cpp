/*
Given 2 sorted linked list, merge them into 1 singly list such that the resulting list is also sorted.
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

node* mergeLinkedLists(node* &head1, node* &head2){
    node *dummyHeadNode = new node(-1);

    node *ptr1 = head1;
    node *ptr2 = head2;
    node *ptr3 = dummyHeadNode;

    while(ptr1 && ptr2){
        if(ptr1 -> value < ptr2 -> value){
            ptr3 -> next = ptr1;
            ptr1 = ptr1 -> next;
        }
        else{
            ptr3 -> next = ptr2;
            ptr2 = ptr2 -> next;
        }
        ptr3 = ptr3 -> next;
    }
    if(ptr1){
        ptr3 -> next = ptr1;
    }
    else{
        ptr3 -> next = ptr2;
    }
    return dummyHeadNode -> next;
}

int main(){

    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    ll1.display();

    LinkedList ll2;
    ll2.insertAtTail(2);
    ll2.insertAtTail(3);
    ll2.display();

    LinkedList ll3;
    ll3.head = mergeLinkedLists(ll1.head, ll2.head);
    ll3.display();

    return 0;
}