/*
Two Sum - [Leetcode-1(Easy)]
==================================
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/ 

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find the indices of the two numbers that add up to the target
vector<int>twoSum(vector<int>& v, int key){
    unordered_map<int,int>map; // Create a map to store number and its index
    vector<int>ans(2,-1); // Initialize the answer vector with -1 ; size = 2;
    for(int i=0;i<v.size();i++){
        if(map.find(key-v[i]) != map.end()){ // Check if the complement (key - current number) exists in the map
            ans[0] = map[key-v[i]]; // Get the index of the complement
            ans[1] = i; // Store the current index
            return ans; // Return the indices
        }
        else map[v[i]] = i; // Store the current number and its index in the map
    }
    return ans; // Return the answer (will be [-1, -1] if no solution found)
}

int main(){

    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    vector<int>v(n);
    cout<<"Enter all the element of vector: ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int key;
    cout<<"Enter the target sum: ";
    cin>>key;

    vector<int> ans = twoSum(v,key);

    cout<<"Indices of the pair: "<<ans[0]<<" "<<ans[1]<<endl; // size of ans vector i.e size = 2

    return 0;
}