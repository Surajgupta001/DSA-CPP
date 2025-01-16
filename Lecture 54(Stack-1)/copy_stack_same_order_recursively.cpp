/*
Copy content of one stack to another in same order
*/
#include <iostream>
using namespace std;
#include <stack>

void function(stack<int> &st, stack <int> &result){
    if(st.empty()) return;
    int curr = st.top();
    st.pop();
    function(st,result);
    result.push(curr);
}
int main(){
    
    stack<int>st;
    
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    stack<int>result;

    function(st,result);

    while(!result.empty()){
        int curr = result.top();
        result.pop();
        cout<<curr<<endl;
    }

    return 0;
}