/*
Minimum cost to cut a board into square - [GfG]
=================================================
A board of length M and width N is given. The task is to break this biard into M*N square such that cost of breaking is minimum. The cutting cost for each edge will be given will be given for the board in two array X & Y. In short, you need to choose sucg a sequence of cutting such that cost is minimised. Return the minimised cost.

Input
M = 6 , N = 4
X = [2,1,3,1,4]
Y = [4,1,2]
Output = 42
*/ 

#include <iostream>
#include <vector>
#define ll long long int
#include <algorithm>
using namespace std;

bool cmp(int x, int y){
    return x > y;
}

ll minCostToBreakGrid(int n, int m, vector<ll>& vertical, vector<ll>& horizontal){
    sort(vertical.begin(), vertical.end(), greater<ll>());
    sort(horizontal.begin(), horizontal.end(), greater<ll>());
    
    int horizontalCount = 1;
    int verticalCount = 1;
    int h = 0;
    int v = 0;
    ll ans = 0;

    while(h < horizontal.size() && v < vertical.size()){
        if(vertical[v] > horizontal[h]){
            ans += vertical[v] * verticalCount;
            horizontalCount++;
            v++;
        } else {
            ans += horizontal[h] * horizontalCount;
            verticalCount++;
            h++;
        }
    }
    while(h < horizontal.size()){
        ans += horizontal[h] * horizontalCount;
        h++;
    }
    while(v < vertical.size()){
        ans += vertical[v] * verticalCount;
        v++;
    }
    return ans;
}

int main(){

    int m,n;
    cin>>m>>n;

    vector<ll> horizontal, vertical;
    
    for(int i = 0; i < m - 1; i++){
        int x;
        cin >> x;
        vertical.push_back(x);
    }

    for(int i = 0; i < n - 1; i++){
        int x;
        cin >> x;
        horizontal.push_back(x);
    }

    cout<<minCostToBreakGrid(n, m, vertical, horizontal) << endl;

    return 0;

}