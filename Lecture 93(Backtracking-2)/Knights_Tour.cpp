/*
A knight's tour is a sequence of moves of a knight on a chessboard such that the knight visits every square exactly once. If the knight ends on a square that is one knight's move from the beginning square (so that it could tour the board again immediately, following the same path), the tour is closed (or re-entrant); otherwise, it is open.

The knight's tour problem is the mathematical problem of finding a knight's tour. Creating a program to find a knight's tour is a common problem given to computer science students.[3] Variations of the knight's tour problem involve chessboards of different sizes than the usual 8 × 8, as well as irregular (non-rectangular) boards.

The knight's tour problem is an instance of the more general Hamiltonian path problem in graph theory. The problem of finding a closed knight's tour is similarly an instance of the Hamiltonian cycle problem. Unlike the general Hamiltonian path problem, the knight's tour problem can be solved in linear time.
*/

#include <iostream>
#include <vector>
using namespace std;

bool isItSafe(vector<vector<int>>& grid, int i, int j, int n){
    return i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == -1;
}

vector<int> dx {-2, -1, -2, -1, +2, +1, +2, +1};
vector<int> dy {+1, +2, -1, -2, +1, +2, -1, -2}; 

void display(vector<vector<int>>& grid, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"*****"<<endl;
    cout<<flush; // Flush the output buffer
}

void helper(vector<vector<int>>& grid, int i, int j, int n, int count){
    if(count == n * n - 1){
        // last position
        grid[i][j] = count;
        display(grid, n);
        grid[i][j] = -1;
        return;
    }
    // from i, j we can go to 8 positions
    // for every position we can only go if it is safe
    for(int k = 0; k < 8; k++){
        if(isItSafe(grid, i + dx[k], j + dy[k], n)){
            grid[i][j] = count;
            helper(grid, i + dx[k], j + dy[k], n, count + 1);
            grid[i][j] = -1; // backtracking
        }
    }
}

void knightTours(int n, int i, int j){
    vector<vector<int>> grid(n, vector<int>(n, -1)); // -1 denotes positions is vacant
    helper(grid, i, j, n, 0);
}

int main(){
    int n = 5;
    knightTours(n, 0, 0);
    return 0;
}