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

bool can_reach_end(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    char dir_map[] = {'L', 'R', 'U', 'D'};

    bool dfs(int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 'V') {
            return false;
        }
        if (i == n - 1 && j == m - 1) {
            return true;
        }
        char temp = grid[i][j];
        grid[i][j] = 'V';
        for (int k = 0; k < 4; k++) {
            if (dir_map[k] == temp) {
                if (dfs(i + directions[k].first, j + directions[k].second)) {
                    return true;
                }
            }
        }
        grid[i][j] = temp;
        return false;
    }

    return dfs(0, 0);
}

int main() {
    vector<vector<char>> grid = {
        {'R', 'R', 'R'},
        {'U', 'L', 'R'},
        {'D', 'D', 'R'}
    };
    cout << (can_reach_end(grid) ? "True" : "False") << endl;
    return 0;
}


#include <iostream>
#include <vector>

using namespace std;

bool can_reach_end(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int slow_i = 0, slow_j = 0;
    int fast_i = 0, fast_j = 0;
    while (true) {
        // Move slow pointer
        if (grid[slow_i][slow_j] == 'L') {
            slow_j--;
        } else if (grid[slow_i][slow_j] == 'R') {
            slow_j++;
        } else if (grid[slow_i][slow_j] == 'U') {
            slow_i--;
        } else if (grid[slow_i][slow_j] == 'D') {
            slow_i++;
        }
        if (slow_i < 0 || slow_i >= n || slow_j < 0 || slow_j >= m) {
            return false;
        }
        if (slow_i == n - 1 && slow_j == m - 1) {
            return true;
        }
        // Move fast pointer
        int next_i = slow_i, next_j = slow_j;
        if (grid[next_i][next_j] == 'L') {
            next_j--;
        } else if (grid[next_i][next_j] == 'R') {
            next_j++;
        } else if (grid[next_i][next_j] == 'U') {
            next_i--;
        } else if (grid[next_i][next_j] == 'D') {
            next_i++;
        }
        if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= m) {
            return false;
        }
        if (next_i == n - 1 && next_j == m - 1) {
            return true;
        }
        if (grid[next_i][next_j] == 'L') {
            fast_j = next_j - 1;
        } else if (grid[next_i][next_j] == 'R') {
            fast_j = next_j + 1;
        } else if (grid[next_i][next_j] == 'U') {
            fast_i = next_i - 1;
        } else if (grid[next_i][next_j] == 'D') {
            fast_i = next_i + 1;
        }
        if (fast_i == slow_i && fast_j == slow_j) {
            return false;
        }
    }
}

int main() {
    vector<vector<char>> grid = {
        {'R', 'R', 'R'},
        {'U', 'L', 'R'},
        {'D', 'D', 'R'}
    };
    cout << (can_reach_end(grid) ? "True" : "False") << endl;
    return 0;
}