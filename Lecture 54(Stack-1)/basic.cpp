#include <iostream>
using namespace std;
#include <stack>

int main(){

    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.top()<<endl;

    st.push(4);
    st.push(6);
    cout<<st.top()<<endl;

    st.pop();
    st.pop();
    cout<<st.top();

    return 0;
}