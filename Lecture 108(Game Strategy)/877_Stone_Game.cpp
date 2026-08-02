/*
Stone Game - [Leetcode - 877(Medium)]
------------------------------------------
Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

Example 1:

Input: piles = [5,3,4,5]
Output: true
Explanation: 
Alice starts first, and can only take the first 5 or the last 5.
Say she takes the first 5, so that the row becomes [3, 4, 5].
If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points.
If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alice, so we return true.

Example 2:

Input: piles = [3,7,2,3]
Output: true 

Constraints:

2 <= piles.length <= 500
piles.length is even.
1 <= piles[i] <= 500
sum(piles[i]) is odd.
*/

// NOTE : EXACT AS 486_Predict_the_Winner.cpp, JUST CHANGED VARIABLE NAMES AND FUNCTION NAMES

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int helper(int i, int j, vector<int>& piles, vector<vector<int>>& dp) {
    if(i > j) return 0; // Base case: If the indices cross, return 0 (no score can be obtained).
    if(i == j) return piles[i]; // Base case: If there's only one pile left, return its value.

    if(dp[i][j] != -1) return dp[i][j];

    int take_i = piles[i] + min(helper(i+2, j, piles, dp) , helper(i+1, j-1, piles, dp));
    int take_j = piles[j] + min(helper(i, j-2, piles, dp), helper(i+1, j-1, piles, dp));

    return dp[i][j] = max(take_i, take_j);
}

bool stoneGame(vector<int>& piles) {
    int n = piles.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    int sum = accumulate(piles.begin(), piles.end(), 0);

    int alice_score = helper(0, n-1, piles, dp);
    
    return alice_score > sum / 2;
}

// Little Better Approach (odd even indices) ===================
bool stoneGame(vector<int>& piles) {
    // Since the number of piles is even and the sum is odd, Alice can always choose to take either all odd-indexed piles or all even-indexed piles.
    // She will choose the group with the higher total value.
    // that means Alice can always win by choosing the optimal strategy.
    return true;
}

int main() {
    vector<int> piles = {5, 3, 4, 5};
    cout << (stoneGame(piles) ? "Alice wins" : "Bob wins") << endl;

    return 0;
}