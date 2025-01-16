/*
Unique Paths - [Leetcode - 62]
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:

Input: m = 3, n = 7
Output: 28

Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
*/

#include <iostream>
#include <vector>
using namespace std;

/*
sr - Starting Row
sc - Starting Column
Er - Ending Row
Ec - Ending Column
*/ 

/*
============== ONLY RECURSION (TLE) ==============
int helper(int sr, int sc, int er, int ec){ 
    if(sr == er && sc == ec) return 1;
    if(sr > er || sc > ec) return 0;
    int rightWays = helper(sr,sc+1,er,ec);
    int downWays = helper(sr+1,sc,er,ec);
    return rightWays + downWays;
}
int uniquePaths(int m, int n){
    return helper(0,0,m-1,n-1);

    2nd Approch(not required helper function)
    if(m==1 and n==1) return 1;
    if(m==0 or n==0) return 0;
    return uniquePath(m-1,n) + uniquePath(m,n-1);
}
*/


int helper(int sr, int sc, int er, int ec, vector<vector<int>>& dp){
    if(sr == er && sc == ec) return 1;
    if(sr > er || sc > ec) return 0;
    if(dp[sr][sc] != -1) return dp[sr][sc];
    return dp[sr][sc] = helper(sr,sc+1,er,ec,dp) + helper(sr+1,sc,er,ec,dp);
}
int uniquePaths(int m, int n){
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return helper(0,0,m-1,n-1,dp);
}


/*
====================== TABULATION ======================
int uniquePath(int m, int n){
    int dp[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;i<n;j++){
            if(i == 0 or j == 0) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}
*/ 

int main(){

    int m = 3, n = 7;

    cout<<"Number of unique Path is: "<<uniquePaths(m,n);

    return 0;
}