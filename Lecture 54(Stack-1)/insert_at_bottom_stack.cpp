#include <iostream>
using namespace std;
#include <stack>

void insertAtBottom(stack<int>&st, int k){
    /*
    * Time: O(N);
    * Space: O(N);
    */ 
    stack<int>tempstack;
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        tempstack.push(curr);
    }
    st.push(k); // this is point where k got inserted at the bottom
    while(!tempstack.empty()){
        int curr = tempstack.top();
        tempstack.pop();
        st.push(curr);
    }
}
int main(){

    stack<int>st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4); // top

    insertAtBottom(st,5);
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }

    return 0;
}