/*
We are given a stack data struct with push and pop operation, the task is to implement a queue using instance of stack data structure and operation on them.
*/
/*
 * Push efficient(Enqueue) -> O(1), pop(Deque) -> can be bad.
 * Pop efficient(Deque) -> O(1), Push(Enqueue) -> can be bad.
 */

/* PUSH EFFICIENT QUEUE USING STACK */

#include <iostream>
using namespace std;
#include <stack>

class Queue{
    stack<int> st;

public:
    Queue() {}
    void push(int x){ // queue.enqueue
    /*
    * Time: O(1)
    */ 
        st.push(x);
    }
    void pop(){
    /*
    * Time: O(N)
    */  
        if(st.empty()) return;
        stack<int> temp;
        while (st.size() > 1){
            temp.push(st.top());
            st.pop();
        }
        // Now stack size is 1, and we are at the bottom element
        st.pop();
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }

    bool empty(){
        return st.empty();
    }

    int front(){
    /*
    * Time: O(1)
    */ 
        if(st.empty()) return -1;
        stack<int> temp;
        while (st.size() > 1){
            temp.push(st.top());
            st.pop();
        }
        // Now stack size is 1, and we are at the bottom element
        int result = st.top();
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        return result;
    }
};

int main(){
    
    Queue qu;

    qu.push(10); // Enqueue
    qu.push(20);
    qu.push(30);
    qu.push(40);
    qu.pop(); // Dequeue

    while(!qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }


    return 0;
}
