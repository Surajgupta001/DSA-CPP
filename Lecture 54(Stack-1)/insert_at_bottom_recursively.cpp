#include <iostream>
using namespace std;
#include <stack>

void insertAtBottom(stack<int> &st, int x){ // x -> will placed at bottom
    /*
    * Time: O(N);
    * Space: O(N);
    */
    if(st.empty()){
        st.push(x);
        return;
    }
    int curr = st.top();
    st.pop();
    insertAtBottom(st,x);
    st.push(curr);
}
int main(){

    stack<int>st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    insertAtBottom(st,100);
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }
    
    return 0;
}