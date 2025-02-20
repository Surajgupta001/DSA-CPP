/*
Range Sum Query - Immutable - [Leetcode - 303(Easy)]
====================================================
Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 

Example 1:

Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]

Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
 

Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105
0 <= left <= right < nums.length
At most 104 calls will be made to sumRange.
*/ 

#include <iostream>
#include <vector>
using namespace std;

class NumArray{
    public:
    vector<int> v; // Prefix array of nums
    NumArray(vector<int>& nums){
        v = nums;
        for(int i=1; i<v.size(); i++){
            v[i] += v[i-1]; // prefix sum
        }
    }
    int sumRange(int left, int right){
        if(left == 0) return v[right];
        return v[right] - v[left-1];
    }
};


int main() {
    // Create a NumArray object with the given array
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);

    // Test the sumRange function
    cout << "Sum of elements from index 0 to 2: " << numArray.sumRange(0, 2) << endl;
    cout << "Sum of elements from index 2 to 5: " << numArray.sumRange(2, 5) << endl;
    cout << "Sum of elements from index 0 to 5: " << numArray.sumRange(0, 5) << endl;

    return 0;
}