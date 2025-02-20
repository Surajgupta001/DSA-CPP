/*
Range Sum Query - Mutable - [Leetcode - 307(Medium)]
=====================================================
Given an integer array nums, handle multiple queries of the following types:

Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 

Example 1:

Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]

Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
 

Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
0 <= index < nums.length
-100 <= val <= 100
0 <= left <= right < nums.length
At most 3 * 104 calls will be made to update and sumRange.
*/ 

// Mutable -> If we use prefix sum array, then in each 'update' we need to change our prefix sum array.

#include <iostream>
#include <vector>
using namespace std;

class NumArray{
    public:
    vector<int> segmentTree;
    int n;
    NumArray(vector<int>& nums){
        n = nums.size();
        segmentTree.resize(4*n);
        buildTree(nums, 0, 0, n-1);
    }
    void buildTree(vector<int>& v, int i, int low, int high){
        if(low == high){
            segmentTree[i] = v[high];
            return;
        }
        int mid = low + (high-low)/2;
        buildTree(v, 2*i+1, low, mid);
        buildTree(v, 2*i+2, mid+1, high);
        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }
    void updateValue(int i, int low, int high, int &index, int &value){
        if(low == high){
            segmentTree[i] = value;
            return;
        }
        int mid = low + (high-low)/2;
        if(index <= mid){
            updateValue(2*i+1, low, mid, index, value);
        }
        else{
            updateValue(2*i+2, mid+1, high, index, value);
        }
        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }
    void update(int index, int val){ 
        updateValue(0, 0, n-1, index, val);
    }
    // Query the maximum in the range [left, right]
    int getSum(int i, int low, int high, int &left, int &right) {
        if (low >= left && high <= right) return segmentTree[i]; // Completely inside range
        if (high < left || low > right) return 0; // Completely outside range
        int mid = low + (high - low) / 2;
        int leftSum = getSum(2 * i + 1, low, mid, left, right);
        int rightSum = getSum(2 * i + 2, mid + 1, high, left, right);
        return (leftSum + rightSum);
    }
    int sumRange(int left, int right){
        return getSum(0, 0, n-1, left, right);
    }
};

int main(){
    vector<int> nums = {1, 3, 5};
    NumArray numArray(nums);
    cout << "Sum of elements in range [0, 2]: " << numArray.sumRange(0, 2) << endl;
    numArray.update(1, 2);
    cout << "Sum of elements in range [0, 2] after update: " << numArray.sumRange(0, 2) << endl;
    return 0;
}