/*
Kth Largest Element in a array - [Leetcode - 215(Medium)]
===========================================================
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
*/ 

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    vector<int>v(n);
    cout<<"Enter the elements of vector: ";
    for(int i=0;i<n;i++) cin>>v[i];

    int k;
    cout<<"Enter the value of K: ";
    cin>>k;

    priority_queue<int, vector<int>, greater<int>>pq; // Min Heap
    for(int i=0;i<n;i++){
        pq.push(v[i]);
        if(pq.size() > k) pq.pop();
    }

    cout<<"Kth largest element is: "<<pq.top()<<endl;

    return 0;
}