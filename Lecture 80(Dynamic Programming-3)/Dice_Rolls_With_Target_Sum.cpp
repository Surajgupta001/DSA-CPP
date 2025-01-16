/*
Number of Dice Rolls With Target Sum - [Leetcode - 1155(Medium)]
You have n dice, and each dice has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

Example 1:

Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.

Example 2:

Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
Example 3:

Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 10^9 + 7.
*/

#include <iostream>
#include <vector>
using namespace std;

/*
=============== Recursion ===============
int helper(int n, int k, int t){
    if(n == 0 and t == 0) return 1;
    if(n == 0) return 0;

    int sum = 0;
    for(int v=1;v<=k;v++){
        if(t-v < 0) continue;
        sum = (sum + helper(n-1, k, t-v));
    }
    return sum;
}

int numRollsTarget(int n, int k, int target){
    return helper(n,k,target) % int(1e9 + 7);
}
*/ 

int helper(vector<vector<int>>& dp, int n, int k, int t){
    if(n == 0 and t == 0) return 1;
    if(n == 0) return 0;
    if(dp[n][t] != -1) return dp[n][t];
    int sum = 0;
    for(int v=1;v<=k;v++){
        if(t-v < 0) continue;
        sum = (sum + helper(dp, n-1, k, t-v));
    }
    dp[n][t] = sum % int(1e9 + 7);
}

int numRollsTarget(int n, int k, int target){
    vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
    return helper(dp, n, k, target);
}

int main(){

    int n;
    cout<<"Enter the number of dies: ";
    cin>>n;

    int k;
    cout<<"Enter the number of faces on each die: ";
    cin>>k;

    int target;
    cout<<"Enter the target sum: ";
    cin>>target;

    cout<<numRollsTarget(n,k,target)<<endl;
    
    return 0;
}