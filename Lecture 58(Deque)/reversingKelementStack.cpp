/*
Reversing the first K elements of a Queue

Given an integer k and a queue of integers, The task is to reverse the order of the first k elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue. 

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.

*/  
#include <iostream>
using namespace std;
#include <queue>
#include <stack>

void reverseKelement(queue<int>&qu, int k){
    if(k <= 0 or k > qu.size()){
        return; // invalid value of k;
    }

    stack<int>st;

    // step 1: Dequeue first K element and push then onto stack
    for(int i=0; i<k; i++){
        st.push(qu.front());
        qu.pop();
    }

    // step 2: Pop form stack and enqueue back to the queue
    while(!st.empty()){
        qu.push(st.top());
        st.pop();
    }

    // step 3: move the remaining element to the back of the queue
    for(int i=0;i<qu.size()-k;i++){
        qu.push(qu.front());
        qu.pop();
    }
}
int main(){

    queue<int>qu;

    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.push(5);
    qu.push(6);
    qu.push(7);
    qu.push(8);
    qu.push(9);
    qu.push(10);

    int k;
    cout<<"Enter the value of reversing element: ";
    cin>>k;

    cout<<"Original Queue: ";
    queue<int> copy = qu;
    while(!copy.empty()){
        cout<<copy.front()<<" ";
        copy.pop();
    }
    cout<<endl;

    reverseKelement(qu,k);

    cout<<"Queue after reversing first "<<k<<"element: ";
    while(!qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }
    cout<<endl;
    
    return 0;
}