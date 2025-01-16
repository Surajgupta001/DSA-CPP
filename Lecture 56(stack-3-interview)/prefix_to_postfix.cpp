#include <iostream>
using namespace std;
#include <string>
#include <stack>
#include <algorithm>

string PrefixToPostfix(string &str){
    stack<string>st;
    reverse(str.begin(),str.end());
    for(int i=0;i<str.size();i++){
        if(isdigit(str[i])){
           st.push(to_string(str[i] - '0'));
        }
        else{
            string v1 = st.top();
            st.pop();
            string v2 = st.top();
            st.pop();
            string newexp = v1 + v2 + str[i];
            st.push(newexp);
        }
    }
    return st.top();
}
int main(){

    string str;
    cout<<"Enter a prefix expression: ";
    getline(cin,str);

    cout<<"Postfix Conversion: "<<str<<endl;
    cout<<"Postfix COnversion: "<<PrefixToPostfix(str)<<endl;

    return 0;
}