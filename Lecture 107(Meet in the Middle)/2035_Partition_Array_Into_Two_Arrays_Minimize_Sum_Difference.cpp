/*
Partition Array Into Two Arrays to Minimize Sum Difference - [Leetcode - 2035(Hard)]
-----------------------------------------------------------------------------------------
You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.

Return the minimum possible absolute difference.

Example 1:

example-1
Input: nums = [3,9,7,3]
Output: 2
Explanation: One optimal partition is: [3,9] and [7,3].
The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.

Example 2:

Input: nums = [-36,36]
Output: 72
Explanation: One optimal partition is: [-36] and [36].
The absolute difference between the sums of the arrays is abs((-36) - (36)) = 72.

Example 3:

example-3
Input: nums = [2,-1,0,4,-2,-9]
Output: 0
Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
The absolute difference between the sums of the arrays is abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0. 

Constraints:

1 <= n <= 15
nums.length == 2 * n
-10^7 <= nums[i] <= 10^7
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
using namespace std;

int minimumDifference(vector<int>& nums) {
    int N = nums.size(); // 2*n

    // Total sum of the array
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    int n = N / 2;
    int n1 = n; // Left Side
    int n2 = n; // Right Side

    // SumsLeft -> size => {subsetsSums}
    unordered_map<int, vector<int>> sumsLeft;
    for(int mask = 0; mask < (1 << n1); mask++){
        int sum = 0;
        int count = 0;

        for(int i = 0; i < n1; i++){
            if(mask & (1 << i)){ // If the ith bit is set in mask, include nums[i] in the sum
                sum += nums[i];
                count++;
            }
        }
        sumsLeft[count].push_back(sum);
    }

    // SumsRight -> size => {subsetsSums}
    unordered_map<int, vector<int>> sumsRight;
    for(int mask = 0; mask < (1 << n2); mask++){
        int sum = 0;
        int count = 0;

        for(int i = 0; i < n2; i++){
            if(mask & (1 << i)){ // If the ith bit is set in mask, include nums[n1 + i] in the sum
                sum += nums[n1 + i];
                count++;
            }
        }
        sumsRight[count].push_back(sum);
    }

    // Sort the sumsRight
    for(int count = 0; count <= n2; count++){
        // SumsRight[count] this is my vector of subset sum having subset of size count
        sort(sumsRight[count].begin(), sumsRight[count].end());
    }

    int minValue = INT_MAX; // abs(2 * s1 - totalSum) => minimize this value

    for(int k = 0; k <= n1; k++){
        int m = n-k; // left hand side me k elements hai to right hand side me n-k elements honge
        // Now we have k elements from left and m elements from right
        // We need to find the best combination to minimize the absolute difference
        for(auto &leftSubSum : sumsLeft[k]){
            int need = (totalSum - 2 * leftSubSum) / 2; // This is the target we want to find in the right side
            int low = lower_bound(sumsRight[m].begin(), sumsRight[m].end(), need) - sumsRight[m].begin();

            // Check out of bounds
            if(low < static_cast<int>(sumsRight[m].size())){
                int rightSubSum = sumsRight[m][low];
                int currentDiff = abs(2 * (leftSubSum + rightSubSum) - totalSum);
                minValue = min(minValue, currentDiff);
            }

            if(low - 1 >= 0){
                int rightSubSum = sumsRight[m][low - 1];
                int currentDiff = abs(2 * (leftSubSum + rightSubSum) - totalSum);
                minValue = min(minValue, currentDiff);
            }
        }
    }
    return minValue;
}

int main() {
    vector<int> nums1 = {3, 9, 7, 3};
    cout << "Minimum Difference: " << minimumDifference(nums1) << endl; // Output: 2

    vector<int> nums2 = {-36, 36};
    cout << "Minimum Difference: " << minimumDifference(nums2) << endl; // Output: 72

    vector<int> nums3 = {2, -1, 0, 4, -2, -9};
    cout << "Minimum Difference: " << minimumDifference(nums3) << endl; // Output: 0

    return 0;
}