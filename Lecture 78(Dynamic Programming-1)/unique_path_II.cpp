/*
Unique Paths II - [Leetcode - 63(Medium)]
=========================================
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Example 2:

Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
*/ 

#include <iostream>
#include <vector>
using namespace std;

/*
===================== RECURSION (TLE) =======================
int helper(int sr, int sc, int er, int ec, vector<vector<int>>& grid){
    
    // Base Case : if out of bounds of an obstacle
    if(sr < 0 or sr >= grid.size() or sc < 0 or sc >= grid[0].size() or grid[sr][sc] == 1) return 0;
    
    // Base Case: if reached the destination
    if(sr == er and sc == ec) return 1;
    
    // Recursive Call : move right & move down
    int rightPaths = helper(sr,sc+1,er,ec,grid);
    int downPaths = helper(sr+1,sc,er,ec,grid);
    
    return rightPaths + downPaths;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstaclesGrid){
    
    // No paths if the grid is empty or starting point is an obstacle
    if(obstaclesGrid.empty() or obstaclesGrid[0].empty() or obstaclesGrid[0][0] == 1) return 0;
    
    int m = obstaclesGrid.size();
    int n = obstaclesGrid[0].size();
    
    return helper(0,0,m-1,n-1,obstaclesGrid);
}
*/ 

int helper(int sr, int sc, int er, int ec, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid){
    
    //  If the current position os out of bound or is an obstacle, return 0
    if(sr < 0 or sr > er or sc < 0 or sc > ec or obstacleGrid[sr][sc] == 1) return 0;
    
    // If we reach the bottom-right corner, return 1
    if(sr == er and sc == ec) return 1;
    
    // If the result is already found, return it
    if(dp[sr][sc] != -1) return dp[sr][sc];

    // Move right + down
    dp[sr][sc] = helper(sr,sc+1,er,ec,dp,obstacleGrid) + helper(sr+1,sc,er,ec,dp,obstacleGrid);
    
    return dp[sr][sc];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
    
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    
    // If the starting or ending cell is an obstacle, return 0
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
    
    vector<vector<int>> dp(m,vector<int>(n,-1));
    
    return helper(0,0,m-1,n-1,dp,obstacleGrid);
}

/*
====================== TABULATION ==============================
int uniquePathsWithObstacles (vector<vector<int>>& obstaclesGrid){
    
    // No paths if the grid is empty or starting point is an obstacle
    if(obstaclesGrid.empty() or obstaclesGrid[0].empty() or obstaclesGrid[0][0] == 1) return 0;
    
    int m = obstaclesGrid.size();
    int n = obstaclesGrid[0].size();
    
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            
            // If the cell is an obstacle, set paths to 0
            if(obstaclesGrid[i][j] == 1) dp[i][j] = 0;
            else {
                // If not the first row, add paths from the cell above
                if(i > 0) dp[i][j] += dp[i-1][j];
                
                // If not the first column, add paths from the cell to the left
                if(j > 0) dp[i][j] += dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
}
*/ 

int main(){
    
    vector<vector<int>> obstaclesGrid = {{0,0,0},{0,1,0},{0,0,0}};
    
    cout<<"unique paths with obstacles is: "<<uniquePathsWithObstacles(obstaclesGrid)<<endl;

    return 0;
}