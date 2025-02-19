/*
Problem Statement
There are N rabbits, numbered 1,2,…,N.

For each i,j (1≤i,j≤N), the compatibility of Rabbit i and j is described by an integer a i,j . Here, a i,i​ =0 for each i (1≤i≤N), and a i,j =a j,i  for each i and j (1≤i,j≤N).

Taro is dividing the N rabbits into some number of groups. Here, each rabbit must belong to exactly one group. After grouping, for each i and j (1≤i<j≤N), Taro earns a i,j​  points if Rabbit i and j belong to the same group.

Find Taro's maximum possible total score.

Constraints

All values in input are integers.

1 ≤ N ≤ 16

∣a i,j∣ ≤ 10^9 

ai,j=0

ai,j​ = a j,i
​
Sample Input 1
3
0 10 20
10 0 -100
20 -100 0

Sample Output 1
20

The rabbits should be divided as 
{1,3},{2}.

*/ 

#include <iostream>
#include <vector>
#include <climits>
#define ll long long int
using namespace std;

vector<ll> dp((1 << 16), INT_MIN);
vector<ll> sums(1 << 16, 0);

ll cals(vector<vector<ll>>& compat, int mask, int n) {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((mask & (1 << i)) != 0 && ((mask & (1 << j)) != 0)) {
                ans += compat[i][j];
            }
        }
    }
    return ans;
}

void preCompute(vector<vector<ll>>& compat, int n) {
    for (int mask = 1; mask < (1 << n); mask++) {
        sums[mask] = cals(compat, mask, n);
    }
}

ll helper(vector<vector<ll>>& compat, int mask) {
    if (mask == 0) return 0;
    if (dp[mask] != INT_MIN) return dp[mask];
    ll ans = INT_MIN;
    for (int g = mask; g != 0; g = ((g - 1) & mask)) {
        ans = max(ans, sums[g] + helper(compat, mask ^ g));
    }
    return dp[mask] = ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<ll>> compat(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> compat[i][j];
        }
    }
    preCompute(compat, n);
    cout << helper(compat, (1 << n) - 1) << endl;
    return 0;
}