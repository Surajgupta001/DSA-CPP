#include <iostream>
using namespace std;
#include <queue>
#include <stack>

int main(){

    queue<int> qu;

    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);
    qu.push(50);

    stack<int>st;

    while(!qu.empty()){
        st.push(qu.front());
        qu.pop();
    }

    while(!st.empty()){
        qu.push(st.top());
        st.pop();
    }

    cout<<"Queue elements are in reversed order: ";
    while(!qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }

    return 0;
}