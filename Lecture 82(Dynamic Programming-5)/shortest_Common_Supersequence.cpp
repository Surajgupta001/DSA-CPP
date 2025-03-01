/*
Shortest Commom Supersequence - [Leetcode-1092(Hard)]
==========================================================

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
*/ 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
=============================== Recursion ==================================
string helper(string str1, string str2, int m, int n) {
    // Base Case: If one of the strings is empty, return the other string
    if (m == 0) return str2.substr(0, n);
    if (n == 0) return str1.substr(0, m);

    // If the last characters of both strings are the same, add it to the result
    if (str1[m - 1] == str2[n - 1]) {
        return helper(str1, str2, m - 1, n - 1) + str1[m - 1];
    }
    else{
        // Otherwise, try both possibilities and return the shorter one
        string left = helper(str1, str2, m - 1, n);
        string right = helper(str1, str2, m, n - 1);
        return (left.length() < right.length()) ? left + str1[m - 1] : right + str2[n - 1];
    }
}
*/ 

string helper(string &str1, string &str2, int m, int n, vector<vector<string>>& dp){ // Memory exceed limit
    // Base Case: If one of the strings is empty, return the other string
    if (m == 0) return str2.substr(0, n);
    if (n == 0) return str1.substr(0, m);

    // If the result is already computed, return it from the DP table
    if (!dp[m][n].empty()) return dp[m][n];

    // If the last characters of both strings are the same, add it to the result
    if (str1[m - 1] == str2[n - 1]) {
        dp[m][n] = helper(str1, str2, m - 1, n - 1, dp) + str1[m - 1];
    } else {
        // Otherwise, try both possibilities and choose the shorter one
        string left = helper(str1, str2, m - 1, n, dp);
        string right = helper(str1, str2, m, n - 1, dp);
        dp[m][n] = (left.length() < right.length()) ? left + str1[m - 1] : right + str2[n - 1];
    }
    return dp[m][n];
}

string shortestCommonSupersequence(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    vector<vector<string>> dp(m + 1, vector<string>(n + 1, ""));
    return helper(str1, str2, m, n, dp);
}

/*
============= Tabulation (Avoid Memory Exceed Limit) ===================
                    More efficient than memoization

string shortestCommonSupersequence(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();

    // DP table to store the lengths of the shortest common supersequence
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the shortest common supersequence from the DP table
    string result;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            result.push_back(str1[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] < dp[i][j - 1]) {
            result.push_back(str1[i - 1]);
            i--;
        } else {
            result.push_back(str2[j - 1]);
            j--;
        }
    }

    // Append the remaining characters of str1 or str2
    while (i > 0) {
        result.push_back(str1[i - 1]);
        i--;
    }
    while (j > 0) {
        result.push_back(str2[j - 1]);
        j--;
    }

    // Reverse the result to get the correct order
    reverse(result.begin(), result.end());
    return result;
}
*/ 

int main(){
    
    string str1, str2;
    cout<<"Enter the first string: ";
    cin>>str1;

    cout<<"Enter the second string: ";
    cin>>str2;

    cout<<"Shortest Common Supersequence is: "<<shortestCommonSupersequence(str1, str2)<<endl; // Output: "cabac"

    return 0;
}