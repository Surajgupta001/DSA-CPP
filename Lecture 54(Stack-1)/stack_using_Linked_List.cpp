#include <iostream>
using namespace std;
#include <climits>

class node{
    public:
    int data;
    node *next;

    node(int value){
        data = value;
        next = nullptr;
    }
};

class stack{
    node *head;
    int capacity;
    int currSize;

    public:
    stack(int c){
        capacity = c;
        currSize = 0;
        head = nullptr;
    }

    bool isEmpty(){
        return head == nullptr;
    }

    bool isFull(){
        return currSize = capacity;
    }

    void push(int data){
        if(currSize == capacity){
            cout<<"Overeflow";
            return;
        }
        node *new_node = new node(data);
        new_node->next = head;
        head = new_node;
        currSize++;
    }

    int pop(){
        if(head == nullptr){
            cout<<"Underflow"<<endl;
            return INT_MIN;
        }
        node *new_head = head->next;
        head->next = nullptr;
        node *tobeRemoved = head;
        int result = tobeRemoved->data;
        delete tobeRemoved;
        head = new_head;
        return result;
    }

    int getTop(){
        if(head == nullptr){
            cout<<"Underflow"<<endl;
            return INT_MIN;
        }
        return head->data;
    }

    int size(){
        return currSize;
    }

};
int main(){

    stack st(5);

    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.getTop()<<endl;

    st.push(4);
    st.push(5);
    cout<<st.getTop()<<endl;

    st.push(8);

    st.pop();
    st.pop();
    cout<<endl;
    cout<<st.getTop()<<endl;
    
    return 0;
}