/*
Minimum Path Sum - [Leetcode - 64(Medium)]
=====================================================
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
*/ 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
========================= Recursion ==========================
int helper(vector<vector<int>>& v, int sr, int sc, int n, int m){
    
    // n -> The number of rows in the grid.
    // m -> The number of columns in the grid.
    
    if(sr == n-1 and sc == m-1) return v[n-1][m-1];
    if(sr >= n or sc >= m or sr < 0 or sc < 0) return INT_MAX;
    // int down = helper(v, sr+1, sc ,n, m);
    // int right = helper(v, sr, sc+1, n, m);
    // return v[sr][sc] + min(down, right);
    return v[sr][sc] + min(helper(v,sr+1,sc, n, m), helper(v,sr,sc+1, n, m));
}

int minPathSum(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    return helper(grid, 0, 0, n, m);
}
*/ 

int helper(vector<vector<int>>& v, vector<vector<int>>& dp, int sr, int sc, int n, int m){
    if(sr == n-1 and sc == m-1) return v[n-1][m-1];
    if(sr >= n or sc >= m or sr < 0 or sc < 0) return INT_MAX;
    if(dp[sr][sc] != -1) return dp[sr][sc];
    return dp[sr][sc] = v[sr][sc] + min(helper(v,dp,sr+1,sc,n,m), helper(v,dp,sr,sc+1,n,m));
}

int minPathSum(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper(grid,dp, 0, 0, n, m);
}

/*
====================== Tabulation ====================
int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Initialize the first cell
    dp[0][0] = grid[0][0];

    // Fill the first row
    for (int i = 1; i < m; i++) dp[0][i] = dp[0][i-1] + grid[0][i];

    // Fill the first column
    for (int i = 1; i < n; i++) dp[i][0] = dp[i-1][0] + grid[i][0];

    // Fill the rest of the table
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }

    // The minimum path sum is stored in the bottom-right cell
    return dp[n-1][m-1];
}
*/ 
int main(){
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout<<minPathSum(grid)<<endl;
    return 0;
} 