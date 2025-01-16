#include <iostream>
using namespace std;
#include <stack>

void insertAtAnyIndex(stack<int> &st, int x, int idx){

    stack<int>tempstack;

    int n = st.size(); // size of stack.
    int count = 0;
    
    while(count < (n - idx)){
        count++;
        int curr = st.top();
        st.pop();
        tempstack.push(curr);
    }
    st.push(x);
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
    st.push(4);
    st.push(5);

    insertAtAnyIndex(st,6,1);
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }

    return 0;
}