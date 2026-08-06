/*
Split Array With Same Average - [Leetcode - 805(Hard)]
-----------------------------------------------------------
You are given an integer array nums.

You should move each element of nums into one of the two arrays A and B such that A and B are non-empty, and average(A) == average(B).

Return true if it is possible to achieve that and false otherwise.

Note that for an array arr, average(arr) is the sum of all the elements of arr over the length of arr.

Example 1:

Input: nums = [1,2,3,4,5,6,7,8]
Output: true
Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have an average of 4.5.

Example 2:

Input: nums = [3,1]
Output: false 

Constraints:

1 <= nums.length <= 30
0 <= nums[i] <= 10^4
*/

// MEET IN THE MIDDLE APPROACH

#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
using namespace std;

bool splitArraySameAverage(vector<int>& nums) {
    int N = nums.size();
    int S = accumulate(nums.begin(), nums.end(), 0);

    int n1 = N / 2; // Left Array
    int n2 = N - n1; // Right Array

    unordered_map<int, vector<int>> sumsLeft;
    // Size -> { subsetSum1, subsetSum2, ... }

    // Generate all possible subset sums for the left half of the array
    for(int mask = 0; mask < (1 << n1); mask++){
        int sum = 0;
        int count = 0;

        for(int i=0; i<n1; ++i) {
            if (mask & (1 << i)) {
                sum += nums[i];
                count++;
            }
        }
        sumsLeft[count].push_back(sum);
    }

    // Generate all possible subset sums for the right half of the array
    unordered_map<int, vector<int>> sumsRight;
    for(int mask = 0; mask < (1 << n2); mask++){
        int sum = 0;
        int count = 0;

        for(int i=0; i<n2; ++i) {
            if (mask & (1 << i)) {
                sum += nums[n1 + i];
                count++;
            }
        }
        sumsRight[count].push_back(sum);
    }

    // Key -> vector<int> (subset sums for that size)
    for(int count=0; count<=n2; count++){
        // Sort it
        sort(sumsRight[count].begin(), sumsRight[count].end());
    }

    for(int k=1; k<=n1; k++){
        // Left Subset Size = k
        for(auto &leftSubSum : sumsLeft[k]){
            for(int m=0; m<=n2; m++){
                int size = k + m;
                if(size == 0 || size == N) continue; // A and B both be non-empty
                
                // Right Subset Size = m
                if((S * size) % N != 0) continue; // rightSubSum
                int rightSubSum = (S * size) / N - leftSubSum;

                if(binary_search(sumsRight[m].begin(), sumsRight[m].end(), rightSubSum)){
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << (splitArraySameAverage(nums) ? "true" : "false") << endl; // Output: true

    vector<int> nums2 = {3, 1};
    cout << (splitArraySameAverage(nums2) ? "true" : "false") << endl; // Output: false

    return 0;
}