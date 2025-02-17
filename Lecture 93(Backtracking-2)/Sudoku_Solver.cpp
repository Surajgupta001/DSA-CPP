/*
Sudoku Solver - [Leetcode - 37(Hard)]
=======================================
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

 

Example 1:


Input: board = [
["5","3",".",".","7",".",".",".","."],
["6",".",".","1","9","5",".",".","."],
[".","9","8",".",".",".",".","6","."],
["8",".",".",".","6",".",".",".","3"],
["4",".",".","8",".","3",".",".","1"],
["7",".",".",".","2",".",".",".","6"],
[".","6",".",".",".",".","2","8","."],
[".",".",".","4","1","9",".",".","5"],
[".",".",".",".","8",".",".","7","9"]]

Output: [
["5","3","4","6","7","8","9","1","2"],
["6","7","2","1","9","5","3","4","8"],
["1","9","8","3","4","2","5","6","7"],
["8","5","9","7","6","1","4","2","3"],
["4","2","6","8","5","3","7","9","1"],
["7","1","3","9","2","4","8","5","6"],
["9","6","1","5","3","7","2","8","4"],
["2","8","7","4","1","9","6","3","5"],
["3","4","5","2","8","6","1","7","9"]]

Explanation: The input board is shown above and the only valid solution is shown below:

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.
*/ 

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<char>>& board, int row, int col, int num){
    // Row check
    for(int i = 0; i < 9; i++){
        if(board[row][i] != '.' && board[row][i] - '0' == num) return false;
    }
    // Column check
    for(int i = 0; i < 9; i++){
        if(board[i][col] != '.' && board[i][col] - '0' == num) return false;
    }
    // 3x3 sub-grid check
    int x = (row / 3) * 3;
    int y = (col / 3) * 3;
    for(int i = x; i < x + 3; i++){
        for(int j = y; j < y + 3; j++){
            if(board[i][j] != '.' && board[i][j] - '0' == num) return false;
        }
    }
    return true;
}

bool helper(vector<vector<char>>& board, int row, int col){
    if(row == 9) return true;
    if(col == 9) return helper(board, row + 1, 0);
    if(board[row][col] != '.') return helper(board, row, col + 1);
    for(int j = 1; j <= 9; j++){
        if(isSafe(board, row, col, j)){
            board[row][col] = j + '0';  // Convert int to char
            bool r = helper(board, row, col + 1);
            if(r) return true;
            board[row][col] = '.';
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board){
    helper(board, 0, 0);
}

int main(){
    
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    solveSudoku(board);
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}