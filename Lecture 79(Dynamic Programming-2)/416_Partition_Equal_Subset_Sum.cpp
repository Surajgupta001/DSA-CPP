/*
Partition Equal Subset Sum - [Leetcode - 416(Medium)]
=====================================================
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/ 

#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& nums) {
    int total_sum = 0;
    
    for(int i=0; i<nums.size(); i++) total_sum += nums[i]; // Calculate total sum of the array
    
    if(total_sum % 2 != 0) return false; // If total sum is odd, we cannot partition it into two equal subsets

    int target_sum = total_sum / 2; // Target sum for each subset
    
    vector<bool> dp(target_sum + 1, false); // DP array to store if a sum can be formed
    dp[0] = true; // 0 sum can always be formed with an empty subset
    
    for(int i=0; i<nums.size(); i++){
        for(int j=target_sum; j>=nums[i]; j--){ // Traversing backwards to avoid using the same element multiple times
            if(dp[j - nums[i]]){ // If we can form (j - nums[i]), then we can also form j by adding nums[i]
                dp[j] = true;
            }
        }
    }
    return dp[target_sum];
}

int main(){
        
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {1, 5, 11, 5};
    cout << boolalpha << canPartition(nums) << endl; // Output: true
        
    return 0;
}