/*
Rotting Oranges - [Leetcode - 994(Medium)]
=============================================
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
*/ 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid){
    queue<pair<int, int>> q;
    int freshOranges = 0;
    int n = grid.size();
    int m = grid[0].size();
    for(int i=0; i<n; i++){
        for(int j=0; j<m;j++){
            if(grid[i][j] == 1) freshOranges++;
            else if(grid[i][j] == 2) q.push({i,j}); // multi source bfs step
        }
    }
    // we have added all the src
    q.push({-1, -1});
    int mins = 0;
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
    while(not q.empty()){
        auto cell = q.front();
        q.pop();
        if(cell.first == -1 and cell.second == -1){
            if(not q.empty()){
                mins++;
                q.push({-1, -1});
            }
            else break;
        }
        else{
            int i = cell.first;
            int j = cell.second;
            for(int d=0; d<4; d++){
                int neighborsRow = i + dir[d][0];
                int neighborsCols = j + dir[d][1];
                if(neighborsRow < 0 or neighborsCols < 0 or neighborsRow >= n or neighborsCols >= m) continue;
                if(grid[neighborsRow][neighborsCols] == 2 or grid[neighborsRow][neighborsCols] == 0) continue;
                freshOranges--;
                grid[neighborsRow][neighborsCols] = 2;
                q.push({neighborsRow, neighborsCols});
            }
        }
    }
    return (freshOranges == 0) ? mins : -1;
}

int main(){

    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    int result = orangesRotting(grid);
    cout<<"Minimum minutes to rot all oranges: "<<result<<endl;
    
    return 0;
}