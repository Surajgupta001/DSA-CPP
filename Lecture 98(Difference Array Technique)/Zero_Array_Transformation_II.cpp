/*
Zero Array Transformation II - [Leetcode - 3356(Medium)]
========================================================
You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri, vali].

Each queries[i] represents the following action on nums:

-> Decrement the value at each index in the range [li, ri] in nums by at most vali.
-> The amount by which each value is decremented can be chosen independently for each index.

A Zero Array is an array with all its elements equal to 0.

Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence, nums becomes a Zero Array. If no such k exists, return -1.



Example 1:

Input: nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]

Output: 2

Explanation:

-> For i = 0 (l = 0, r = 2, val = 1):
    -> Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
    -> The array will become [1, 0, 1].
-> For i = 1 (l = 0, r = 2, val = 1):
    -> Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
    -> The array will become [0, 0, 0], which is a Zero Array. Therefore, the minimum value of k is 2.

Example 2:

Input: nums = [4,3,2,1], queries = [[1,3,2],[0,2,1]]

Output: -1

Explanation:

-> For i = 0 (l = 1, r = 3, val = 2):
    -> Decrement values at indices [1, 2, 3] by [2, 2, 1] respectively.
    -> The array will become [4, 1, 0, 0].
-> For i = 1 (l = 0, r = 2, val = 1):
    -> Decrement values at indices [0, 1, 2] by [1, 1, 0] respectively.
    -> The array will become [3, 0, 0, 0], which is not a Zero Array.


Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 5 * 105
1 <= queries.length <= 105
queries[i].length == 3
0 <= li <= ri < nums.length
1 <= vali <= 5
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

bool checkWithDifferenceArrayTeq(vector<int> &nums, vector<vector<int>> &queries, int k){
    int n = nums.size();
    vector<int> diff(n, 0);

    // Apply the first k queries
    for (int i = 0; i <= k; i++){
        int left = queries[i][0];
        int right = queries[i][1];
        int value = queries[i][2];

        diff[left] += value;
        if (right + 1 < n){
            diff[right + 1] -= value;
        }
    }
    // Calculate the prefix sum of the difference array
    int prefixSum = 0;
    for (int i = 0; i < n; i++){
        prefixSum += diff[i];
        diff[i] = prefixSum;

        // Check if the array becomes zero
        if (nums[i] - diff[i] > 0){
            return false;
        }
    }
    return true;
}

int minZeroArray(vector<int> &nums, vector<vector<int>> &queries){
    int n = nums.size();
    int Q = queries.size();

    auto lambda = [](int x){
        return x == 0;
    };

    if (all_of(begin(nums), end(nums), lambda)){
        return 0; // no query required because all are already zero
    }

    int low = 0;
    int high = Q - 1;
    int k = -1;
    while (low <= high){
        int mid = low + (high - low) / 2;

        if (checkWithDifferenceArrayTeq(nums, queries, mid) == true){
            k = mid + 1; // possible answer
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return k;
}

int main(){
    vector<int> nums = {2, 0, 2};
    vector<vector<int>> queries = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};
    int result = minZeroArray(nums, queries);
    cout << result << endl;
    return 0;
}