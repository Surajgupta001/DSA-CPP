/*
Combination Sum II - [Leetcode - 40(Medium)]
=============================================
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> ans; // global
void helper(vector<int>& candidate, int target, int idx, vector<int>& subset){
    if(target == 0){
        // we found a subset which sums to target
        ans.push_back(subset);
        return;
    }
    if(idx == candidate.size()) return;
    if(candidate[idx] <= target){ // pick
        subset.push_back(candidate[idx]);
        helper(candidate, target - candidate[idx], idx + 1, subset);
        subset.pop_back(); // backtrack
    }
    // avoid
    int j = idx + 1;
    while(j < candidate.size() and candidate[j] == candidate[j-1]) j++;
    helper(candidate, target, j, subset);
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> subset;
    ans.clear();
    helper(candidates, target, 0, subset);
    return ans;
}

int main(){

    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> result = combinationSum2(candidates, target);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;
}