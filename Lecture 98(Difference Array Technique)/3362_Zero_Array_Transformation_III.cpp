/*
Zero Array Transformation III - [Leetcode - 3362(Medium)]
----------------------------------------------------------
You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].

Each queries[i] represents the following action on nums:

=> Decrement the value at each index in the range [li, ri] in nums by at most 1.
=> The amount by which the value is decremented can be chosen independently for each index.
=> A Zero Array is an array with all its elements equal to 0.

Return the maximum number of elements that can be removed from queries, such that nums can still be converted to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.

Example 1:

Input: nums = [2,0,2], queries = [[0,2],[0,2],[1,1]]

Output: 1

Explanation:

After removing queries[2], nums can still be converted to a zero array.

Using queries[0], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
Using queries[1], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
Example 2:

Input: nums = [1,1,1,1], queries = [[1,3],[0,2],[1,3],[1,2]]

Output: 2

Explanation:

We can remove queries[2] and queries[3].

Example 3:

Input: nums = [1,2,3,4], queries = [[0,3]]

Output: -1

Explanation:

nums cannot be converted to a zero array even after using all the queries.

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105
1 <= queries.length <= 105
queries[i].length == 2
0 <= li <= ri < nums.length
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int maxRemoval(vector<int> &nums, vector<vector<int>> &queries){
    int Q = queries.size();
    int n = nums.size();

    // Sort queries based on starting index & If starting index is same, sort based on ending index
    sort(queries.begin(), queries.end());

    // To store farthest ending index of queries
    priority_queue<int> maxHeap; // Max Heap

    // To store past ending index of queries
    priority_queue<int, vector<int>, greater<int>> past; // Min Heap

    int j = 0;         // Pointing to queries
    int usedCount = 0; // How many queries I have used

    for (int i = 0; i < n; i++){
        
        // While queries are starting at i, push them into maxHeap
        while (j < Q and queries[j][0] == i){
            
            // Push the ending index of queries into maxHeap
            maxHeap.push(queries[j][1]);
            j++;
        }

        // First Check if we can impact current i from any past queries ending
        nums[i] -= past.size();

        // If we can impact current i from past queries ending, pop them
        while (nums[i] > 0 and !maxHeap.empty() and maxHeap.top() >= i){
            // Pop the farthest ending index of queries
            int ending = maxHeap.top();
            
            // Pop the farthest ending index of queries
            maxHeap.pop();
            
            // Push the ending index of queries into past
            past.push(ending);
            
            usedCount++;
            nums[i]--;
        }

        // If we can't impact current i from any past queries ending, return -1
        if (nums[i] > 0) return -1;

        // If we can impact current i from any past queries ending, pop them
        while (!past.empty() and past.top() <= i){
            // Pop the past ending index of queries
            past.pop();
        }
    }

    return Q - usedCount;
}

int main(){
    vector<int> nums1 = {2, 0, 2};
    vector<vector<int>> queries1 = {{0, 2}, {0, 2}, {1, 1}};
    cout << "Example 1: " << maxRemoval(nums1, queries1) << endl; // Expected: 1

    vector<int> nums2 = {1, 1, 1, 1};
    vector<vector<int>> queries2 = {{1, 3}, {0, 2}, {1, 3}, {1, 2}};
    cout << "Example 2: " << maxRemoval(nums2, queries2) << endl; // Expected: 2

    vector<int> nums3 = {1, 2, 3, 4};
    vector<vector<int>> queries3 = {{0, 3}};
    cout << "Example 3: " << maxRemoval(nums3, queries3) << endl; // Expected: -1

    return 0;
}