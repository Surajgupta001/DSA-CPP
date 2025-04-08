/*
Minimum Increment to Make Array Unique - [Leetcode - 945(Medium)]
=================================================================
You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.

Return the minimum number of moves to make every value in nums unique.

The test cases are generated so that the answer fits in a 32-bit integer.

Example 1:

Input: nums = [1,2,2]
Output: 1
Explanation: After 1 move, the array could be [1, 2, 3].

Example 2:

Input: nums = [3,2,1,2,1,7]
Output: 6
Explanation: After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown that it is impossible for the array to have all unique values with 5 or less moves.
 

Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
int minIncrementForUnique(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    vector<int> freq(100001, 0);
    
    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
    }
    
    for (int i = 0; i < 100001; i++) {
        if (freq[i] > 1) {
            ans += freq[i] - 1;
            if (i < 100000) { // Add this conditional statement
                freq[i + 1] += freq[i] - 1;
            }
        }
    }
    return ans;
}
*/ 


int minIncrementForUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int moves = 0;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] <= nums[i - 1]) {
            int increment = nums[i - 1] - nums[i] + 1;
            moves += increment;
            nums[i] += increment;
        }
    }
    return moves;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> nums = {3,2,1,2,1,7};
    cout << "Minimum number of moves to make every value in nums unique: " << minIncrementForUnique(nums) << endl;

    return 0;
}