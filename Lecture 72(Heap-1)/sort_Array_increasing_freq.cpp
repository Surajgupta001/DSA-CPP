/*
Sort Array by Increasing Frequency - [Leetcode - 1636(Easy)]
==============================================================
Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.

Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]
*/ 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> frequencySort(vector<int>& v){
    // step 1: Count frequency
    unordered_map<int, int> freq; // <ele,freq>
    for(auto ele:v) freq[ele]++;

    // step 2: Create a min-heap based on frequency and element
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq; // heap pair is <freq,ele>
    for(auto itr:freq) pq.push({itr.second, itr.first}); // Push pairs into the heap: frequency first (for sorting), then the element
    
    // step 3: Sort the array based on frequency and value
    vector<int>ans;
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        for(int i=0; i<top.first; i++) ans.push_back(top.second);
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    vector<int>v(n);
    cout<<"Enter the elements of vector: ";
    for(int i=0;i<n;i++) cin>>v[i];

    vector<int>ans = frequencySort(v);
    cout<<"Sorted vector: ";
    for(auto ele:ans) cout<<ele<<" ";

    return 0;
}