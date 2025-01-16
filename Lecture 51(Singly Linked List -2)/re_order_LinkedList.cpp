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

node *reorderLinkedList(node* &head){

    // can check if linked list has atleast 3 nodes

    // 1. finding the middle element
    node *slow = head;
    node *fast = head;
    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    // now slow is pointing to the middle element
    // 2. seperate the linked list and remove second half
    node *curr = slow -> next;
    slow -> next = nullptr;
    node *prev = slow;
    while(curr){
        node *nextptr = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nextptr;
    }
    // 3. merging the two halves of the linked list
    node *ptr1 = head; // linked list first half 
    node *ptr2 = prev; // linked list second half
    while(ptr1 != ptr2){
        node *temp = ptr1 -> next;
        ptr1 -> next = ptr2;
        ptr1 = ptr2;
        ptr2 = temp;
    }
    return head;
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

    ll.head = reorderLinkedList(ll.head);
    ll.display();

    return 0;
}