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

// ========== Connected Component in a 2D Grid ==========

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int numIslands(vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    int connectedComponents = 0; // Store the number of connected components (islands)

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(grid[i][j] == '0'){
                // It is a water body, skip it
                continue;
            }

            // New Unvisited land found, increment the connected components count
            connectedComponents++;
            grid[i][j] = '0'; // Mark it as visited

            // BFS
            queue<pair<int, int>> qu; // Queue to store the nodes to be processed -> {row, col}
            qu.push({i, j}); // Store the source node

            while(!qu.empty()){
                auto curr = qu.front(); // Get the front node
                qu.pop(); // Remove the front node
                
                // Go to all Unvisited land neighbours of the current node
                int currRow = curr.first; // Current node row
                int currCol = curr.second; // Current node column

                // Check up neighbour
                if(currRow - 1 >= 0 && grid[currRow - 1][currCol] == '1'){
                    // Top neighbour
                    qu.push({currRow - 1, currCol}); // Push it to the queue
                    grid[currRow - 1][currCol] = '0'; // Mark it as visited
                }

                // Check down neighbour
                if(currRow + 1 < rows && grid[currRow + 1][currCol] == '1'){
                    // Bottom neighbour
                    qu.push({currRow + 1, currCol}); // Push it to the queue
                    grid[currRow + 1][currCol] = '0'; // Mark it as visited
                }

                // Check left neighbour
                if(currCol - 1 >= 0 && grid[currRow][currCol - 1] == '1'){
                    // Left neighbour
                    qu.push({currRow, currCol - 1}); // Push it to the queue
                    grid[currRow][currCol - 1] = '0'; // Mark it as visited
                }

                // Check right neighbour
                if(currCol + 1 < cols && grid[currRow][currCol + 1] == '1'){
                    // Right neighbour
                    qu.push({currRow, currCol + 1}); // Push it to the queue
                    grid[currRow][currCol + 1] = '0'; // Mark it as visited
                }
            }
        }
    }
    return connectedComponents;
}

int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << "Number of Islands: " << numIslands(grid) << endl;

    return 0;
}