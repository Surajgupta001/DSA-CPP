/*
Maximum Average Subarray I - [Leetcode - 643(Easy)]
=====================================================
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

Example 2:

Input: nums = [5], k = 1
Output: 5.00000
*/ 
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maximumAverageSubarray(vector<int>& v, int k){
    int maxSum = INT_MIN;
    int maxIdx = 0;
    int sum = 0;
    for(int i=0;i<k;i++) sum +=v[i];
    maxSum = sum;
    int ptr1 = 1;
    int ptr2 = k;
    while(ptr2 < v.size()){
        sum = sum + v[ptr2] - v[ptr1-1];
        if(maxSum < sum){
            maxSum = sum;
            maxIdx = ptr1;
        }
        ptr1++;
        ptr2++;
    }
    return maxSum/k;
}

int main(){

    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    vector<int>v(n);
    cout<<"Enter all the elements of vectors: ";
    for(int i=0;i<n;i++) cin>>v[i];

    int k;
    cout<<"Enter the size of SubArray: ";
    cin>>k;

    int ans = maximumAverageSubarray(v,k);
    cout<<"Maximum Average sum subarray of size "<<k<<" is: "<<ans<<endl;

    return 0;
}