/*
Maximum Subarray Sum With Length Divisible by K - [Leetcode - 3381(Medium)]
------------------------------------------------------------------------------
You are given an array of integers nums and an integer k.

Return the maximum sum of a subarray of nums, such that the size of the subarray is divisible by k.

Example 1:

Input: nums = [1,2], k = 1

Output: 3

Explanation:

The subarray [1, 2] with sum 3 has length equal to 2 which is divisible by 1.

Example 2:

Input: nums = [-1,-2,-3,-4,-5], k = 4

Output: -10

Explanation:

The maximum sum subarray is [-1, -2, -3, -4] which has length equal to 4 which is divisible by 4.

Example 3:

Input: nums = [-5,1,2,-3,4], k = 2

Output: 4

Explanation:

The maximum sum subarray is [1, 2, -3, 4] which has length equal to 4 which is divisible by 2.

Constraints:

1 <= k <= nums.length <= 2 * 10^5
-10^9 <= nums[i] <= 10^9
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Kadane's Algorithm variation
long long maxSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    
    vector<long long> prefixSum(n);
    prefixSum[0] = nums[0];

    for(int i = 1; i < n; i++){
        prefixSum[i] = prefixSum[i-1] + nums[i]; // prefix sum computation to 
    }

    long long result = LLONG_MIN;

    for(int start=0; start<k; start++){
        long long currSum = 0;

        int i = start;

        while(i < n && (i + k - 1) < n){
            int j = i + k - 1;

            long long subSum = prefixSum[j] - (i > 0 ? prefixSum[i - 1] : 0);

            // Kadane's steps
            currSum = max(subSum, currSum + subSum);
            result = max(result, currSum);

            i += k;
        }
    }

    return result;
}

int main() {
    vector<int> nums = {-5, 1, 2, -3, 4};
    int k = 2;

    cout << "Maximum Subarray Sum with Length Divisible by " << k << " is: " << maxSubarraySum(nums, k) << endl;

    return 0;
}