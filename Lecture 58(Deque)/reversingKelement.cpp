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

void function(queue<int>&qu, int k){
    if(k == 0){
        return;
    }
    else{
        int x = qu.front();
        qu.pop();
        function(qu, k-1);
        qu.push(x);
    }
}

// Function to reverse k element of a queue
queue<int>reverseKelement(queue<int>qu, int k){
    function(qu,k);
    int temp = qu.size()-k;
    while(temp -- > 0){
        int x = qu.front();
        qu.pop();
        qu.push(x);
    }
    return qu;
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
    
    qu = reverseKelement(qu, k);
    cout<<"Queue after reversing first "<<k<<"element: ";

    while(!qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }
    return 0;
}