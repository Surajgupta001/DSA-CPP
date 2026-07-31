/*
Closest Subsequence Sum - [Leetcode - 1755(Hard)]
------------------------------------------------------

You are given an integer array nums and an integer goal.

You want to choose a subsequence of nums such that the sum of its elements is the closest possible to goal. That is, if the sum of the subsequence's elements is sum, then you want to minimize the absolute difference abs(sum - goal).

Return the minimum possible value of abs(sum - goal).

Note that a subsequence of an array is an array formed by removing some elements (possibly all or none) of the original array.

Example 1:

Input: nums = [5,-7,3,5], goal = 6
Output: 0
Explanation: Choose the whole array as a subsequence, with a sum of 6.
This is equal to the goal, so the absolute difference is 0.

Example 2:

Input: nums = [7,-9,15,-2], goal = -5
Output: 1
Explanation: Choose the subsequence [7,-9,-2], with a sum of -4.
The absolute difference is abs(-4 - (-5)) = abs(1) = 1, which is the minimum.

Example 3:

Input: nums = [1,2,3], goal = -7
Output: 7 

Constraints:

1 <= nums.length <= 40
-10^7 <= nums[i] <= 10^7
-10^9 <= goal <= 10^9
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int minAbsDifference(vector<int>& nums, int goal) {
    int n = nums.size();

    int n1 = n / 2;
    int n2 = n - n1;

    vector<int> sumsA(1 << n1);
    for(int mask = 0; mask < (1 << n1); mask++) {
        int sum = 0;
        for(int i = 0; i < n1; i++) {
            if(mask & (1 << i)) {
                sum += nums[i];
            }
        }
        sumsA[mask] = sum;
    }

    vector<int> sumsB(1 << n2);
    for(int mask = 0; mask < (1 << n2); mask++) {
        int sum = 0;
        for(int i = 0; i < n2; i++) {
            if(mask & (1 << i)) {
                sum += nums[n1 + i];
            }
        }
        sumsB[mask] = sum;
    }

    sort(sumsB.begin(), sumsB.end());

    int minDiffValue = INT_MAX;
    for(auto &sum1 : sumsA){
        int needed = goal - sum1;
        int low = lower_bound(sumsB.begin(), sumsB.end(), needed) - sumsB.begin(); // return the index of the first element that is not less than needed

        if(low < sumsB.size()){
            int sum2 = sumsB[low];
            int totalSum = sum1 + sum2;
            minDiffValue = min(minDiffValue, abs(totalSum - goal));
        }

        if(low > 0){
            int sum2 = sumsB[low - 1];
            int totalSum = sum1 + sum2;
            minDiffValue = min(minDiffValue, abs(totalSum - goal));
        }
    }

    return minDiffValue;
}

int main() {
    vector<int> nums = {5, -7, 3, 5};
    int goal = 6;
    cout << minAbsDifference(nums, goal) << endl; // Output: 0

    nums = {7, -9, 15, -2};
    goal = -5;
    cout << minAbsDifference(nums, goal) << endl; // Output: 1

    nums = {1, 2, 3};
    goal = -7;
    cout << minAbsDifference(nums, goal) << endl; // Output: 7

    return 0;
}