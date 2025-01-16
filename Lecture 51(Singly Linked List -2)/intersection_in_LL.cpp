/*
Given the head of two singly linked list headA and headB, return the nide at which the two list intersect. If the two linked list have no intersection at all, return null.
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

int getLength(node *head){
    node *temp = head;
    int length = 0;
    while(temp != nullptr){
        length++;
        temp = temp -> next;
    }
    return length;
}

node *moveHeadByK(node *head, int k){
    node *ptr = head;
    while(k--){
        ptr = ptr -> next;
    }
    return ptr;
}

node *getIntersection(node *head1, node *head2){

    // step1: Calculate lengths of both linked lists
    int l1 = getLength(head1);
    int l2 = getLength(head2);
    
    // step2: find difference between Linked List and move longer linked ptr by k steps
    node *ptr1, *ptr2;
    if(l1 > l2){ //LL1 is longer
        int k = l1 - l2;
        ptr1 = moveHeadByK(head1,k);
        ptr2 = head2;
    }
    else{ // LL2 is longer
    int k = l2 - l1;
    ptr1 = head1;
    ptr2 = moveHeadByK(head2,k);
    }
    // step3: compare ptr1 and ptr2
    while(ptr1){
        if(ptr1 == ptr2){
            return ptr1;
        }
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }
    return nullptr;
}

int main(){

    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    ll1.display();
    // 1->2->3->4->5->nullptr;

    LinkedList ll2;
    ll2.insertAtTail(6);
    ll2.insertAtTail(7);
    ll2.head -> next -> next = ll1.head -> next -> next -> next;
    // 6->7->4->5->nullptr
    ll2.display();

    node *intersection = getIntersection(ll1.head,ll2.head);
    if(intersection){
        cout<<intersection -> value <<endl;
    }
    else{
        cout<<"-1"<<endl;
    }

    return 0;
}