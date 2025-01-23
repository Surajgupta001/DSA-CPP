/*
I - Coins - [AtCoder]

Problem Statement
Let N be a positive odd number.

There are N coins, numbered 1,2,…,N. For each i (1≤i≤N), when Coin i is tossed, it comes up heads with probability piand tails with probability 1−pi.

Taro has tossed all the N coins. Find the probability of having more heads than tails.

Sample Input 1
3
0.30 0.60 0.80

Sample Output 1
0.612

The probability of each case where we have more heads than tails is as follows:

The probability of having (Coin1,Coin2,Coin3)=(Head,Head,Head) is 0.3×0.6×0.8=0.144;
The probability of having (Coin1,Coin2,Coin3)=(Tail,Head,Head) is 0.7×0.6×0.8=0.336;
The probability of having (Coin1,Coin2,Coin3)=(Head,Tail,Head) is 0.3×0.4×0.8=0.096;
The probability of having (Coin1,Coin2,Coin3)=(Head,Head,Tail) is 0.3×0.6×0.2=0.036.
Thus, the probability of having more heads than tails is 0.144+0.336+0.096+0.036=0.612.
*/ 

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

double helper(vector<double>& p, vector<vector<double>>& dp, int i, int x){
    if(x == 0) return 1;
    if(i == -1) return 0;
    if(dp[i][x] > -0.9) return dp[i][x];
    return dp[i][x] = helper(p, dp, i-1, x-1)*p[i] + helper(p, dp, i-1, x)*(1-p[i]);
}

int main(){
    
    int n;
    cout<<"Enter the number of probability: ";
    cin>>n;

    vector<double>p(n);
    cout<<"Enter all the probability: ";
    for(int i=0; i<n; i++) cin>>p[i];
    
    vector<vector<double>> dp(n, vector<double>(n+1, -1.0));
    
    cout<<"Probability of having more heads than tails is: "<<fixed<<setprecision(9)<<helper(p, dp, n-1, ((n+1)/2));
    
    return 0;
}