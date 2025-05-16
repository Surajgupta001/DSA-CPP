/*
300. Longest Increasing Subsequence - [Leetcode - 300(Medium)]
--------------------------------------------------------------
Given an integer array nums, return the length of the longest strictly increasing subsequence.

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Bottom-Up DP Approach
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1); // Initialize dp array with 1

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

// Top-Down DP Approach or Recurion + Memoization
int helper(vector<int>& nums, int i, int n, int prev, vector<vector<int>>& dp) {
    if( i>= n) return 0;
    
    if(dp[i][prev+1] != -1) return dp[i][prev+1];
    
    int take = 0;
    if(prev == -1 || nums[i] > nums[prev]){
        take = 1 + helper(nums, i+1, n, i, dp);
    }

    int notTake = helper(nums, i+1, n, prev, dp);
    
    return dp[i][prev+1] = max(take, notTake);
}
int lengthOfLIS(vector<int>& nums) {
    
    vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
    
    return helper(nums, 0, nums.size(), -1, dp);
}

// Binary Search Approach - O(n log(n)) - in-built lower_bound function
int lengthOfLIS(vector<int>& nums) {
    vector<int> v;
    for(int i=0; i<nums.size(); i++){
        auto itr = lower_bound(v.begin(), v.end(), nums[i]);
        if(itr == v.end()){
            v.push_back(nums[i]);
        }
        else{
            *itr = nums[i];
        }
    }
    return v.size();
}

// Binary Search Approach - O(n log(n)) - custom binary search function
int lengthOfLIS(vector<int>& nums) {
    vector<int> v;
    int low = 0;
    int high = v.size();

    for(int i=0; i<nums.size(); i++){
        int  low = 0;
        int high = v.size();

        while(low < high){
            int mid = low + (high - low) / 2;
            
            if(v[mid] < nums[i]) low = mid + 1;
            else high = mid;
        }
        if(low == v.size()) v.push_back(nums[i]);
        else v[low] = nums[i];
    }
    return v.size();
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    
    cout << "Length of Longest Increasing Subsequence: " << lengthOfLIS(nums) << endl;
    
    return 0;
}