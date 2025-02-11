/*
Connecting Cities With Minimum Cost - [Leetcode - 1135(Medium)]
===============================================================
There are n cities labeled from 1 to n. You are given the integer n and an array connections where connections[i] = [xi, yi, costi] indicates that the cost of connecting city xi and city yi (bidirectional connection) is costi.

Return the minimum cost to connect all the n cities such that there is at least one path between each pair of cities. If it is impossible to connect all the n cities, return -1,

The cost is the sum of the connections' costs used.

Example 1:

Input: n = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
Output: 6
Explanation: Choosing any 2 edges will connect all cities so we choose the minimum 2.

Example 2:

Input: n = 4, connections = [[1,2,3],[3,4,4]]
Output: -1
Explanation: There is no way to connect all cities even if all edges are used.
*/  

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int find(vector<int> &parent, int x) {
    return parent[x] = ((parent[x] == x) ? x : find(parent, parent[x]));
}

void Union(vector<int> &parent, vector<int> &rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    if(a == b) return;
    if(rank[a] >= rank[b]) {
        rank[a]++;
        parent[b] = a;
    } else {
        rank[b]++;
        parent[a] = b;
    }
}

class Edge {
public:
    int src;
    int dest;
    int wt;
};

bool cmp(Edge e1, Edge e2) {
    return e1.wt < e2.wt;
}

ll minimumCost(int n, vector<vector<int>>& connections){
    vector<int> parent(n+1);
    vector<int> rank(n+1, 1);
    vector<Edge> edges;
    for(int i = 0; i <= n; i++) {
        parent[i] = i;
    }
    
    // Create Edge objects and add them to the edges vector
    for(auto &connection : connections) {
        Edge e;
        e.src = connection[0];
        e.dest = connection[1];
        e.wt = connection[2];
        edges.push_back(e);
    }
    
    // Sort edges by weight
    sort(edges.begin(), edges.end(), cmp);
    
    int edgeCount = 0;
    ll ans = 0;
    for(auto &curr : edges) {
        int srcPar = find(parent, curr.src);
        int destPar = find(parent, curr.dest);
        if(srcPar != destPar){
            Union(parent, rank, srcPar, destPar);
            edgeCount++;
            ans += curr.wt;
        }
        if(edgeCount == n - 1) break;
    }
    if(edgeCount < n - 1) return -1;
    return ans;
}

int main(){
    int n = 4;
    vector<vector<int>> connections = {{1,2,3},{3,4,4}};
    cout<<"Minimum cost to connect all the n cities are: "<<minimumCost(n, connections)<<endl;
    return 0;
}