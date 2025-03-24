/*
Find First and Last Position of Element in Sorted Array - [Leetcode - 34(Medium)]
================================================================================
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lowerBound(vector<int>& v, int targets){
    int low = 0;
    int high = v.size() - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;
        if(v[mid] < targets) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

int upperBound(vector<int>& v, int targets){
    int low = 0;
    int high = v.size() - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;
        if(v[mid] <= targets) low = mid + 1;
        else high = mid - 1;
    }
    return high;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int low = lowerBound(nums, target);
    int high = upperBound(nums, target);

    // Check if the target elements is present in the array
    if(low <= high and nums[low] == target and nums[high] == target){
        return {low, high};
    }
    else return {-1, -1};
}

// Using STL Upper and Lower Bound
vector<int> searchRange(vector<int>& nums, int target){
    // Find the first occurrence of the target
    auto low = lower_bound(nums.begin(), nums.end(), target);

    // If the target is not found, return {-1, -1}
    if(low == nums.end() or *low != target){
        return {-1, -1};
    }

    // Find the last occurrence of the target
    auto high = upper_bound(nums.begin(), nums.end(), target);
    // Return the range of the target
    return {(int)(low - nums.begin()), (int)(high - nums.begin() - 1)};

}

int main(){
    
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    
    vector<int> result = searchRange(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    
    return 0;
}