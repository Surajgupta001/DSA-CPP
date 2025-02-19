#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int>> grid = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}
};

vector<vector<int>> dp(4, vector<int>(1<<4, -1));  // Initialize with -1

int TSP(int curr, int mask, int n){
    if(mask == (1 << n) - 1){
        return grid[curr][0];
    }

    if(dp[curr][mask] != -1) return dp[curr][mask];
    
    int ans = INT_MAX;
    for(int neigh = 0; neigh < n; neigh++){
        if((mask & (1 << neigh)) == 0){
            int cost = grid[curr][neigh] + TSP(neigh, mask | (1 << neigh), n);
            if(cost < ans) ans = cost;
        }
    }
    
    return dp[curr][mask] = ans;
}

int main(){

    cout<<TSP(0, 1, 4)<<endl;
    
    return 0;
}