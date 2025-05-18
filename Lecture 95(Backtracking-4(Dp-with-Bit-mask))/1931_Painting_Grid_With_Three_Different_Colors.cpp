/*
Painting a Grid With Three Different Colors - [Leetcode - 1931(Hard)]
----------------------------------------------------------------------
You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.

Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.

Example 1:

Input: m = 1, n = 1
Output: 3
Explanation: The three possible colorings are shown in the image above.

Example 2:

Input: m = 1, n = 2
Output: 6
Explanation: The six possible colorings are shown in the image above.
Example 3:

Input: m = 5, n = 5
Output: 580986
 

Constraints:

1 <= m <= 5
1 <= n <= 1000
*/ 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

// Generate all valid column states (no two adjacent cells same color)
void generateStates(int m, int curr, int pos, int last, vector<int>& states) {
    if (pos == m) {
        states.push_back(curr);
        return;
    }
    for (int color = 0; color < 3; ++color) {
        if (color != last) {
            generateStates(m, curr * 3 + color, pos + 1, color, states);
        }
    }
}

// Check if two states are compatible (no same color in same row)
bool isCompatible(int a, int b, int m) {
    for (int i = 0; i < m; ++i) {
        if ((a % 3) == (b % 3)) return false;
        a /= 3; b /= 3;
    }
    return true;
}

int colorTheGrid(int m, int n) {
    vector<int> states;
    generateStates(m, 0, 0, -1, states);
    int S = states.size();

    // Precompute compatibility
    vector<vector<int>> compatible(S);
    for (int i = 0; i < S; ++i)
        for (int j = 0; j < S; ++j){
            if (isCompatible(states[i], states[j], m)){
                compatible[i].push_back(j);
            }
        }

    // DP 
    vector<vector<int>> dp(n, vector<int>(S, 0));
    for (int i = 0; i < S; ++i){
        dp[0][i] = 1;
    }
    
    for (int col = 1; col < n; ++col){
        for (int i = 0; i < S; ++i){
            for (int j : compatible[i]){
                dp[col][i] = (dp[col][i] + dp[col-1][j]) % MOD;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < S; ++i) res = (res + dp[n-1][i]) % MOD;
    return res;
}

int main() {
    
    int m = 5, n = 5;
    
    cout << colorTheGrid(m, n) << endl;
    
    return 0;
}