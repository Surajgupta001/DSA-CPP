/*
Minimizing Coins - [CSES]
==========================
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
For example, if the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.

Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c1,c2,....cn: the value of each coin.

Output
Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print -1.

Example
Input:
3 11
1 5 7

Output:
3
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int helper(vector<int> coins, vector<int>& dp, int x){
    if(x == 0) return 0;
    if(dp[x] != -2) return dp[x];
    int result = INT_MAX;
    for(int i=0;i<coins.size();i++){
        if(x - coins[i] < 0) continue;
        int temp = helper(coins, dp, x - coins[i]);
        if(temp != INT_MAX) result = min(result, 1 + temp);
    }
    return dp[x] = result;
}

int minimizingCoin(int n, int x, vector<int> coins){
    vector<int> dp(x+1, -2);
    int result = helper(coins,dp,x);
    return (result == INT_MAX) ? -1 : result;
}

int main(){

    int n;
    cout<<"Enter the size of money bucket: ";
    cin>>n;

    int sum;
    cout<<"Enter the desired sum: ";
    cin>>sum;

    vector<int> coins(n);
    cout<<"Enter the values of coins: ";
    for(int i=0;i<n;i++) cin>>coins[i];

    cout<<minimizingCoin(n,sum,coins)<<endl;

    return 0;
}