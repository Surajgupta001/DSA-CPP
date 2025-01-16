/*
VALID PARANTHESIS (lEETCODE-20)

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false
*/ 
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalancedParanthesis(string str){
    /*
    * Time: O(N)
    * Space: O(N)
    */ 
    stack<char>st;
    for(int i=0;i<str.size();i++){
        char ch = str[i];
        // current char
        if(ch == '[' || ch == '{' || ch == '('){
            st.push(ch);
        }
        else{
            // closing bracket
            if(ch == ')' && !st.empty() && st.top() == '('){
                st.pop(); 
            }
            else if(ch == '}' && !st.empty() && st.top() == '{'){
                st.pop();
            }
            else if(ch == ']' && !st.empty() && st.top() == '['){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    return st.empty();
}
int main(){

    string str;
    cout<<"Enter a string: ";
    cin>>str;

    isBalancedParanthesis(str);

    if(isBalancedParanthesis(str)){
        cout<<"TURE";
    }
    else{
        cout<<"FALSE";
    }

    return 0;
}