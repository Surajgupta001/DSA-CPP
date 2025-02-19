/*
Problem Statement There are N men and N women, both numbered 1,2,…,N.

For each i,j (1≤i,j≤N), the compatibility of Man i and Woman j is given as an integer a i,j . If a i,j =1, Man i and Woman j are compatible; if a i,j =0, they are not.

Taro is trying to make N pairs, each consisting of a man and a woman who are compatible. Here, each man and each woman must belong to exactly one pair.

Find the number of ways in which Taro can make N pairs, modulo 10^9 +7.

Constraints
All values in input are integers.
1 ≤ N ≤ 21
ai,j is 0 or 1.

Input
Input is given from Standard Input in the following format:

N
a 
1,1 … a 1,N
​:
a N,1 … a N,N
​
Output
Print the number of ways in which Taro can make N pairs, modulo 10^9 +7.

Sample Input 1
3
0 1 1
1 0 1
1 1 1
Sample Output 1
3
There are three ways to make pairs, as follows ((i,j) denotes a pair of Man i and Woman j):

(1,2),(2,1),(3,3)
(1,2),(2,3),(3,1)
(1,3),(2,1),(3,2)
*/

#include <iostream>
#include <vector>
using namespace std;
#include <cstring>
#define mod 1000000007

vector<vector<int>> dp;

int helper(int i, int mask, int n, vector<vector<int>>& c){
    if(mask == 0) return 1; // base case: all women have been paired
    if(dp[i][mask] != -1) return dp[i][mask];
    int ans = 0;
    for(int w = 1; w <= n; w++){
        if((mask & (1 << (w-1))) && c[i][w] == 1){
            ans = (ans % mod + helper(i+1, mask^(1<<(w-1)), n, c) % mod) % mod;
        }
    }
    return dp[i][mask] = ans;
}

int main(int argc, char const *argv[]){
    int n;
    cin>>n;
    vector<vector<int>> c(n+1, vector<int>(n+1, 0)); // compatibility matrix
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){ // corrected loop counter
            cin>>c[i][j];
        }
    }
    dp.resize(n+1, vector<int>(1 << n, -1)); // initialize dp vector
    cout<<helper(1, (1 << n) - 1, n, c);
    return 0;
}