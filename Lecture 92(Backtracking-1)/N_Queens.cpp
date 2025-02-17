/*
N-Queens  [Leetcode - 51(HARD)]
=====================================
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

xample 2:

Input: n = 1
Output: [["Q"]]
*/ 

#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> grid;

bool canPlaceQueen(int row, int col, int n){
    // column check
    for(int i=row-1; i>=0; i--){
        if(grid[i][col] == 'Q'){ // we are attacked
            return false;
        }
    }
    // left diag check
    for(int i=row-1, j=col-1; i>=0 and j>=0; i--, j--){
        if(grid[i][j] == 'Q'){ // we are attacked
            return false;
        }
    }
    // right diag check
    for(int i=row-1, j=col+1; i>=0 and j<n; i--, j++){
        if(grid[i][j] == 'Q'){ // we are attacked
            return false;
        }
    }
    return true; // no attacked
}

void helper(int row, int n){
    if(row == n){
        // We got one possible ans
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<grid[i][j];
            }
            cout<<endl;
        }
    }
    for(int col=0; col<n; col++){
        if(canPlaceQueen(row, col, n)){
            grid[row][col] = 'Q';
            helper(row + 1, n);
            grid[row][col] = '.';
        }
    }
}

vector<vector<string>>nQueen(int n){
    grid.resize(n, vector<char>(n,'.'));
    helper(0, n);
}

int main(){
    
    int n = 4;
    vector<vector<string>>ans = nQueen(n);
    return 0;
}