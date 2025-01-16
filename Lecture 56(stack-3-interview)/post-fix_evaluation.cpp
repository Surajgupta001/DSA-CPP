#include <iostream>
using namespace std;
#include <stack>
#include <math.h>

int calculate(int num1, int num2, int op){
    if(op == '^'){
        return pow(num1,num2);
    }
    if(op == '*'){
        return num1*num2;
    }
    if(op == '/'){
        return num1/num2;
    }
    if(op == '+'){
        return num1+num2;
    }
    else{
        return num1-num2;
    }
}

int evaluation(string &str){
    stack<int> st;
    for(int i=0;i<str.size();i++){
        char ch = str[i];
        if(isdigit(ch)){
            st.push(ch-'0');
        }
        else{
            int num2 = st.top();
            st.pop();
            int num1 = st.top();
            st.pop();
            st.push(calculate(num1, num2, ch));
        }
    }
    return st.top();
}
int main(){

    string str;
    cout<<"Enter a string: ";
    cin>>str;

    cout<<evaluation(str);

    return 0;
}