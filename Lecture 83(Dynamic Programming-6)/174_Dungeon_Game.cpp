/*
Dungeon Game - [Leetcode - 174(HARD)]
-------------------------------------
The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).

To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Return the knight's minimum initial health so that he can rescue the princess.

Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

Example 1:

Input: dungeon = [[-2,-3,3][-5,-10,1],[10,30,-5]]
Output: 7
Explanation: The initial health of the knight must be at least 7 if he follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.

Example 2:

Input: dungeon = [[0]]
Output: 1
 

Constraints:

m == dungeon.length
n == dungeon[i].length
1 <= m, n <= 200
-1000 <= dungeon[i][j] <= 1000
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
=============== Brute Force - Binary Search On Answer===============
bool canSurvive(int m, int n, int i, int j, int mid, vector<vector<int>>& dungeon){
    if(i >= m || j >= n) return false;

    mid += dungeon[i][j];
    if(mid <= 0) return false;
    if(i == m - 1 && j == n - 1) return true;

    bool right = canSurvive(m, n, i, j + 1, mid, dungeon);
    bool down = canSurvive(m, n, i + 1, j, mid, dungeon);
    
    return right or down;
}

int calculateMinimumHP(int m, int n, vector<vector<int>>& dungeon) {
    m = dungeon.size();
    n = dungeon[0].size();

    int left = 1;
    int right = 4 * 1e7;

    int minimumHealth = 4 * 1e7;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if (canSurvive(m, n, 0, 0, mid, dungeon)) {
            minimumHealth = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}
*/ 

/*
============ Optimisation with Recursion =================
int helper(int i, int j, int m, int n, vector<vector<int>>& dungeon) {
    if (i >= m || j >= n) return 1e9;

    if (i == m - 1 && j == n - 1) {
        if (dungeon[i][j] > 0) return 1;
        return abs(dungeon[i][j]) + 1;
    }

    int right = helper(i, j + 1, m, n, dungeon);
    int down = helper(i + 1, j, m, n, dungeon);

    int result = min(right, down) - dungeon[i][j];

    return (result > 0) ? result : 1;
}

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size();
    int n = dungeon[0].size();

    return helper(0, 0, m, n, dungeon);
}
*/ 

// ============================= Optimisation with Memoization(DP) =======================
int solve(int m, int n, int i, int j, vector<vector<int>>& dungeon, vector<vector<int>> dp) {
    if (i >= m || j >= n) return 1e9;

    if (dp[i][j] != -1) return dp[i][j];

    if (i == m - 1 && j == n - 1){
        return dp[i][j] = (dungeon[i][j] > 0 ? 1 : abs(dungeon[i][j]) + 1);
    }

    int down = solve(m, n, i + 1, j, dungeon, dp);
    int right = solve(m, n, i, j + 1, dungeon, dp);

    int res = min(down, right) - dungeon[i][j];
    return dp[i][j] = (res > 0 ? res : 1);
}

int calculateMinimumHP(int m, int n, vector<vector<int>>& dungeon, vector<vector<int>> dp) {
    m = dungeon.size();
    n = dungeon[0].size();
    
    dp = vector<vector<int>>(m+1, vector<int>(n+1, -1)); // Initialize the vector with -1
    
    return solve(m, n, 0, 0, dungeon, dp);
}


// ============================ Bottom Up -> Approach(DP) ============================
int calculateMinimumHP(int m, int n,vector<vector<int>> &dungeon){
    m = dungeon.size();
    n = dungeon[0].size();
    // NOTE : We will write bottom up by traversing from bottom right to top left because
    //  when we find t[i][j] we must be already aware of the health for down (t[i+1][j) and right (t[i][j+1])

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    // dp[i][j] = min health needed to reach (m-1, n-1) from (i,j)

    // Fill the rest of the DP table
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (i == m - 1 && j == n - 1) {
                dp[i][j] = (dungeon[m - 1][n - 1] > 0 ? 1 : abs(dungeon[m - 1][n - 1]) + 1);
            }
            else {
                int down = (i + 1 >= m) ? 1e9 : dp[i + 1][j];  // Health needed if moving down
                int right = (j + 1 >= n) ? 1e9 : dp[i][j + 1]; // Health needed if moving right
                int res = min(down, right) - dungeon[i][j];   // Calculate the required health

                // If the result is <= 0, we need at least 1 health
                dp[i][j] = (res > 0 ? res : 1);
            }
        }
    }

    // The result is the minimum health required to start at the top-left corner
    return dp[0][0];
}

int main() {
    vector<vector<int>> dungeon = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };

    int m = dungeon.size();
    int n = dungeon[0].size();

    cout << "Minimum initial health required: " << calculateMinimumHP(m, n, dungeon) << endl;

    return 0;
}