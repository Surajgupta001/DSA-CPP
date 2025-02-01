/*
Shortest Bridge - [Leetcode - 934(Medium)]
===========================================
You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.

 

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 1

Example 2:

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2

Example 3:

Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
*/ 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int,int>>& q, vector<vector<int>>& directions){
    if(i < 0 or i >= grid.size() or j < 0 or j >= grid.size() or grid[i][j] != 1) return;
    grid[i][j] = -1; // visited cell in the grid
    q.push({i,j});
    for(auto dir : directions){
        dfs(grid, i + dir[0], j + dir[1], q, directions);
    }
}

int shortestBridge(vector<vector<int>>& grid){
    queue<pair<int,int>>q; // queue to store the cells to be visited during the BFS
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    bool found = false;

    // Find the first island
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid.size(); j++){
            if(grid[i][j] == 1){
                dfs(grid, i, j, q, directions);
                found = true;
                break;
            }
        }
        if(found) break;
    }

    int dist = 0;
    while(!q.empty()){
        for(int i=0; i<q.size(); i++){
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();

            for(auto &dir : directions){
                int neighbourRow = currRow + dir[0];
                int neighbourCol = currCol + dir[1];

                if(neighbourRow >= 0 and neighbourRow < grid.size() and neighbourCol >= 0 and neighbourCol < grid.size()){
                    if(grid[neighbourRow][neighbourCol] == 1) return dist + 1;
                    else if(grid[neighbourRow][neighbourCol] == 0){
                        grid[neighbourRow][neighbourCol] = -1;
                        q.push({neighbourRow, neighbourCol});
                    }
                }
            }
        }
        dist++;
    }
    return -1; // Return -1 if no bridge is found
}

int main(){

    int n;
    cout << "Enter the size of the grid: ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    cout << "Enter the grid values (0 for water, 1 for land):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "The shortest bridge between the two islands is: " << shortestBridge(grid) << endl;
    return 0;
}