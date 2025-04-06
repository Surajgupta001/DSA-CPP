/*
Largest Divisible Subset - [Leetcode - 368(Medium)]
===================================================
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.

Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> ans; // Global variable to store the answer

// Finding all subsets of a given set
void helper(vector<int>& v, int start, vector<int> curr){
    ans.push_back(curr);
    for(int i=start; i<v.size(); i++){
        curr.push_back(v[i]); // Include the current element in the subset
        helper(v, i+1, curr); // Recur for the next elements
        curr.pop_back(); // Backtrack to explore other combinations
    }
}

vector<vector<int>> subsets(vector<int>& v){
    ans.clear(); // Clear the global variable before starting
    helper(v, 0, {}); // Start the recursion with an empty subset
    return ans; // Return the list of all subsets
}

vector<int> largestDivisibleSubset(vector<int>& nums) {
    if(nums.empty()) return {}; // Handle empty input
    sort(nums.begin(), nums.end()); // Sort the input array

    vector<int> dp(nums.size(), 1); // DP array to store the size of the largest divisible subset ending at each index
    vector<int> prev(nums.size(), -1); // Array to store the previous index in the subset

    int maxSize = 1, maxIndex = 0; // Variables to track the maximum size and index of the largest subset

    for(int i=1; i<nums.size(); i++){
        for(int j=0; j<i; j++){
            if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1; // Update the size of the largest divisible subset
                prev[i] = j; // Update the previous index
            }
        }
        if(dp[i] > maxSize){
            maxSize = dp[i]; // Update the maximum size
            maxIndex = i; // Update the index of the largest subset
        }
    }
    vector<int> result; // Vector to store the result
    while(maxIndex != -1){
        result.push_back(nums[maxIndex]); // Add the current element to the result
        maxIndex = prev[maxIndex]; // Move to the previous index
    }
    reverse (result.begin(), result.end()); // Reverse the result to get the correct order
    return result;
}

int main(){
        
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {1, 2, 4, 8}; 
    vector<int> result = largestDivisibleSubset(nums); 
    for(int i=0; i<result.size(); i++) cout << result[i] << " ";
    cout << endl;
        
    return 0;
}