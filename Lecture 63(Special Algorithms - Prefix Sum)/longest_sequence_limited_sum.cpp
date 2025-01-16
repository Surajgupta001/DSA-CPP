/*
LONGEST SUBSEQUENCE WITH LIMITED SUM - (LEETCODE - 2389)
==============================================
You are given an integer array nums of length n, and an integer array queries of length m.

Return an array answer of length m where answer[i] is the maximum size of a subsequence that you can take from nums such that the sum of its elements is less than or equal to queries[i].

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
 

Example 1:

Input: nums = [4,5,2,1], queries = [3,10,21]
Output: [2,3,4]
Explanation: We answer the queries as follows:
- The subsequence [2,1] has a sum less than or equal to 3. It can be proven that 2 is the maximum size of such a subsequence, so answer[0] = 2.
- The subsequence [4,5,1] has a sum less than or equal to 10. It can be proven that 3 is the maximum size of such a subsequence, so answer[1] = 3.
- The subsequence [4,5,2,1] has a sum less than or equal to 21. It can be proven that 4 is the maximum size of such a subsequence, so answer[2] = 4.

Example 2:

Input: nums = [2,3,4,5], queries = [1]
Output: [0]
Explanation: The empty subsequence is the only subsequence that has a sum less than or equal to 1, so answer[0] = 0.
*/ 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>answerQuaries(vector<int>&nums, vector<int>&queries){
    int n = nums.size();
    int m = queries.size();
    vector<int>ans(m);

    // sort vector
    sort(nums.begin(), nums.end()); // TIME: O(nlogn), SPACE: O(logn)

    // make nums prefix sum
    for(int i=1; i<n; i++){
        nums[i] += nums[i-1];
    }

    // 1ST approch
    // for every queries traverse
    for(int i=0; i<m; i++){ // TIME: O(m*n)
        int len = 0;
        for(int j=0;j<n;j++){
            if(nums[j] > queries[i]) break;
            len++;
        }
        ans[i] = len;
    }

    // 2nd Approch
    // BINARY SEARCH
    for(int i=0; i<m; i++){ // TIME: O(m*(logn))
        int maxLen =  0;
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] > queries[i]){
                high = mid-1;
            }
            else{
                maxLen = mid+1;
                low = mid+1;
            }
        }
        ans[i] = maxLen;
    }
    return ans; // TIME: O(m+n)logn)
}

int main() {
    vector<int> nums = {4, 5, 1, 3, 2};
    vector<int> queries = {3, 1, 4, 1};
    vector<int> result = answerQuaries(nums, queries);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}