/*
Longest Common Subsequence - [Leetcode - 1143(Medium)]
---------------------------------------------------------
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 
Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
*/ 

#include <iostream>
#include <vector>
using namespace std;

// Recursion + Memoization Approach
int helper(string &text1, string &text2, int i, int j, vector<vector<int>> &dp) {
    int m = text1.length();
    int n = text2.length();

    if (i >= m || j >= n) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    if (text1[i] == text2[j]) {
        return dp[i][j] = 1 + helper(text1, text2, i + 1, j + 1, dp);
    } else {
        return dp[i][j] = max(helper(text1, text2, i + 1, j, dp), helper(text1, text2, i, j + 1, dp));
    }
}

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return helper(text1, text2, 0, 0, dp);
}

// Bottom-Up Dynamic Programming Approach
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // First row and first column will be 0 as initialized
    for(int row = 0; row < m+1; row++){
        dp[row][0] = 0;
    }
    for(int col = 0; col < n+1; col++){
        dp[0][col] = 0;
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(text1[i-1] == text2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    cout << "Length of Longest Common Subsequence: " << longestCommonSubsequence(text1, text2) << endl;
    return 0;
}