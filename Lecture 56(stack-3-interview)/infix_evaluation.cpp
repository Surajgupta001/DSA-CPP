#include <iostream>
using namespace std;
#include <stack>
#include <math.h>
int calculate(int num1, int num2, int op){
    if (op == '^'){
        return pow(num1, num2);
    }
    if (op == '*'){
        return num1 * num2;
    }
    if (op == '/'){
        return num1 / num2;
    }
    if (op == '+'){
        return num1 + num2;
    }
    else{
        return num1 - num2;
    }
}
int precendence(char ch){
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}
int evaluation(string str){
    stack<int> nums;
    stack<char> ops;
    for (int i = 0; i < str.size(); i++){
        if (isdigit(str[i])){
            nums.push(str[i] - '0');
        }
        else if (str[i] == '('){
            ops.push('(');
        }
        else if (str[i] == ')'){
            while (!ops.empty() && ops.top() != '('){
                char op = ops.top();
                ops.pop();
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                nums.push(calculate(num1, num2, op));
            }
            if (!ops.empty()){
                ops.pop();
            }
        }
        else{
            while (!ops.empty() && precendence(ops.top()) >= precendence(str[i])){
                char op = ops.top();
                ops.pop();
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                nums.push(calculate(num1, num2, op));
            }
            ops.push(str[i]);
        }
    }
    while (!ops.empty()){
        char op = ops.top();
        ops.pop();
        int num2 = nums.top();
        nums.pop();
        int num1 = nums.top();
        nums.pop();
        nums.push(calculate(num1, num2, op));
    }
    return nums.top();
}
int main(){
    
    string str;
    cout<<"Enter a string: ";
    cin>>str;

    cout << evaluation(str);

    return 0;
}