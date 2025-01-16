/*
MINIMIZE THE SUBAARAY SUM - (LEETCODE - 209)
=============================================
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray
whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
*/ 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSubArray(int target, vector<int> &nums){
    int n = nums.size();
    int i = 0;
    int j = 0;
    int minLen = INT_MAX;
    int len;
    int sum = 0;
    while(j < n){
        sum += nums[j];
        while(sum >= target){
            len = j - i + 1;
            minLen = min(minLen, len);
            sum -= nums[i];
            i++;
        }
        j++;
    }
    if(minLen == INT_MAX) return 0;
    return minLen;
}
int main(){

    int n;
    cout<<"Enter the size of vectors: ";
    cin>>n;

    vector<int>v(n);
    cout<<"Enter the elements of vector: ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int target;
    cout<<"Enter the target sum: ";
    cin>>target;
    
    cout<<"Minimum length of subarray with sum greater than or equal to target is: "<<endl;

    cout<<minSubArray(target, v)<<endl;

    return 0;
}