/*
Unique Binary Search Trees (Catalan Number) - 96[Leetcode - (Medum)]
===================================================
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

Example 1:

Input: n = 3
Output: 5

Example 2:

Input: n = 1
Output: 1
*/

#include <iostream>
#include <vector>
using namespace std;

/*
================ Recursion ====================
int helper(int n){
    if(n == 0 or n == 1) return 1;
    if(n == 2) return 2;
    int sum = 0;
    for(int k = 1; k <= n; k++){
        // k ->  potential root
        // n-k ->  potential left subtree
        // k-1 ->  potential right subtree
        sum += helper(k-1) * helper(n-k);
    }
    return sum;
}

int numTree(int n){
    return helper(n);
}
*/ 

int helper(vector<int>& dp, int n){
    if(n == 0 or n == 1) return 1;
    if(n == 2) return 2;
    if(dp[n] != -1) return dp[n];
    int sum = 0;
    for(int k=1; k<=n; k++) sum += helper(dp,k-1)*helper(dp,n-k);
    return dp[n] = sum;
}
int numTree(int n){
    vector<int> dp(n+1,-1);
    return helper(dp,n);
}

/*
================ Tabulation ====================
int numTree(int n){
    vector<int> dp(n+1,0);
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++){
        // helper(i)
        for(int k = 1; k <= i; k++){
            // k -> potential root
            // i-k -> potential left subtree
            // k-1 -> potential right subtree
            dp[i] += dp[k-1]*dp[i-k];
        }
    }
    return dp[n];
}
*/ 

int main(){
    
    int n;
    cout<<"Enter the numbers of nodes: ";
    cin>>n;

    cout<<"number of structurally unique BST's is: "<<numTree(n)<<endl;
    
    return 0;
}