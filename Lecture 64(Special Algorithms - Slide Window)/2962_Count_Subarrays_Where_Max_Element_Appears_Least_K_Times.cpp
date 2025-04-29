/*
Count Subarrays Where Max Element Appears at Least K Times - [Leetcode - 2962(Medumium)]
========================================================================================
You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.

Example 1:

Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].

Example 2:

Input: nums = [1,4,2,1], k = 3
Output: 0
Explanation: No subarray contains the element 4 at least 3 times.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106
1 <= k <= 105
*/ 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Approach : 1 - Sliding Window Technique - O(n) time complexity and O(1) space complexity
long long countSubarrays(vector<int>& nums, int k) {
    int maxElement = *max_element(nums.begin(), nums.end());

    int n = nums.size();
    int i = 0;
    int j = 0;

    long long result = 0;
    int countMax = 0; // Count of max element in the current window


    while(j < n){
        if(nums[j] == maxElement){
            countMax++;
        }
        while(countMax >= k){
            result += (n - j); // All subarrays starting from i to j and ending at n-1
            if(nums[i] == maxElement){
                countMax--;
            }
            i++;
        }
        j++;
    }
    return result;
}

// Approach : 2 - Without Sliding Window
long long countSubarrays(vector<int>& nums, int k){
    int maxElement = *max_element(nums.begin(), nums.end());

    int n = nums.size();

    long long result = 0;

    vector<int> maxIndices; // Store the indices of max elements
    for(int i = 0; i < n; i++){
        if(nums[i] == maxElement){
            maxIndices.push_back(i);
        }

        int size = maxIndices.size();

        if (size >= k){
            int last_index = maxIndices[size - k];
            result = result + (last_index + 1);
        }
    }
    return result;
}

int main(){
    
    vector<int> nums = {1, 3, 2, 3, 3};
    int k = 2;
    cout << "Count of subarrays where max element appears at least k times: " << countSubarrays(nums, k) << endl;
    
    return 0;
}