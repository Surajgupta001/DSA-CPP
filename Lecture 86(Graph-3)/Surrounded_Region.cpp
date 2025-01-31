/*
Surrounded Region - [Leetcode - 130(Medium)]
=============================================
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.


Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:


In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]
*/ 

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& board, int i, int j){
    if(i < 0 or j < 0 or i >= board.size() or j >= board[0].size() or board[i][j] != 'O') return;
    board[i][j] = 'N'; // Mark as non-surrounded
    dfs(board, i-1, j);
    dfs(board, i+1, j);
    dfs(board, i, j-1);
    dfs(board, i, j+1);
}

void solve(vector<vector<char>>& board){
    if(board.empty() or board[0].empty()) return;

    int m = board.size(); // m -> rows
    int n = board[0].size(); // n -> col

    // Mark edge "O" cells as non-surronded
    for(int i = 0; i < m; i++){
        dfs(board, i, 0);
        dfs(board, i, n-1);
    }
    for(int j = 0; j < n; j++){
        dfs(board, 0, j);
        dfs(board, m-1, j);
    }
    // Mark all "O" cells as "X" and "N" cells as "O"
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'O'){
                board[i][j] = 'X';
            }
            else if(board[i][j] == 'N'){
                board[i][j] = 'O';
            }
        }
    }
}

int main() {
    // Example 1
    vector<vector<char>> board1 = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    cout << "Original Board 1:" << endl;
    for (const auto& row : board1) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    solve(board1);

    cout << "\nUpdated Board 1:" << endl;
    for (const auto& row : board1) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}