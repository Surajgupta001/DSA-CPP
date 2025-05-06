/*
96. Unique Binary Search Trees - [Leetcode - 96(Medium)]
---------------------------------------------------------
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

Example 1:

Input: n = 3
Output: 5

Example 2:

Input: n = 1
Output: 1
 
Constraints:

1 <= n <= 19

*/

#include <iostream>
#include <vector>
using namespace std;

// Recursive Approach with Memoization
int numTrees(int n, vector<int>& dp){
    if(n == 0 or n == 1) return 1;

    if(dp[n] != -1) return dp[n];

    int count = 0;
    for(int i=1; i<=n; i++){
        count += numTrees(i-1, dp) * numTrees(n-i, dp);
    }
    dp[n] = count; // Store the result in dp[n]
    return count;
}

int main() {
    
    int n = 3; // Example input
    
    vector<int> dp(n + 1, -1); // Initialize dp array with -1
    cout << "Number of unique BSTs for n = " << n << " is: " << numTrees(n, dp) << endl;
    
    return 0;
}

// =============================================================================================== 

// Bottom-Up Dynamic Programming Approach
int numTrees(int n) {
    // Step 1. Create a dp vector of size n+1 and initialize it with 0.
    vector<int> dp(n + 1, 0);
    
    // Step 2. Base Case: There is one unique BST for 0 nodes and one unique BST for 1 node.
    dp[0] = 1;
    dp[1] = 1;
    
    // Step 3. Fill the dp vector using the formula:
    // dp[i] = sum of dp[j-1] * dp[i-j] for j from 1 to i
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    
    // Step 4. Return the result for n nodes.
    return dp[n];
}

int main() {
    
    int n = 3;
    
    cout << "Number of unique BSTs for n = " << n << " is: " << numTrees(n) << endl;
    
    return 0;
}