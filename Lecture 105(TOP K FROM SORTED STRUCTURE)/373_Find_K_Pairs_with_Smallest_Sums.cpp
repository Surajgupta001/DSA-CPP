/*
Find K Pairs with Smallest Sums - [Leetcode - 373(Medium)]
-----------------------------------------------------------
You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 
Constraints:

1 <= nums1.length, nums2.length <= 10^5
-10^9 <= nums1[i], nums2[i] <= 10^9
nums1 and nums2 both are sorted in non-decreasing order.
1 <= k <= 10^4
k <= nums1.length * nums2.length
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// PATTERN: TOP K FROM SORTED STRUCTURE
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    // Priority queue to store pairs with their sums - MIN-HEAP => (sum, (i, j))
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;


    int m = nums1.size();
    int n = nums2.size();

    // Initialize the heap with the first element of nums2 paired with each element of nums1
    for(int i = 0; i < min(k, m); i++){
        int sum = nums1[i] + nums2[0];
        minHeap.push({sum, {i, 0}});
    }

    vector<vector<int>> result;
    
    while(k > 0 && !minHeap.empty()){
        auto current = minHeap.top();
        minHeap.pop();

        int i = current.second.first;
        int j = current.second.second;

        result.push_back({nums1[i], nums2[j]});

        // If there's a next element in nums2 for the same element in nums1, add it to the heap
        if(j + 1 < n){
            int sum = nums1[i] + nums2[j + 1];
            minHeap.push({sum, {i, j + 1}});
        }
        k--;
    }

    return result;
}

int main () {
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 3;

    vector<vector<int>> result = kSmallestPairs(nums1, nums2, k);

    for (const auto& pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;

    return 0;
}