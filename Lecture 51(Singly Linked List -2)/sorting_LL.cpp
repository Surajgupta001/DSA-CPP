/*
SORTING A SINGLY LINKED LIST
=====================================
Given a Linked List, the task is to sort this Linked List in ascending order.

INPUT: 10->30->20->5
OUTPUT: 5->10->20->30

INPUT: 20->4->3
OUTPUT: 3->4->20
*/ 

#include <iostream>
using namespace std;

class node{
    public:
    int value;
    node *next;

    // constructor
    node(int data){
        value = data;
        next = nullptr;
    }
};

class Linkedlist{
    public:
    node *head;

    Linkedlist(){
        head = nullptr;
    }

    void insertAtTail(int value){
        node *new_node = new node(value);
        // if linked listb is empty
        if(head == nullptr){
            head = new_node;
            return;
        }

        node *temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display(){
        node *temp = head;
        while(temp != nullptr){
            cout <<temp->value<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void bubbleSort(){
        
        node *left_ptr = head;
        node *right_ptr = nullptr;

        if(head == nullptr){
            return;
        }

        while(left_ptr != nullptr){
            right_ptr = left_ptr->next;
            while(right_ptr != nullptr){
                if(left_ptr->value > right_ptr->value){
                    int temp = left_ptr->value;
                    left_ptr->value = right_ptr->value;
                    right_ptr->value = temp;
                }
                right_ptr = right_ptr->next;
            }
            left_ptr = left_ptr->next;
        }
    }
};

int main(){

    Linkedlist ll;

    ll.insertAtTail(10);
    ll.insertAtTail(30);
    ll.insertAtTail(20);
    ll.insertAtTail(5);

    cout<<"Before Sorting: ";
    ll.display();

    ll.bubbleSort();
    cout<<"After sorting: ";
    ll.display();

    return 0;
}