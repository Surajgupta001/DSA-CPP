/*
Print All Longest Increasing Subsequences
-----------------------------------------

Given an array of integers nums, print all possible longest strictly increasing subsequences (LIS) present in the array.

Each subsequence should be printed in the order of appearance, and each sequence should be printed on a new line.

If there are multiple LIS ending at different indices, print all of them.

Input: nums = [10, 9, 2, 5, 3, 7, 101, 18]

Output:
All Longest Increasing Subsequences of length 4:

Longest Increasing Subsequences ending at 6: 2 3 7 101
Longest Increasing Subsequences ending at 6: 2 5 7 101
Longest Increasing Subsequences ending at 7: 2 5 7 18
Longest Increasing Subsequences ending at 7: 2 3 7 18

*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
==> Time: O(n^2 * k)
==> Space: O(n * k)
where k is the number of LIS, which can be exponential for some inputs.
*/
void printAllLIS(vector<int>& nums){
    int n = nums.size();
    if(n == 0) return;

    vector<int> dp(n, 1);
    vector<vector<vector<int>>> seqs(n); // seqs[i]: all LIS ending at i


    for(int i = 0; i < n; i++){
        seqs[i].push_back({nums[i]});

        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                if(dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    seqs[i].clear();
                    for(auto & seq : seqs[j]){
                        vector<int> newSeq = seq;
                        newSeq.push_back(nums[i]);
                        seqs[i].push_back(newSeq);
                    }
                }
                else if(dp[j] + 1 == dp[i]){
                    for(auto & seq : seqs[j]){
                        vector<int> newSeq = seq;
                        newSeq.push_back(nums[i]);
                        seqs[i].push_back(newSeq);
                    }
                }
            }
        }
    }
    int maxLength = *max_element(dp.begin(), dp.end());
    cout<<"All Longest Increasing Subsequences of length "<<maxLength<<":\n";
    for(int i = 0; i < n; i++){
        if(dp[i] == maxLength){
            cout<<"Longest Increasing Subsequences ending at "<<i<<": ";
            for(auto & seq : seqs[i]){
                for(int num : seq){
                    cout<<num<<" ";
                }
                cout<<endl;
            }
        }
    }
}


// Using Backtarcking
/*
==> Time: O(n^2 + k * n)
==> Space: O(k * n)
where k is the number of LIS (can be exponential in n).
*/ 
void backtrack(vector<int>& nums, vector<int>& dp, int currIdx, int currLen, vector<int>& path, vector<vector<int>>& result){
    if(currLen == 1){
        path.push_back(nums[currIdx]);

        vector<int> seq = path;
        reverse(seq.begin(), seq.end());
        result.push_back(seq);
        path.pop_back();
        return;
    }
    path.push_back(nums[currIdx]);
    for(int prevIdx = currIdx - 1; prevIdx >= 0; prevIdx--){
        if(nums[prevIdx] < nums[currIdx] && dp[prevIdx] == currLen - 1){
            backtrack(nums, dp, prevIdx, currLen - 1, path, result);
        }
    }
    path.pop_back();
}
void printAllLIS(vector<int>& nums){
    int n = nums.size();

    if(n== 0) return;

    vector<int> dp(n, 1);

    // Buliding the dp array
    for(int i=1; i<n; i++){
        for(int j = 0; j<i; j++){
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int maxLength = *max_element(dp.begin(), dp.end());

    // Finding all LIS through backtracking
    vector<vector<int>> result;
    vector<int> path;
    for(int i = 0; i < n; i++){
        if(dp[i] == maxLength){
            backtrack(nums, dp, i, maxLength, path, result);
        }
    }
    cout<<"All Longest Increasing Subsequences of length "<<maxLength<<":\n";
    for(auto & seq : result){
        for(int num : seq){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}

int main () {
    
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    
    printAllLIS(nums);
    
    return 0;    
}