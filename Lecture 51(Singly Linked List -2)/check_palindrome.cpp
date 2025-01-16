/*
Check palindrome or not.(LEETCODE - 234)
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

bool isPalindrome(node *head){

    // step1. find middle element
    node *slow = head;
    node *fast = head;
    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    // now slow is pointing to middle elment
    // step2. break the linked list in the middle
    node *curr = slow -> next;
    node *prev = slow;
    slow -> next = nullptr;

    // step3. reverse the second half of linked list
    while(curr){
        node *next_node = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next_node;
    }

    // step4. check if two linked list are equal
    node *head1 = head;
    node *head2 = prev;
    while(head2){
        if(head1 -> value != head2 -> value){
            return false;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    return true;
}

int main(){
    
    LinkedList ll;
    
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(3);
    ll.insertAtTail(2);
    ll.insertAtTail(1);
    ll.display();
    cout<<isPalindrome(ll.head)<<endl;

    return 0;

}