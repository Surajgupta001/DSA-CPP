/*
N-th Tribonacci Number - [Leetcode - 1173(Easy)]
================================================
The Tribonacci sequence Tn is defined as follows: 
The tribonacci series is a generalization of the Fibonacci sequence where each term is the sum of the three preceding terms.

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4

Example 2:

Input: n = 25
Output: 1389537
*/ 

#include <iostream>
#include <vector>
using namespace std;

/*
============ RECURSION =============
int tribonacci(int n){
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
    return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
}
*/ 

int helper(int n, vector<int>& dp){
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = helper(n-1,dp) + helper(n-2,dp) + helper(n-3,dp);
}

int tribonacci(int n){
    vector<int> dp(n+1,-1);
    return helper(n,dp);
}

/*
============ TABULATION ============
int tribonacci(int n){
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
    int dp[n+1];
    for(int i=0;i<=n;i++){
        if(i == 0) dp[i] = 0;
        else if(i == 1 or i == 2) dp[i] = 1;
        else dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}
*/ 

int main(){
    
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<"Tribonacci number at position "<<n<<" is: "<<tribonacci(n)<<endl;
    
    return 0;
}