/*
Given the head of a linked list, remove the kth-node from the end of the list and return its head.
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
        // linked List is empty.
        if(head == NULL){
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

// assume k is always less than/equal length of linked list
void removeKthNodeFromEnd(node* &head, int k){

    node *ptr1 = head;
    node *ptr2 = head;

    // move ptr2 by k steps ahead
    int count = k;
    while(count--){
        ptr2 = ptr2 -> next;
    }

    if(ptr2 == NULL){ // k is equal to length of Linked List
        // we have to delete head node
        node *temp = head;
        head = head -> next;
        free(temp);
        return;
    }
    // move ptr1 by k steps of ptr1
    // when ptr2 is at null (end of list), ptr1 will be at node to be deleted
    while(ptr2 -> next != NULL){
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }
    // now ptr1 is pointing to the node before kth node from end
    // node to be deleted is ptr1 -> next
    node *temp = ptr1 -> next;
    ptr1 -> next = ptr1 -> next -> next;
    free(temp);
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

    removeKthNodeFromEnd(ll.head,3);
    ll.display();
    
    return 0;
}