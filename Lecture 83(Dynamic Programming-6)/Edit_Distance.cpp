/*
Edit Distance - [Leetcode-72(medium)]
=======================================
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/ 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
=============== Recursion ===================
int helper(string &str1, string &str2, int i, int j){
    if(i == str1.size()) return str2.length()-j;
    if(j == str2.size()) return str1.length()-i;
    
    if(str1[i] == str2[j]) return helper(str1, str2, i+1, j+1);
    return min({1 + helper(str1, str2, i+1, j+1), 1 + helper(str1, str2, i+1, j), 1 + helper(str1, str2, i, j+1)});
}
*/ 

int helper(string &str1, string &str2, int i, int j, vector<vector<int>>& dp){
    if(i == str1.size()) return str2.length()-j;
    if(j == str2.size()) return str1.length()-i;
    if(dp[i][j] != -1) return dp[i][j];
    if(str1[i] == str2[j]) return dp[i][j] = helper(str1, str2, i+1, j+1,dp);
    return dp[i][j] = min({1 + helper(str1, str2, i+1, j+1,dp), 1 + helper(str1, str2, i+1,j,dp), 1 + helper(str1, str2, i, j+1,dp)});
}
int minDistance(string word1, string word2){
    int n = word1.length(), m = word2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
    return helper(word1, word2, 0, 0, dp);
}

int main(){
    
    string word1 = "horse";
    string word2 = "ros";
    
    cout<<minDistance(word1, word2)<<endl;
    
    return 0;
}