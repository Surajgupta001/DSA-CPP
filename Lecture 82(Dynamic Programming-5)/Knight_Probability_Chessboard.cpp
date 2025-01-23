/*
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

double helper(vector<vector<vector<double>>>& dp, int n, int i, int j, int k){
    // vector<double> dx = (1,2,1,2,-1,-2,-1,-2);
    // vector<double> dy = (2,1,-2,-1,2,1,-2,-1);

    if(i < 0 || i >= n || j < 0 || j >= n) return 0;
    if(k == 0) return 1;
    if(dp[i][j][k] != -0.9) return dp[i][j][k];
    
    double ans = 0;
    // for(int m=0;m<8;m++){
    //     ans += helper(dp, n, i + dx[m], j + dy[m], k - 1)*(0.125);
    // }
    ans += helper(dp, n, i+1, j+2, k-1)*(0.125);
    ans += helper(dp, n, i+2, j+1, k-1)*(0.125);
    ans += helper(dp, n, i+1, j-2, k-1)*(0.125);
    ans += helper(dp, n, i+2, j-1, k-1)*(0.125);
    ans += helper(dp, n, i-1, j+2, k-1)*(0.125);
    ans += helper(dp, n, i-2, j+1, k-1)*(0.125);
    ans += helper(dp, n, i-1, j-2, k-1)*(0.125);
    ans += helper(dp, n, i-2, j-1, k-1)*(0.125);

    return dp[i][j][k] = ans;
}

double knightProbability(int n, int k, int row, int column){
    vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k+1, -0.9)));
    return helper(dp, n, row, column, k);
}

int main(){

    int n;
    cout<<"Enter chessboard size: ";
    cin>>n;

    int k;
    cout<<"Enter number of moves: ";
    cin>>k;

    int row, column;
    cout<<"Enter starting position row and column: ";
    cin>>row>>column;

    cout<<knightProbability(n, k, row, column)<<endl;

    return 0;
}