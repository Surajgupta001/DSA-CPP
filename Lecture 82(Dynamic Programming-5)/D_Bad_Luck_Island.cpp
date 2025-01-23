/*
The Bad Luck Island is inhabited by three kinds of species: r rocks, s scissors and p papers. At some moments of time two random individuals meet (all pairs of individuals can meet equiprobably), and if they belong to different species, then one individual kills the other one: a rock kills scissors, scissors kill paper, and paper kills a rock. Your task is to determine for each species what is the probability that this species will be the only one to inhabit this island after a long enough period of time.

Input
The single line contains three integers r, s and p (1 ≤ r, s, p ≤ 100) — the original number of individuals in the species of rock, scissors and paper, respectively.

Output
Print three space-separated real numbers: the probabilities, at which the rocks, the scissors and the paper will be the only surviving species, respectively. The answer will be considered correct if the relative or absolute error of each number doesn't exceed 10 - 9.

Examples
InputCopy
2 2 2
OutputCopy
0.333333333333 0.333333333333 0.333333333333

InputCopy
2 1 2
OutputCopy
0.150000000000 0.300000000000 0.550000000000

InputCopy
1 1 3
OutputCopy
0.057142857143 0.657142857143 0.285714285714
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
// #define ld long double
using namespace std;

long double rock(vector<vector<vector<long double>>>&dp, int r, int s, int p){
    if(r == 0 || s == 0 ) return 0.0;
    if(p == 0) return 1.0;
    if(dp[r][s][p] > -0.9) return dp[r][s][p];

    long double total = r*s + s*p + p*r;
    long double ans = 0.0;
    ans += rock(dp,r-1,s,p) * ((r*p)/total);
    ans += rock(dp,r,s-1,p) * ((r*s)/total);
    ans += rock(dp,r,s,p-1) * ((s*p)/total);
    return dp[r][s][p] = ans;

}

long double scissors(vector<vector<vector<long double>>>&dp, int r, int s, int p){
    if(s == 0 or p == 0) return 0.0;
    if(r == 0) return 1.0;
    if(dp[r][s][p] > -0.9) return dp[r][s][p];

    long double total = r*s + s*p + p*r;
    long double ans = 0.0;
    ans += scissors(dp,r-1,s,p) * ((r*p)/total);
    ans += scissors(dp,r,s-1,p) * ((r*s)/total);
    ans += scissors(dp,r,s,p-1) * ((s*p)/total);
    return dp[r][s][p] = ans;
}

long double papers(vector<vector<vector<long double>>>& dp, int r, int s, int p){
    if(p == 0 or r == 0) return 0.0;
    if(s == 0) return 1.0;
    if(dp[r][s][p] > -0.9) return dp[r][s][p];

    long double total = r*s + s*p + p*r;
    long double ans = 0.0;
    ans += papers(dp,r-1,s,p) * ((r*p)/total);
    ans += papers(dp,r,s-1,p) * ((r*s)/total);
    ans += papers(dp,r,s,p-1) * ((s*p)/total);
    return dp[r][s][p] = ans;
}

int main(){

    int r, s, p;
    cout<<"Enter the number of rocks, scissors, and papers: ";
    cin>>r>>s>>p;

    int max = std::max({r, s, p}) + 1;
    vector<vector<vector<long double>>> dp_r(max, vector<vector<long double>>(max, vector<long double>(max, -1.0)));
    vector<vector<vector<long double>>> dp_s(max, vector<vector<long double>>(max, vector<long double>(max, -1.0)));
    vector<vector<vector<long double>>> dp_p(max, vector<vector<long double>>(max, vector<long double>(max, -1.0)));

    long double rock_prob = rock(dp_r, r, s, p);
    long double scissors_prob = scissors(dp_s, r, s, p);
    long double papers_prob = papers(dp_p, r, s, p);

    cout<<fixed<<setprecision(15)<<rock_prob<<" "<<scissors_prob<<" "<<papers_prob<<endl;

    return 0;
}