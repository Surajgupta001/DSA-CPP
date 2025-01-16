/*
House Robber - [Leetcode - 198(Medium)]
=====================================================
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
================== Recursive Approach ==================
int helper(vector<int>&v , int index){
    // if we are at the last house, we can only rob that house or single house
    if(index == v.size()-1) return v[index];

    // if we are at the second last house, we can rob the house with maximum money among the two houses
    if(index == v.size()-2) return max(v[index], v[index+1]);

    return max(v[index] + helper(v, index+2), helper(v, index+1));
}

int rob(vector<int>& v){
    return helper(v, 0);
}
*/ 

// ================== Dynamic Programming Approach ==================
int helper(vector<int>&v , int index, vector<int>& dp){
    
    // if we are at the last house, we can only rob that house or single house
    if(index == v.size()-1) return v[index];

    // if we are at the second last house we can rob the house with maximum money among the two houses
    if(index == v.size()-2) return max(v[index], v[index+1]);
    
    // if the value is already calculated, return the value
    if(dp[index] != -1) return dp[index]; 

    // store the value in dp array  and return the value
    dp[index] = max(v[index] + helper(v, index+2, dp), helper(v, index+1, dp));
}

int rob(vector<int>& v){
    vector<int> dp(v.size(), -1);
    return helper(v, 0, dp);
}

/*
================== Tabulation ==================
int helper(vector<int>& v, vector<int>& dp){
    if(v.size() == 1) return v[0];
    dp[v.size()-1] = v[v.size()-1];
    dp[v.size()-2] = max(v[v.size()-1], v[v.size()-2]);
    for(int i=v.size()-3;i>=0;i--){ // ordering
        dp[i] = max(v[i] + dp[i+2],0 + dp[i+1]);
    }
    return dp[0];
}

int rob(vector<int>& v){
    vector<int> dp(v.size(), -1);
    return helper(v, dp);
}
*/ 

int main(){
    int n;
    cout<<"Enter the number of houses: ";
    cin>>n;
    
    vector<int> v(n);
    cout<<"Enter the money in each house: ";
    
    for(int i=0; i<n; i++) cin>>v[i];
    cout<<"Maximum amount of money you can rob tonight without alerting the police: "<<rob(v)<<endl;
    
    return 0;
}