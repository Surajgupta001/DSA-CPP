/*
Coloring A Border - [Leetcode - 1034(Medium)]
==============================================
You are given an m x n integer matrix grid, and three integers row, col, and color. Each value in the grid represents the color of the grid square at that location.

Two squares are called adjacent if they are next to each other in any of the 4 directions.

Two squares belong to the same connected component if they have the same color and they are adjacent.

The border of a connected component is all the squares in the connected component that are either adjacent to (at least) a square not in the component, or on the boundary of the grid (the first or last row or column).

You should color the border of the connected component that contains the square grid[row][col] with color.

Return the final grid.

 

Example 1:

Input: grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
Output: [[3,3],[3,2]]
Example 2:

Input: grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
Output: [[1,3,3],[2,3,3]]
Example 3:

Input: grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
Output: [[2,2,2],[2,1,2],[2,2,2]]
*/ 

#include <iostream>
#include <vector>
using namespace std;

    vector<pair<int, int> > Internal;
    void dfs(vector<vector<int>>& grid, int r, int c, int newColor, int originalColor) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != originalColor) return;
        grid[r][c] = -newColor;
        dfs(grid, r+1, c, newColor, originalColor), dfs(grid, r-1, c, newColor, originalColor), dfs(grid, r, c+1, newColor, originalColor), dfs(grid, r, c-1, newColor, originalColor);
        
        // below code will be executed while coming back from recursion
        if(not (r == 0 || c == 0 || r == grid.size() - 1 || c == grid[0].size() - 1 || grid[r+1][c] != -newColor || grid[r-1][c] != -newColor || grid[r][c-1] != -newColor || grid[r][c+1] != -newColor)) {
            Internal.push_back({r, c}); // curr cell is Internal
        }
        
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int originalColor = grid[row][col];
        if(originalColor == color) return grid;
        dfs(grid, row, col, color, originalColor);
        for(auto p : Internal) {
            int i = p.first;
            int j = p.second;
            grid[i][j] = originalColor;
        }
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] < 0) grid[i][j]*=-1;
            }
        }
        return grid;
    }

int main(){
    vector<vector<int>> grid = {{1,1},{1,2}};
    int row = 0, col = 0, color = 3;
    vector<vector<int>> res = colorBorder(grid, row, col, color);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[0].size(); j++){
            cout<<res[i][j]<<" ";
        }
    }
    return 0;
}