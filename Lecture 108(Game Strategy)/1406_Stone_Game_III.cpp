/*
Stone Game III - [Leetcode - 1406(Hard)]
----------------------------------------------
Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2, or 3 stones from the first remaining stones in the row.

The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially.

The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.

Assume Alice and Bob play optimally.

Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they will end the game with the same score.

Example 1:

Input: stoneValue = [1,2,3,7]
Output: "Bob"
Explanation: Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and Bob wins.

Example 2:

Input: stoneValue = [1,2,3,-9]
Output: "Alice"
Explanation: Alice must choose all the three piles at the first move to win and leave Bob with negative score.
If Alice chooses one pile her score will be 1 and the next move Bob's score becomes 5. In the next move, Alice will take the pile with value = -9 and lose.
If Alice chooses two piles her score will be 3 and the next move Bob's score becomes 3. In the next move, Alice will take the pile with value = -9 and also lose.
Remember that both play optimally so here Alice will choose the scenario that makes her win.

Example 3:

Input: stoneValue = [1,2,3,6]
Output: "Tie"
Explanation: Alice cannot win this game. She can end the game in a draw if she decided to choose all the first three piles, otherwise she will lose. 

Constraints:

1 <= stoneValue.length <= 5 * 10^4
-1000 <= stoneValue[i] <= 1000
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int helper(vector<int>& stoneValue, int i, vector<int>& dp) {
    int n = stoneValue.size();
    
    if(i >= n) return 0;

    if(dp[i] != -1) return dp[i];

    int result = stoneValue[i] - helper(stoneValue, i + 1, dp);
    
    if(i + 1 < n){
        result = max(result, stoneValue[i] + stoneValue[i + 1] - helper(stoneValue, i + 2, dp));
    }

    if(i + 2 < n){
        result = max(result, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - helper(stoneValue, i + 3, dp));
    }
    
    return dp[i] = result;
}

string stoneGameIII(vector<int>& stoneValue) {
    int n = stoneValue.size();

    vector<int> dp(n, -1);
    
    int diff = helper(stoneValue, 0, dp);
    
    if (diff > 0) {
        return "Alice";
    } else if (diff < 0) {
        return "Bob";
    } else {
        return "Tie";
    }
}

// Bottom up
string stoneGameIII(vector<int>& stoneValue) {
    int n = stoneValue.size();
    vector<int> dp(n + 1);

    for(int i = n - 1; i >= 0; --i) {
        dp[i] = stoneValue[i] - dp[i + 1];

        if (i + 1 < n) {
            dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] - dp[i + 2]);
        }

        if (i + 2 < n) {
            dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3]);
        }
    }

    if (dp[0] > 0) {
        return "Alice";
    } else if (dp[0] < 0) {
        return "Bob";
    } else {
        return "Tie";
    }
}

int main() {
    vector<int> stoneValue1 = {1, 2, 3, 7};
    cout << stoneGameIII(stoneValue1) << endl; // Output: "Bob"

    vector<int> stoneValue2 = {1, 2, 3, -9};
    cout << stoneGameIII(stoneValue2) << endl; // Output: "Alice"

    vector<int> stoneValue3 = {1, 2, 3, 6};
    cout << stoneGameIII(stoneValue3) << endl; // Output: "Tie"

    return 0;
}