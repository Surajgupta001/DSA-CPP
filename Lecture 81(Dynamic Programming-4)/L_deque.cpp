/*
Taro and Jiro will play the following game against each other.

Initially, they are given a sequence 
a=(a1, a2,…,aN). Until a becomes empty, the two players perform the following operation alternately, starting from Taro:

Remove the element at the beginning or the end of a. The player earns x points, where x is the removed element.
Let X and Y be Taro's and Jiro's total score at the end of the game, respectively. Taro tries to maximize X−Y, while Jiro tries to minimize X−Y.

Assuming that the two players play optimally, find the resulting value of X−Y.

Sample Input
4
10 80 90 30

Sample Output
10
*/ 

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

/*
=============== Tabulation ================
ll maxProfit(vector<ll>& prices){
    vector<vector<ll>> dp(prices.size(),vector<ll>(prices.size(),0));
    
    // Base Case: WHen there,s only one element
    for(int i=0;i<prices.size();i++){
        dp[i][i] = prices[i];
    }
    // Filling the dp table in a bottom-up manner
    for(int len=2;len<=prices.size();len++){
        for(int i=0;i<=prices.size()-len;i++){
            int j = i + len - 1;
            dp[i][j] = max(prices[i] - dp[i+1][j], prices[j] - dp[i][j-1]);
        }
    }
    return dp[0][prices.size()-1];
}
*/ 

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