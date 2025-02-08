/*
Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.

A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.

Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.

Return true if any cycle of the same value exists in grid, otherwise, return false.

Example 1:

Input: grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
Output: true
Explanation: There are two valid cycles shown in different colors in the image below:

Example 2:

Input: grid = [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]
Output: true
Explanation: There is only one valid cycle highlighted in the image below:

Example 3:

Input: grid = [["a","b","b"],["b","z","b"],["b","b","a"]]
Output: false
*/ 
#include <vector>
#include <iostream>
using namespace std;

// Helper function to perform DFS
bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c, int prev_r, int prev_c, char target, int directions[4][2]) {
    // Check if the current cell is out of bounds or doesn't match the target value.
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != target) {
        return false;
    }

    // If the cell is already visited, a cycle is detected.
    if (visited[r][c]) {
        return true;
    }

    // Mark the current cell as visited.
    visited[r][c] = true;

    // Explore all four directions (up, down, left, right).
    for (int i = 0; i < 4; ++i) {
        auto& dir = directions[i];
        int nr = r + dir[0]; // New row.
        int nc = c + dir[1]; // New column.

        // Avoid backtracking to the previous cell.
        if (nr != prev_r || nc != prev_c) {
            // Recursively call DFS for the new cell.
            if (dfs(grid, visited, nr, nc, r, c, target, directions)) {
                return true; // If a cycle is found, return true.
            }
        }
    }
    return false; // If no cycle is found, return false.
}

// Function to check if a cycle exists in the grid
bool containsCycle(vector<vector<char>>& grid) {
    if (grid.empty()) return false; // If the grid is empty, no cycle exists.

    int rows = grid.size(); // Number of rows in the grid.
    int cols = grid[0].size(); // Number of columns in the grid.

    // Create a 2D array to track visited cells.
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // Directions for moving up, down, left, right.
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // Iterate through every cell in the grid.
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // If the cell is not visited, start DFS from it.
            if (!visited[i][j]) {
                if (dfs(grid, visited, i, j, -1, -1, grid[i][j], directions)) {
                    return true; // If a cycle is found, return true.
                }
            }
        }
    }
    return false; // If no cycle is found, return false.
}

// Example usage
int main() {
    vector<vector<char>> grid1 = {
        {'a', 'a', 'a', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'a', 'a', 'a'}
    };
    cout << boolalpha << containsCycle(grid1) << endl; // Output: true

    vector<vector<char>> grid2 = {
        {'c', 'c', 'c', 'a'},
        {'c', 'd', 'c', 'c'},
        {'c', 'c', 'e', 'c'},
        {'f', 'c', 'c', 'c'}
    };
    cout << boolalpha << containsCycle(grid2) << endl; // Output: true

    vector<vector<char>> grid3 = {
        {'a', 'b', 'b'},
        {'b', 'z', 'b'},
        {'b', 'b', 'a'}
    };
    cout << boolalpha << containsCycle(grid3) << endl; // Output: false

    return 0;
}