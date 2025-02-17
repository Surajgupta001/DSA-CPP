/*
Subsets - [Leetcode - 78(Medium)]
==================================
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:

Input: nums = [0]
Output: [[],[0]]

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/ 
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ans; // global

void helper(vector<int>& v, int start, vector<int> curr){
    ans.push_back(curr);
    for(int i = start; i < v.size(); i++){
        curr.push_back(v[i]);
        helper(v, i + 1, curr);
        curr.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums){
    ans.clear(); // Clear the global variable before each use
    helper(nums, 0, {});
    return ans;
}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = subsets(nums);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;
}