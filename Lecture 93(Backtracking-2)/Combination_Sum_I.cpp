/*
Combination Sum - [Leetcode - 39(Medium)]
=============================================
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:

Input: candidates = [2], target = 1
Output: []
 

Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40
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
        helper(candidate, target - candidate[idx], idx, subset);
        subset.pop_back(); // backtrack
    }
    // avoid
    int j = idx + 1;
    // while(j < candidate.size() and candidate[j] == candidate[j-1]) j++;
    helper(candidate, target, j, subset);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> subset;
    ans.clear();
    helper(candidates, target, 0, subset);
    return ans;
}

int main(){

    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> result = combinationSum(candidates, target);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;
}