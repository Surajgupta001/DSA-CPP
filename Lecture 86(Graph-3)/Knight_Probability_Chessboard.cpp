/*
Knight Probability Chessboard - [Leetcode - 688(Medium)]
===========================================================
On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).

A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.


Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly k moves or has moved off the chessboard.

Return the probability that the knight remains on the board after it has stopped moving.

Example 1:

Input: n = 3, k = 2, row = 0, column = 0
Output: 0.06250
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.

Example 2:

Input: n = 1, k = 0, row = 0, column = 0
Output: 1.00000
*/ 

#include <iostream>
#include <vector>
using namespace std;

// Possible moves of a knight
const vector<pair<int, int>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

double knightProbability(int n, int k, int row, int col){
    
    // Create a 2D array to store the probability of the knight being at each position
    vector<vector<double>> dp(n, vector<double>(n, 0.0));
    dp[row][col] = 1.0; // The knight starts at given position

    // BFS Traversal
    for(int i = 0; i < k; i++){
        vector<vector<double>> new_dp(n, vector<double>(n, 0.0));
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                for(const auto& move : moves){
                    int new_r = r + move.first;
                    int new_c = c + move.second;

                    // check if the new position is within the board
                    if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < n){
                        new_dp[new_r][new_c] += dp[r][c] / 8.0;
                    }
                }
            }
        }
        dp = new_dp;
    }

    // Calculate the total probability of the knight being on the board
    double total_prob = 0.0;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            total_prob += dp[r][c];
        }
    }
    return total_prob;
}

int main(){
    
    int n = 3, k = 2, row = 0, column = 0;
    
    cout<<"The probability that the knight remains on the board is: "<<knightProbability(n, k, row, column)<<endl;

    return 0;
}