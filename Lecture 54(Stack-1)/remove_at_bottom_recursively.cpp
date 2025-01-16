#include <iostream>
using namespace std;
#include <stack>

void removeAtBottom(stack<int> &st){
    if(st.size() == 1 ){
        st.pop();
        return;
    }
    int curr = st.top();
    st.pop();
    removeAtBottom(st);
    st.push(curr);
}
int main(){

    stack <int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    removeAtBottom(st);
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;

    }


    return 0;
}