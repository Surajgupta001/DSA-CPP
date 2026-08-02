/*
Stone Game II - [Leetcode - 1140(Medium)]
-------------------------------------------------
Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]. The objective of the game is to end with the most stones.

Alice and Bob take turns, with Alice starting first.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

Example 1:

Input: piles = [2,7,9,4,4]

Output: 10

Explanation:

If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 stones in total.
If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 stones in total.
So we return 10 since it's larger.

Example 2:

Input: piles = [1,2,3,4,5,100]

Output: 104

Constraints:

1 <= piles.length <= 100
1 <= piles[i] <= 10^4
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
using namespace std;

int solveForAlice(int person, int i, int M, vector<int>& piles, vector<vector<vector<int>>>& dp) {
    int n = piles.size();

    if(i >= n) return 0; // Base case: If there are no more piles left, return 0.

    int result = (person == 1) ? -1 : INT_MAX; // Initialize result based on the current player.

    int stones = 0; // To keep track of the total stones taken in this turn.

    if(dp[person][i][M] != -1) return dp[person][i][M]; // Return the cached result if it exists.

    for(int x = 1; x <= min(2 * M, n - i); x++) { // Loop through the possible number of piles to take (from 1 to 2M or the remaining piles).
        
        stones += piles[i + x - 1]; // Add the stones from the current pile to the total.
        
        if(person == 1){ // If it's Alice's turn, we want to maximize her score.
            result = max(result, stones + solveForAlice(0, i + x, max(M, x), piles, dp)); // Update result with the maximum score Alice can achieve.
        } else { // If it's Bob's turn, we want to minimize Alice's score.
            result = min(result, solveForAlice(1, i + x, max(M, x), piles, dp)); // Update result with the minimum score Alice can achieve after Bob's turn.
        }
    }

    return dp[person][i][M] = result;
}

int stoneGameII(vector<int>& piles) {
    int n = piles.size();
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n + 1, -1))); // 3D DP array to store results for each player, index, and M value.
    return solveForAlice(1, 0, 1, piles, dp); // Start the game with Alice's turn, starting at index 0 and M = 1.
}

int main() {
    vector<int> piles = {2, 7, 9, 4, 4};
    cout << "Maximum stones Alice can get: " << stoneGameII(piles) << endl; // Output: 10

    vector<int> piles2 = {1, 2, 3, 4, 5, 100};
    cout << "Maximum stones Alice can get: " << stoneGameII(piles2) << endl; // Output: 104

    return 0;
}