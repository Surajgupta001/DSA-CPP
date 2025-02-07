/*
Problem Statement

Given a grid of size n x m, where each cell is marked with a character 'L', 'R', 'U', or 'D', denoting the direction you can move from that cell. Starting from the top-left cell (0, 0), determine if it's possible to reach the bottom-right cell (n-1, m-1) using the given directions, without using any extra space (i.e., O(1) space complexity).

Note: The grid is a torus, meaning that if you move out of the grid in one direction, you will reappear on the opposite side of the grid. For example, if you move left from the leftmost column, you will reappear on the rightmost column.

Example

INPUT : 
[
  ['R', 'R', 'R'],
  ['U', 'L', 'R'],
  ['D', 'D', 'R']
]
OUTPUT : true
*/ 

#include <iostream>
#include <vector>
using namespace std;

// Here we can use dfs, bfs, recursion, or graph but it is not efficient
// ========= SLow and Fast Pointer (Efficient) ===========
bool canReachGrid(vector<vector<char>>& grid){
  /*
  * Time: O(n*m);
  * Space: O(1)
  */  
  int n = grid.size();
  int m = grid[0].size();
  int slow = 0;
  int fast = 0;

  while(fast < n * m){
    int next = fast;
    while(slow <= next){
      int i = slow / m;
      int j = slow % m;
      if(i == n-1 and j == m-1) return true; // Check if we've reached the bottom-right cell
      if(grid[i][j] == 'L') next = max(next, slow-1);
      else if(grid[i][j] == 'R') next = min(next, slow+1);
      else if(grid[i][j] == 'U') next = max(next, slow-m);
      else if(grid[i][j] == 'D') next = min(next, slow+m);
      slow++;
    }
    fast = next+1;
  }
  return false;
}

int main(){
  
  vector<vector<char>> grid = {
    {'R', 'R', 'R'},
    {'U', 'L', 'R'},
    {'D', 'D', 'R'}
  };

  cout<<boolalpha<<canReachGrid(grid)<<endl;

  return 0;
}