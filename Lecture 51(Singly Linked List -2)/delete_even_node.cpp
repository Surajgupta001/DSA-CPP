/*
Write a Program to delete all even nodes from a Singly Linked List.

Input: LL = 1 -> 4 -> 3 -> 18 -> 19 
Output: 1 -> 3 -> 19

Input: LL = 5 -> 3 -> 6 -> 8 -> 4 -> 1 -> 2 -> 9 
Output: 5 -> 3 -> 1 -> 9 
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
        node *newNode = new node(value);
        // If linked List is empty
        if(head == nullptr){
            head = newNode;
            return;
        } 

        node *temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display(){
        node *temp = head;
        while(temp != nullptr){
            cout<<temp->value<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void deleteEvenNodes(){
        if(head == nullptr){
            return;
        }
        
        // In case of, where the head node as an even value
        while(head != nullptr && head -> value %2 == 0){
            node *temp = head;
            head = head->next;
            free(temp);
        }

        node *curr = head;
        while(curr != nullptr && curr -> next != nullptr){
            if(curr->next->value % 2 == 0){
                node *temp = curr->next;
                curr->next = curr->next->next;
                free(temp);
            }
            else{
                curr = curr->next;
            }
        }
    }
};

int main(){
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(4);
    ll.insertAtTail(3);
    ll.insertAtTail(18);
    ll.insertAtTail(19);

    cout<<"Original Linked List: ";
    ll.display();

    ll.deleteEvenNodes();
    cout<<"Linked List after deleting even nodes: ";
    ll.display();

    return 0;
}