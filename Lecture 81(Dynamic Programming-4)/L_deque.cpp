#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

ll helper(vector<ll>& v, vector<vector<ll>>& dp, int i, int j){
    if(i == j) return v[i];
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = max(v[i] - helper(v, dp, i+1, j), v[j] - helper(v, dp, i, j-1));
}

ll maxProfit(vector<ll>& prices){
    int n = prices.size();
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    return helper(prices, dp, 0, n-1);
}

int main(){
    
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    vector<ll> v(n);
    cout<<"Enter all the element of vector: ";
    for(int i = 0; i < n; i++) cin>>v[i];
    
    cout<<maxProfit(v)<<endl;
    
    return 0;
}