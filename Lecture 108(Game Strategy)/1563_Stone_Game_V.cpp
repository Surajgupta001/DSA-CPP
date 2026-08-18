/*
Stone Game V - [Leetcode - 1563(Hard)]
------------------------------------------
There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

In each round of the game, Alice divides the row into two non-empty rows (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row.

The game ends when there is only one stone remaining. Alice's score is initially zero.

Return the maximum score that Alice can obtain.

Example 1:

Input: stoneValue = [6,2,3,4,5,5]
Output: 18
Explanation: In the first round, Alice divides the row to [6,2,3], [4,5,5]. The left row has the value 11 and the right row has value 14. Bob throws away the right row and Alice's score is now 11.
In the second round Alice divides the row to [6], [2,3]. This time Bob throws away the left row and Alice's score becomes 16 (11 + 5).
The last round Alice has only one choice to divide the row which is [2], [3]. Bob throws away the right row and Alice's score is now 18 (16 + 2). The game ends because only one stone is remaining in the row.

Example 2:

Input: stoneValue = [7,7,7,7,7,7,7]
Output: 28

Example 3:

Input: stoneValue = [4]
Output: 0
 

Constraints:

1 <= stoneValue.length <= 500
1 <= stoneValue[i] <= 10^6
*/

#include <iostream>
#include <vector>
using namespace std;

int helper(int left, int right, vector<int>& prefixSum, vector<vector<int>>& dp) {
    if (left >= right) return 0; // Base case: if there is only one stone left, Alice cannot score any points.

    if (dp[left][right] != -1) return dp[left][right];

    int score = 0;
    for(int mid = left; mid <= right - 1; mid++){
        int leftSum = prefixSum[mid] - (left > 0 ? prefixSum[left - 1] : 0); // [left .... mid]
        int rightSum = prefixSum[right] - prefixSum[mid]; // [mid + 1 .... right]

        if (leftSum < rightSum) {
            score = max(score, leftSum + helper(left, mid, prefixSum, dp));
        } else if (leftSum > rightSum) {
            score = max(score, rightSum + helper(mid + 1, right, prefixSum, dp));
        } else {
            score = max(score, leftSum + max(helper(left, mid, prefixSum, dp), helper(mid + 1, right, prefixSum, dp)));
        }
    }
    return dp[left][right] = score;
}

int stoneGameV(vector<int>& stoneValue) {
    int n = stoneValue.size();

    vector<int> prefixSum(n, 0);
    prefixSum[0] = stoneValue[0];
    for(int i = 1; i < n; i++){
        prefixSum[i] = prefixSum[i - 1] + stoneValue[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));
    return helper(0, n-1, prefixSum, dp);
}

// Bottom UP
int stoneGameV(vector<int>& stoneValue) {
    int n = stoneValue.size();

    vector<int> prefixSum(n, 0);
    prefixSum[0] = stoneValue[0];
    for(int i = 1; i < n; i++){
        prefixSum[i] = prefixSum[i - 1] + stoneValue[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int left = n - 1; left >= 0; left--){
        for(int right = left + 1; right < n; right++){
            int score = 0;
            for(int mid = left; mid <= right - 1; mid++){
                int leftSum = prefixSum[mid] - (left > 0 ? prefixSum[left - 1] : 0); // [left .... mid]
                int rightSum = prefixSum[right] - prefixSum[mid]; // [mid + 1 .... right]

                if (leftSum < rightSum) {
                    score = max(score, leftSum + dp[left][mid]);
                } else if (leftSum > rightSum) {
                    score = max(score, rightSum + dp[mid + 1][right]);
                } else {
                    score = max(score, leftSum + max(dp[left][mid], dp[mid + 1][right]));
                }
            }
            dp[left][right] = score;
        }
    }
    return dp[0][n - 1];
}

int main() {
    vector<int> stoneValue1 = {6, 2, 3, 4, 5, 5};
    cout << "Maximum score Alice can obtain: " << stoneGameV(stoneValue1) << endl; // Output: 18

    vector<int> stoneValue2 = {7, 7, 7, 7, 7, 7, 7};
    cout << "Maximum score Alice can obtain: " << stoneGameV(stoneValue2) << endl; // Output: 28

    vector<int> stoneValue3 = {4};
    cout << "Maximum score Alice can obtain: " << stoneGameV(stoneValue3) << endl; // Output: 0

    return 0;
}