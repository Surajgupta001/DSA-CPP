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
class Queue{
    node *head;
    node *tail;
    int size;

public:
    Queue(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void Enqueue(int data){
        node *newNode = new node(data);
        if(head == nullptr){
            // if LL is empty
            head = tail = newNode;
        }
        else{
            // if LL is not empty
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void Dequeue(){
        if(head == nullptr){
            // LL is empty
            return;
        }
        else{
            node *oldHead = head;
            node *newHead = head->next;
            head = newHead;
            if(head == nullptr) tail = nullptr;
            oldHead->next = nullptr;
            delete oldHead;           
        }
    }

    int getsize(){
        return size;
    }

    bool isEmpty(){
        return head == nullptr;
    }

    int front(){
        if(head == nullptr) return -1;
        return head->value;
    }
};
int main(){
    
    Queue qu;
    qu.Enqueue(10);
    qu.Enqueue(20);
    qu.Enqueue(30);
    qu.Dequeue();
    qu.Enqueue(40);

    while(!qu.isEmpty()){
        cout<<qu.front()<<" ";
        qu.Dequeue();
    }

    return 0;
}