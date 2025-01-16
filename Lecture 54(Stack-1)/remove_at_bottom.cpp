#include <iostream>
#include <stack>
using namespace std;

void removeAtBottom(stack<int>&st){
    
    stack<int>tempstack;

    while(st.size() != 1){
        int curr = st.top();
        st.pop();
        tempstack.push(curr);
    }
    st.pop();
    while(!tempstack.empty()){
        int curr = tempstack.top();
        tempstack.pop();
        st.push(curr);
    }
}
int main(){

    stack <int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    removeAtBottom(st);
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }
    
    return 0;
}