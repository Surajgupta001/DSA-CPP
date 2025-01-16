/*
We are given a stack data struct with push and pop operation, the task is to implement a queue using instance of stack data structure and operation on them.
*/
/*
 * Push efficient(Enqueue) -> O(1), pop(Deque) -> can be bad.
 * Pop efficient(Deque) -> O(1), Push(Enqueue) -> can be bad.
*/

/* POP EFFICIENT QUEUE USING STACK */\
#include <iostream>
using namespace std;
#include <stack>
#include <climits>

class Queue{
    stack<int> st;

public:
    Queue(){}
    void push(int x){ // queue.enqueue
    /*
    * Time: O(N);
    */ 
        stack<int>temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
    void pop(){
    /*
    * Time: O(1);
    */ 
        if(st.empty()) return;
        st.pop();
    }

    bool empty(){
        return st.empty();
    }

    int front(){
    /*
    * Time: O(1);
    */ 
        if(st.empty()){
            return INT_MIN;
        }
        else{
            return st.top();
        }
    }
};

int main(){
    
    Queue qu;

    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);
    qu.pop();

    while(!qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }

    return 0;
}