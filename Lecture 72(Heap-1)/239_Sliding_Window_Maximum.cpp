/*
Sliding Window Maximum - [Leetcode - 239(Hard)]
------------------------------------------------
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]

Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:

Input: nums = [1], k = 1
Output: [1]

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length

*/ 

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> pq; // {value, index}
    vector<int> ans;

    for (int i = 0; i < nums.size(); ++i) {
        pq.push({nums[i], i});
        // Remove elements outside the window
        while (!pq.empty() && pq.top().second <= i - k) {
            pq.pop();
        }
        if (i >= k - 1) {
            ans.push_back(pq.top().first);
        }
    }
    return ans;
}

int main(){

    vector<int> nums = {1,3,-1,-3,5,3,6,7};

    int k = 3;

    vector<int> result = maxSlidingWindow(nums, k);

    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;

    return 0;
}