/*
Given a number n, you can perform any of the following operations on it some number of times
1. Reduce n to n-1
2. if n is divisible by 2 to make it n/2
3. if n is divisible by 3 to make it n/3

Find out in how many minimum steps you can reduce n to 1
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define inf INT_MAX
using namespace std;

/*
=================== Recursion =================
int minStepsToReduceTo1(int n){
    if(n == 1) return 0;
    if(n == 2 or n == 3) return 1;
    return 1 + min({minStepsToReduceTo1(n-1), (n%2 == 0) ? minStepsToReduceTo1(n/2) : inf, (n%3 == 0) ? minStepsToReduceTo1(n/3) : inf});
}
*/ 

int helper(vector<int>& dp, int n){
    if(n == 1) return 0;
    if(n == 2 or n == 3) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = 1 + min({helper(dp, n-1), (n%2 == 0) ? helper(dp,n/2) : inf, (n%3 == 0) ? helper(dp,n/3) : inf});
}

int minStepsToReduceTo1(int n){
    vector<int> dp(n+1, -1);
    return helper(dp, n);
}

/*
================= Tabulation ==================
int minStepsToReduceTo1(int n){
    vector<int> dp(n+1, 0);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4; i <= n; i++){
        dp[i] = 1 + min({dp[i-1], (i%2 == 0) ? dp[i/2] : dp[i-1], (i%3 == 0) ? dp[i/3] : dp[i-1]});
    }
    return dp[n];
}
*/
 
int main(){

    int n;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<"Minimum steps to reduce "<<n<<" to 1: "<<minStepsToReduceTo1(n)<<endl;
    
    return 0;
}