/*
Copy content of one stock to another in same order
*/ 
#include <iostream>
#include <stack>
using namespace std;

stack<int>copystack(stack<int> &input){
    stack <int> tempstack;
    while(!input.empty()){
        // do the process till the time input stack doesn't become empty
        int curr = input.top();
        input.pop();
        tempstack.push(curr);
    }
    stack<int>result;
    while(!tempstack.empty()){
        int curr = tempstack.top();
        tempstack.pop();
        result.push(curr);
    }
    return result;
}
int main(){

    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    stack<int>res = copystack(st);
    while(!res.empty()){
        int curr = res.top();
        res.pop();
        cout<<curr<<endl;
    }
    return 0;
}
