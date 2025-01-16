/*
Dice Combinations - [CSES]
=====================================
Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
For example, if n=3, there are 4 ways:

* 1+1+1
* 1+2
* 2+1
* 3

Input
The only input line has an integer n.

Output
Print the number of ways modulo 10^9+7.

Example
Input:
3

Output:
4
*/ 

#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

int helper(vector<int>& dp, int n){
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    ll sum = 0;
    for(int i = 1; i <= 6; i++){
        if(n-i < 0) break;
        sum = (sum + helper(dp, n-i)) % 1000000007;
    }
    dp[n] = sum;
}

int diceCombinations(int n){
    vector<int> dp(n+1, -1);
    return helper(dp, n);
}

/*
=============== Tabulations ==================
int diceCombinations(vector<int>&dp, int n){
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        ll sum = 0;
        for(int j=1;j<=6;j++){
            if(i-j < 0) break;
            sum = (sum + dp[i-j]) % 1000000007;
        }
        dp[i] = sum;
    }
    return dp[n];
}
*/ 
int main(){

    int n;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<"Number of ways to construct sum: "<<diceCombinations(n)<<endl;
    
    return 0;
}