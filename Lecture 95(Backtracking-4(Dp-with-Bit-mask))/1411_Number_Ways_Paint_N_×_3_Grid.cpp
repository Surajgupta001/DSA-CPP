/*
Number of Ways to Paint N × 3 Grid - [Leetcode - 1411(Hard)]
-------------------------------------------------------------
You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).

Given n the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 109 + 7.

Example 1:


Input: n = 1
Output: 12
Explanation: There are 12 possible way to paint the grid as shown.
Example 2:

Input: n = 5000
Output: 30228214
 

Constraints:

n == grid.length
1 <= n <= 5000

Similar Problems: 1931 - [Leetcode(Hard)] : Painting a Grid With Three Different Colors => (Genrate Columns States)

Both of them solved using Recursion, DP and Bitmask with DP(Efficient Approach) approach
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

// Generate all valid row states (no two adjacent cells in a row have the same color)
void generateRowStates(string curr, char prev, int len, vector<string>& rowStates) {
    if (len == 3) {
        rowStates.push_back(curr);
        return;
    }
    for (char c : {'R', 'Y', 'G'}) {
        if (c != prev) {
            generateRowStates(curr + c, c, len + 1, rowStates);
        }
    }
}

// Check if two row states are compatible (no cell in the same column has the same color)
bool isCompatible(const string& a, const string& b) {
    for (int i = 0; i < 3; ++i) {
        if (a[i] == b[i]) return false;
    }
    return true;
}

int numOfWays(int n) {
    vector<string> rowStates;
    generateRowStates("", '#', 0, rowStates);
    int S = rowStates.size();

    // Precompute compatibility
    vector<vector<int>> compatible(S);
    for (int i = 0; i < S; ++i){
        for (int j = 0; j < S; ++j){
            if (isCompatible(rowStates[i], rowStates[j])){
                compatible[i].push_back(j);
            }
        }
    }

    // DP
    vector<vector<int>> dp(n, vector<int>(S, 0));
    for (int i = 0; i < S; ++i){
        dp[0][i] = 1; // Base case: one way to paint the first row with each state
    }
    for (int row = 1; row < n; ++row){
        for (int i = 0; i < S; ++i){
            for (int j : compatible[i]){
                dp[row][i] = (dp[row][i] + dp[row-1][j]) % MOD;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < S; ++i){
        result = (result + dp[n-1][i]) % MOD; // Sum up all ways to paint the last row
    }
    return result;
}

int main() {
    int n = 1;
    cout << numOfWays(n) << endl; // Output: 12

    return 0;
}