/*
Minimum Number of Taps to Open to Water a Garden - [Leetcode - 1326(Hard)]
===========================================================================

There is a one-dimensional garden on the x-axis. The garden starts at the point 0 and ends at the point n. (i.e., the length of the garden is n).

There are n + 1 taps located at points [0, 1, ..., n] in the garden.

Given an integer n and an integer array ranges of length n + 1 where ranges[i] (0-indexed) means the i-th tap can water the area [i - ranges[i], i + ranges[i]] if it was open.

Return the minimum number of taps that should be open to water the whole garden, If the garden cannot be watered return -1.

Example 1:


Input: n = 5, ranges = [3,4,1,1,0,0]
Output: 1
Explanation: The tap at point 0 can cover the interval [-3,3]
The tap at point 1 can cover the interval [-3,5]
The tap at point 2 can cover the interval [1,3]
The tap at point 3 can cover the interval [2,4]
The tap at point 4 can cover the interval [4,4]
The tap at point 5 can cover the interval [5,5]
Opening Only the second tap will water the whole garden [0,5]

Example 2:

Input: n = 3, ranges = [0,0,0,0]
Output: -1
Explanation: Even if you activate all the four taps you cannot water the whole garden.
*/ 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
=============== Leetcode Acceptance =========
int minTaps(int n, vector<int>& ranges){
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i <= n; i++){
        int start = max(0, i-ranges[i]);
        int end = min(n, i+ranges[i]);
        int ans = INT_MIN;
        for(int j = start; j <= end; j++){
            ans = min(ans, dp[j]);
        }
        if(ans == INT_MIN){
            dp[end] = min(dp[end], ans+1);
        }
    }
    return dp[n] == INT_MAX ? -1 : dp[n];
}
*/ 

int minTaps(int n, vector<int>& ranges) {
    vector<int> dp(n + 1, INT_MAX); // Initialize dp array with INT_MAX
    dp[0] = 0; // No taps required to water up to point 0

    for (int i = 0; i <= n; i++) {
        int start = max(0, i - ranges[i]);
        int end = min(n, i + ranges[i]);

        if (dp[start] == INT_MAX) continue; // Skip if the starting point is unreachable

        for (int j = start; j <= end; j++) {
            dp[j] = min(dp[j], dp[start] + 1); // Update minimum taps required for each position
        }
    }

    return dp[n] == INT_MAX ? -1 : dp[n]; // If dp[n] is INT_MAX, it means we cannot water the entire garden
}

int main(){
    int n = 5;
    vector<int> ranges = {3,4,1,1,0,0};
    cout<<minTaps(n, ranges) << endl; // output will be 1
    return 0;
}