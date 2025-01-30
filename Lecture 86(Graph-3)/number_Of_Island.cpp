/*
Number of Island - [Leetcode - 200(Medium)]
===============================================
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/ 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int numIsLand(vector<vector<char>>& grid){
    
    int row = grid.size();
    int col = grid[0].size();
    int cc = 0;

    for(int r=0; r<row; r++){
        for(int c=0; c<col; c++){
            if(grid[r][c] == '0') continue; // It is a water body 
            if(grid[r][c] == '!1') continue; // It is a visited land
            // new unvisited land piece found, i.e. new connected component
            cc++;
            grid[r][c] = '0'; // mark it visited
            
            queue<pair<int, int>> q;
            q.push({r, c}); // store thr src node
            while(!q.empty()){
                auto curr = q.front(); // get one node from queue
                q.pop();
                
                // go to all unvisited neighbours of the curr node
                int currRow = curr.first;
                int currCol = curr.second;
                // check all 4 neighbours
                // check up
                if(currRow + 1 >= 0 and grid[currRow - 1][currCol] == '1'){
                    q.push({currRow-1, currCol});
                    grid[currRow - 1][currCol] = '0'; // mark it visited
                }
                // check down
                if(currRow + 1 < row and grid[currRow + 1][currCol] == '1'){
                    q.push({currRow+1, currCol});
                    grid[currRow + 1][currCol] = '0'; // mark it visited
                }
                // check left
                if(currCol - 1 >= 0 and grid[currRow][currCol - 1] == '1'){
                    q.push({currRow, currCol - 1});
                    grid[currRow][currCol - 1] = '0'; // mark it visited
                }
                // check right
                if(currCol + 1 < col and grid[currRow][currCol + 1] == '1'){
                    q.push({currRow, currCol + 1});
                    grid[currRow][currCol + 1] = '0'; // mark it visited
                }
            }
        }
    }
    return cc;
}

int main(){
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    int numIslands = numIsLand(grid);
    cout << "Number of Islands: " << numIslands << endl;

    return 0;
}