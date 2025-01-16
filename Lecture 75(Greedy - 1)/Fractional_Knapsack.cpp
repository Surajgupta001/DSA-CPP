/*
Fractional Knapsack Problem - GFG
===================================
Given the weights and profits of N items, in the form of {profit, weight} put these items in a knapsack of capacity W to get the maximum total profit in the knapsack. In Fractional Knapsack, we can break items for maximizing the total value of the knapsack.

Input: arr[] = {{60, 10}, {100, 20}, {120, 30}}, W = 50
Output: 240 
Explanation: By taking items of weight 10 and 20 kg and 2/3 fraction of 30 kg. 
Hence total price will be 60+100+(2/3)(120) = 240

Input:  arr[] = {{500, 30}}, W = 10
Output: 166.667
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool customComparator(pair<int,int>& p1, pair<int,int>& p2){
    // pair<int,int>fisrt -> value, second->weight
    double r1 = (p1.first*1.0) / (p1.second*1.0);
    double r2 = (p2.first*1.0) / (p2.second*1.0);
    return r1 > r2;
}

double fractionalKnapsack(vector<int>& profit, vector<int>& weight, int n, int w){
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++) v.push_back({profit[i],weight[i]});
    sort(v.begin(),v.end(),customComparator);
    double ans = 0;
    for(int i=0;i<n;i++){
        if(v[i].second <= w){
            ans += v[i].first;
            w -= v[i].second;
        }
        else{
            ans += ((v[i].first*1.0) / (v[i].second*1.0))*w;
            w = 0;
            break;
        }
    }
    return ans;
}

int main(){
    
    int n = 3;
    int w = 50;
    
    vector<int> profit = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    
    cout << fractionalKnapsack(profit, weight, n, w) << endl;
    
    return 0;
}