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

string helper(string &str1, string &str2, int m, int n, vector<vector<string>>& dp){
    // Base Case: If one of the strings is empty, return the other string
    if(m == 0) return str2.substr(0, n);
    if(n == 0) return str1.substr(0, m);

    // If the result is ready computed, return it from ths DP table
    if(dp[m][n] != "") return dp[m][n];
    // if(!dp[m][n].empty()) return dp[m][n];

    // if the last character of both strings are the same, add it to result
    if(str1[m - 1] == str2[n - 1]){
        dp[m][n] = helper(str1, str2, m-1, n-1, dp) + str1[m-1];
    }
    else{
        // Otherwise, try both possibilities and return the shorter one 
        string left = helper(str1, str2, m - 1, n, dp);
        string right = helper(str1, str2, m, n - 1, dp);
        dp[m][n] = (left.length() < right.length()) ? left + str1[m-1] : right + str2[n-1];
    }
    return dp[m][n];
}

string shortestCommonSupersequence(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    vector<vector<string>> dp(m+1, vector<string>(n+1, ""));
    return helper(str1, str2, m, n, dp);
}

int main(){
    
    string str1, str2;
    cout<<"Enter the first string: ";
    cin>>str1;

    cout<<"Enter the second string: ";
    cin>>str2;

    cout<<"Shortest Common Supersequence is: "<<shortestCommonSupersequence(str1, str2)<<endl; // Output: "cabac"

    return 0;
}