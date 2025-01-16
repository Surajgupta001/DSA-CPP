/*

*/
#include <iostream>
using namespace std;
#include <vector>
#include <limits.h>

class node{
public:
    int value;
    node *prev;
    node *next;

    // construtor
    node(int data){
        value = data;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList{
public:
    node *head;
    node *tail;

    DoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void display(){
        node *temp = head;
        while (temp != nullptr){
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insertAtEnd(int value){
        node *new_node = new node(value);
        // check if linked list is empty
        if (head == nullptr){
            head = new_node;
            tail = new_node;
            return;
        }
        // if linked list is not empty
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        return;
    }
};

vector<int>pairSumDLL(node *&head, node *&tail, int x){
    vector<int>ans(2,-1);
    while(head != tail){
        int sum = head -> value + tail -> value;
        if(sum == x){
            ans[0] = head -> value;
            ans[1] = tail -> value;
            return ans;
        }
        else if(sum > x){ // i need smaller values, i will move by tail back
            tail = tail -> prev;
        }
        else{ // i need bigger value, i will move forward
            head = head -> next;
        }
    }
    return ans;
}

int main(){

    DoublyLinkedList dll;
    cout << "Inserted Linked List: ";
    dll.insertAtEnd(2);
    dll.insertAtEnd(5);
    dll.insertAtEnd(6);
    dll.insertAtEnd(8);
    dll.insertAtEnd(10);
    dll.display();

    vector<int>ans = pairSumDLL(dll.head, dll.tail, 11);
    cout<<ans[0]<<endl<<ans[1];

    return 0;
}