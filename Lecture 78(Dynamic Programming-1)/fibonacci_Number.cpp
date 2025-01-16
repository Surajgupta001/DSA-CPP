/*
Fibonacci Number - [Leetcode - 509(Easy)]
============================================

The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

Example 1:

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 3:

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
*/

#include <iostream>
#include <vector>
using namespace std;

/*
============= RECURSION ==========
int fibo(int n){ // Time : O(2^n)
    if(n <= 1) return n;
    return fibo(n-1) + fibo(n-2);
}
*/

int fibo(int n, vector<int>& dp){
    /*
    Time : O(n);
    Space : O(n);
    */ 
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fibo((n-1), dp) + fibo((n-2), dp);
}

int fib(int n){
    vector<int> dp(n+1, -1);
    return fibo(n, dp);
}

/*
================ TABULATION =================
int fibo(int n){
    if(n <= 1) return n;
    int dp[n+1];
    for(int i=0;i<=n;i++){
        if(i<=1) dp[i] = i;
        else dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
*/

int main(){

    int n;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<"Fibonacci number at position "<<n<<" is "<<fib(n)<<endl;

    return 0;
}