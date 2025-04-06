/*
Subsets - [Leetcode - 78(Medium)]
===================================

Given an integer array nums of unique elements, return all possible subsets(the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:

Input: nums = [0]
Output: [[],[0]]

All the numbers of nums are unique.
*/ 

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ans; // global

void helper(vector<int>&v, int start, vector<int>curr){
    ans.push_back(curr); // add the current subset to the answer list 
    for(int i = start; i < v.size(); i++){
        curr.push_back(v[i]); // add the current element to the current subset
        helper(v, i + 1, curr); // recursively call the helper function with the updated
        curr.pop_back(); // backtrack by removing the last element from the current subset
    }
}

vector<vector<int>> subsets(vector<int>& v){
    ans.clear(); // clear the answer list before calling the helper function
    helper(v, 0, {}); // call the helper function with the initial subset as an
    return ans;
}

int main(){
    vector<int> v = {1, 2, 3};
    vector<vector<int>> result = subsets(v);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout<<result[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;
}