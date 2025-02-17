/*
Problem Statement - [Leetcode]
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
{1, 1, 0, 1},
{1, 1, 0, 0},
{0, 1, 1, 1}}

Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.

Constraints:
2 ≤ N ≤ 5
0 ≤ m[i][j] ≤ 1
*/ 

#include <iostream>
#include <vector>
using namespace std;

int ans;
bool canWeGo(int n, int i, int j, vector<vector<int>>& grid){
    return i >= 0 and j >= 0 and i < n and j < n and grid[i][j] == 0;
}

void helper(vector<vector<int>>& grid, int n, int i, int j){
    if(i == n - 1 and j == n - 1){
        ans += 1;
        return; // base case
    }
    grid[i][j] = 2; // 2 means visited

    // explore all possible directions
    // left
    if(canWeGo(n, i, j - 1, grid)){
        helper(grid, n, i, j - 1);
    }
    // up
    if(canWeGo(n, i - 1, j, grid)){
        helper(grid, n, i - 1, j);
    }
    // right
    if(canWeGo(n, i, j + 1, grid)){
        helper(grid, n, i, j + 1);
    }
    // down
    if(canWeGo(n, i + 1, j, grid)){
        helper(grid, n, i + 1, j);
    }

    grid[i][j] = 0;
}

int ratInAMAze(vector<vector<int>>& grid, int n){
    ans = 0;
    helper(grid, n, 0, 0);
    return ans;
}

int main(){
    int n = 7;
    vector<vector<int>> grid ={
        {0,0,1,0,0,1,0},
        {1,0,1,1,0,0,0},
        {0,0,0,0,1,0,1},
        {1,0,1,0,0,0,0},
        {1,0,1,1,0,1,0},
        {1,0,0,0,0,1,0},
        {1,1,1,1,0,0,0},
    };
    cout<<ratInAMAze(grid, n)<<endl;
    return 0;
}