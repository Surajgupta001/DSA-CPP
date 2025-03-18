/*
Longest Nice Subarray - [Leetcode - 2401(Medium)]
=================================================
You are given an array nums consisting of positive integers.

We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.

Return the length of the longest nice subarray.

A subarray is a contiguous part of an array.

Note that subarrays of length 1 are always considered nice.

Example 1:

Input: nums = [1,3,8,48,10]
Output: 3
Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
- 3 AND 8 = 0.
- 3 AND 48 = 0.
- 8 AND 48 = 0.
It can be proven that no longer nice subarray can be obtained, so we return 3.

Example 2:

Input: nums = [3,1,5,11,13]
Output: 1
Explanation: The length of the longest nice subarray is 1. Any subarray of length 1 can be chosen.
 
Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
*/

#include <iostream>
#include <vector>
using namespace std;

int longestNiceSubarray(vector<int>& nums) {
    // Base case: If the array has one or zero elements, return its size
    if (nums.size() <= 1) {
        return nums.size();
    }
    
    int n = nums.size();
    int max_length = 1; 
    int left = 0; // Left pointer of the sliding window
    int bitmask = 0; // Bitmask to store the bitwise OR of elements in the current window
    
    for (int right = 0; right < n; right++) {
        // If the current element has a non-zero bitwise AND with the bitmask, move the left pointer to the right
        // This ensures that the current window is a nice subarray
        while ((bitmask & nums[right]) != 0) {
            // Remove the leftmost element from the bitmask
            bitmask &= ~nums[left];
            left++;
        }
        // Add the current element to the bitmask
        bitmask |= nums[right];
        // Update the maximum length of the nice subarray
        max_length = max(max_length, right - left + 1);
    }
    return max_length;
}

int main(){
    vector<int> nums = {1,3,8,48,10};
    cout << longestNiceSubarray(nums) << endl;
    return 0;
}