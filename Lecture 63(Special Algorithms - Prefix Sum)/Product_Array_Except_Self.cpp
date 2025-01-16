/*
PRODUCT OF ARRAY EXERCISE SELF - (LEETCODE -238)

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the DIVISION operation.


Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/ 

#include <iostream>
#include <vector>
using namespace std;

// WITH DIVISION
vector<int>productExceptSelf(vector<int>&nums){
    int product_1 = 1;
    int product_2 = 1;
    int nonZero = 0;

    for(int i=0;i<nums.size();i++){
        if(nums[i] != 0) nonZero++;
        product_1 *= nums[i];
        if(nums[i] != 0) product_2 *= product_2;
    }

    if(nonZero>1) product_2 = 0;
    for(int i=0 ;i<nums.size();i++){
        if(nums[i] == 0) nums[i] = product_2;
        else nums[i] = product_1/nums[i];
    }
    return nums;
}

// WITHOUT DIVISION
vector<int>productExceptSelf(vector<int>&nums){
    int n = nums.size();
    vector<int>pre(n);
    vector<int>suf(n);

    // prefix product array
    int product = nums[0];
    for(int i=1;i<n;i++){
        pre[i] = product;
        product *= nums[i];
    }

    // suffix product array
    product = nums[n-1];
    suf[n-1] = 1;
    for(int i=n-2;i>=0;i--){
        suf[i] = product;
        product *= nums[i];
    }

    // pre[i] = pre[i]*suf[i]
    for(int i=0;i<n;i++){
        pre[i] = pre[i]*suf[i];
    }
    return pre;
}

// WITHOUT DIVISION-1
vector<int>productExceptSelf(vector<int>&nums){
    int n = nums.size();
    vector<int>pre(n);

    // prefix product array
    int product = nums[0];
    for(int i=1;i<n;i++){
        pre[i] = product;
        product *= nums[i];
    }

    // suffix product array(in prefix only)
    product = nums[n-1];
    for(int i=n-2;i>=0;i--){
        pre[i] *= product; 
        product *= nums[i];
    }
}
