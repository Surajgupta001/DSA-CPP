/*
Min Cost Climbing Stairs - [Leetcode - 746(Easy)]
===================================================
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
*/ 

#include <iostream>
#include <vector>
using namespace std;
/*
===========  ONLY RECURSION ============

int helper(vector<int>& cost, int i){
    if(i <= 1) return cost[i];
    return cost[i] + min(helper(cost,i-1),helper(cost,i-2));
}

int minCostClimbingStairs(vector<int>& cost){
    int n = cost.size();
    return min(helper(cost,n-1),helper(cost,n-2));
}
*/ 

int helper(vector<int>& cost, int i, vector<int>& dp){
    if(i <= 1) return cost[i];
    if(dp[i] != -1) return dp[i];
    return dp[i] = cost[i] + min(helper(cost,i-1,dp),helper(cost,i-2,dp)); 
}

int minCostClimStairs(vector<int>& cost){
    int n = cost.size();
    vector<int> dp(n,-1);
    return min(helper(cost,n-1,dp),helper(cost,n-2,dp));
}

/*
===========  ONLY ITERATION / TABULATION ============
int minCostCimbingStarirs(vector<int>& cost){
    int n = cost.size();
    for(int i=2;i<n;i++){
        cost[i] += min(cost[i-1],cost[i-2])
    }
    return min(cost[n-1],cost[n-2]);
}
*/ 

int main(){

    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};

    cout<<"Minimum cost to reach the top of the floor is: "<<minCostClimStairs(cost);
    
    return 0;
}