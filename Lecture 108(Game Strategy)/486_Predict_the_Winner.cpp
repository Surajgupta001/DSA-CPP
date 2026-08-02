/*
Predict the Winner - [Leetcode - 486(Medium)]
-------------------------------------------------

You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.

Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.
 

Example 1:

Input: nums = [1,5,2]
Output: false
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return false.

Example 2:

Input: nums = [1,5,233,7]
Output: true
Explanation: Player 1 first chooses 1. Then player 2 has to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win. 

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 10^7
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int helper(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
    if(i > j) return 0; // Base case: If the indices cross, return 0 (no score can be obtained).
    if(i == j) return nums[i]; // Base case: If there's only one element left, return its value.

    if(dp[i][j] != -1) return dp[i][j];

    int take_i = nums[i] + min(helper(i+2, j, nums, dp) , helper(i+1, j-1, nums, dp));
    int take_j = nums[j] + min(helper(i, j-2, nums, dp), helper(i+1, j-1, nums, dp));

    return dp[i][j] = max(take_i, take_j);
}

bool predictTheWinner(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    int total_score = accumulate(nums.begin(), nums.end(), 0);

    int player1_score = helper(0, n-1, nums, dp);

    int player2_score = total_score - player1_score;

    return player1_score >= player2_score;
}

// ========== Little Better Approach ===================

// Taking the difference of scores of player 1 and player 2,
// we can say that if the difference is greater than or equal to 0, then player 1 can win.
// Otherwise, player 2 will win.
int helper1(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
    if(i > j) return 0; // Base case: If the indices cross, return 0 (no score can be obtained).
    if(i == j) return nums[i]; // Base case: If there's only one element left, return its value.

    if(dp[i][j] != -1) return dp[i][j];

    int take_i = nums[i] - helper1(i+1, j, nums, dp);
    int take_j = nums[j] - helper1(i, j-1, nums, dp);

    return dp[i][j] = max(take_i, take_j);
}

bool predictTheWinner(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return helper1(0, n-1, nums, dp) >= 0;
}

// =======================================================

int main() {
    vector<int> nums = {1, 5, 233, 7};
    bool result = predictTheWinner(nums);
    cout << (result ? "Player 1 can win" : "Player 1 cannot win") << endl;
    return 0;
}