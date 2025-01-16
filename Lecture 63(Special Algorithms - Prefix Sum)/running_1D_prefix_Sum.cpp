/*
Running Sum of 1D Array - (LEETCODE-1480)

Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.


Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
Example 2:

Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
Example 3:

Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]
*/ 

#include <iostream>
#include <vector>
using namespace std;

// 1st Approch
vector<int>runningSum(vector<int>&nums){
    vector<int>result(nums.size());
    result[0] = nums[0];
    for(int i=1;i<nums.size();i++){
        result[i] = nums[i] + result[i-1];
    }
    return result;
}

// 2nd Approch / better approch
vector<int>runningSum(vector<int>&nums){
    for(int i=1;i<nums.size();i++){
        nums[i] += nums[i-1];
    }
    return nums;
}

int main(){

    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    cout<<"Original Array: ";
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    vector<int>result = runningSum(v);

    cout<<"Prefix Sum Array: ";
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

    return 0;
}