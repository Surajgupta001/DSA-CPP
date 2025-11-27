/*
Maximum Absolute Sum of Any Subarray - [Leetcode - 1749(Medium)]
--------------------------------------------------------------------
You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.

Example 1:

Input: nums = [1,-3,2,3,-4]
Output: 5
Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.

Example 2:

Input: nums = [2,-5,1,-4,3,-2]
Output: 8
Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.

Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Approach-1 (2 Pass - Kadane's Algorithm for maxSubArrySum and minsubArraySum)
// T.C : O(2*n) ~= O(n)
// S.C : O(1)
int maxAbsoluteSum(vector<int>& nums) {
    int n = nums.size();

    int currSubArraySum = nums[0];
    int maxSubArraySum = nums[0];
    
    // 1st Pass : Kadane's Algorithm to finding max subarray Sum
    for(int i=1; i<n; i++){
        currSubArraySum = max(nums[i], currSubArraySum + nums[i]);
        maxSubArraySum = max(maxSubArraySum, currSubArraySum);
    }

    // 2nd Pass : Kadane's Algorithm to finding min subarray Sum
    int minSubArraySum = nums[0];
    currSubArraySum = nums[0];

    for(int i=1; i<n; i++){
        currSubArraySum = min(nums[i], currSubArraySum + nums[i]);
        minSubArraySum = min(minSubArraySum, currSubArraySum);
    }

    return max(abs(maxSubArraySum), abs(minSubArraySum));
}

// Approach-2 (1 Pass - Kadane's Algorithm for maxsubarrysum and minsybarraysum inside one for loop)
// T.C : O(n)
// S.C : O(1)
int maxAbsoluteSum(vector<int> &nums) {
    int n = nums.size();
    
    int maxSum = nums[0];
    int minSum = nums[0];
    
    int currSumMax = nums[0];
    int currSumMin = nums[0];
    
    for (int i = 1; i < n; i++){
        currSumMax = max(nums[i], currSumMax + nums[i]);
        maxSum = max(maxSum, currSumMax);
        
        currSumMin = min(nums[i], currSumMin + nums[i]);
        minSum = min(minSum, currSumMin);
    }
    
    return max(maxSum, abs(minSum));
}

int main() {
    vector<int> nums = {1, -3, 2, 3, -4};
    cout << "Maximum Absolute Sum of Any Subarray: " << maxAbsoluteSum(nums) << endl;
    return 0;
}