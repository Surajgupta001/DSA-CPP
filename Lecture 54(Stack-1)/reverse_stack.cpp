#include <iostream>
using namespace std;
#include <stack>

void reverseStack(stack<int> &st){
    stack<int> temp_st1, temp_st2;

    while(!st.empty()){
        int curr = st.top();
        st.pop();
        temp_st1.push(curr);
    }
    while(!temp_st1.empty()){
        int curr = temp_st1.top();
        temp_st1.pop();
        temp_st2.push(curr);
    }
    while(!temp_st2.empty()){
        int curr = temp_st2.top();
        temp_st2.pop();
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

    reverseStack(st);

    while(!st.empty()){
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }
    return 0;
}