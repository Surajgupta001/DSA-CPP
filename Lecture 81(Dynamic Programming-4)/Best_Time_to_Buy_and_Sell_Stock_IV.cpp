/*
Best Time to Buy and Sell Stock (I,II,III,IV) - [Leetcode - 188(Hard)]
============================================================

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
====================== Recursion =======================
int helper(vector<int>& price, int i, int k, bool on){
    if(i == price.size()) return 0;
    int ans = INT_MIN;
    ans = helper(price,i+1,k,on); // avoid
    // not avoid
    if(on){
        ans  = max(ans, price[i] + helper(price,i+1,k-1,false));
    }
    else{
        if(k>0){
            ans = max(ans,helper(price,i+1,k,true) - price[i]);
        }
    }
    return ans;
}
*/ 

int helper(vector<int>& price, vector<vector<vector<int>>>& dp, int i, int k, bool on){
    if(i == price.size()) return 0;
    if(dp[i][k][on] != -1) return dp[i][k][on];
    int ans = INT_MIN;
    ans = helper(price,dp,i+1,k,on);
    if(on){
        ans  = max(ans, price[i] + helper(price,dp,i+1,k-1,false));
    }
    else{
        if(k>0){
            ans = max(ans,helper(price,dp,i+1,k,true) - price[i]);
        }
    }
    return dp[i][k][on] = ans; 
}

int maxProfit(int k, vector<int>& prices){
    vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(k+1,vector<int>(2,-1)));
    return helper(prices,dp,0,k,0);
}

int main(){

    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;
    
    vector<int> price(n);
    cout<<"Enter the elements of vector: ";
    for(int i = 0; i < n; i++) cin>>price[i];
    
    int k;
    cout<<"Enter the number of transactions: ";
    cin>>k;
    
    cout<<"Maximum profit: "<<maxProfit(k,price)<<endl;
    
    return 0;
}