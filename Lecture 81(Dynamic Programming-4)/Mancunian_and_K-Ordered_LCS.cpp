/*
Any programmer worth his salt would be familiar with the famous Longest Common Subsequence problem. Mancunian was asked to solve the same by an incompetent programmer. As expected, he solved it in a flash. To complicate matters, a twist was introduced in the problem.

In addition to the two sequences, an additional parameter k was introduced. A k-ordered LCS is defined to be the LCS of two sequences if you are allowed to change at most k elements in the first sequence to any value you wish to. Can you help Mancunian solve this version of the classical problem?

Input:
The first line contains three integers N, M and k, denoting the lengths of the first and second sequences and the value of the provided parameter respectively.
The second line contains N integers denoting the elements of the first sequence.
The third line contains M integers denoting the elements of the second sequence.

Output:
Print the answer in a new line.

Constraints:
1 <= N, M <= 2000
1 <= k <= 5
1 <= element in any sequence <= 109

Sample Input
5 5 1
1 2 3 4 5
5 3 1 4 2
Sample Output
3
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int
using namespace std;

// Replace the fixed-size array with a nested vector
vector<vector<vector<ll>>> dp;

ll kOrderedLCS(vector<int>& a, vector<int>& b, int n, int m, int i, int j, int k) {
    if (i == n || j == m) return 0;
    if (dp[i][j][k] != -1) return dp[i][j][k];

    ll ans = 0;
    if (a[i] == b[j]) ans = 1 + kOrderedLCS(a, b, n, m, i + 1, j + 1, k);
    else {
        if (k > 0) ans = 1 + kOrderedLCS(a, b, n, m, i + 1, j + 1, k - 1);
        ans = max(ans, kOrderedLCS(a, b, n, m, i + 1, j, k));
        ans = max(ans, kOrderedLCS(a, b, n, m, i, j + 1, k));
    }
    dp[i][j][k] = ans;
    return ans;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> v1(n), v2(m);
    for (int i = 0; i < n; i++) cin >> v1[i];
    for (int i = 0; i < m; i++) cin >> v2[i];

    // Initialize the dp vector with -1
    dp.resize(n, vector<vector<ll>>(m, vector<ll>(k + 1, -1)));

    // Compute and print the k-ordered LCS
    cout << kOrderedLCS(v1, v2, n, m, 0, 0, k) << endl;

    return 0;
}