/*
Min Cost to Connect All Points - [Leetcode - 1584(Medium)]
===========================================================
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

Example 1:

Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 
We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.

Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(vector<int>& parent, int a){
    return parent[a] = ((parent[a] == a) ? a : find(parent, parent[a]));
}

void Union(vector<int>& parent, vector<int>& rank, int a, int b){
    a = find(parent, a);
    b = find(parent, b);
    if(a == b) return;
    if(rank[a] >= rank[b]){
        parent[b] = a;
        rank[a]++;
    }
    else{
        parent[a] = b;
        rank[b]++;
    }
}

class Edge{
    public:
    int src;
    int dest;
    int weight;
};

bool cmp(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

int minCostConnectPoints(vector<vector<int>>& points){
    int n = points.size();
    vector<Edge> edges;

    // Create edges between each pair of points and calculate their weights
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            edges.push_back({i, j, weight});
        }
    }
    vector<int> parent(n+1);
    vector<int> rank(n+1, 1);
    for(int i = 0; i < n; i++) parent[i] = i;
    int totalCost = 0;
    int connectedPoints = 0;

    // Sort edges by weight
    sort(edges.begin(), edges.end(), cmp);

    // Kruskal's algorithms
    for(Edge edge : edges){
        int srcPar = find(parent, edge.src);
        int destpar = find(parent, edge.dest);
        if(srcPar != destpar){
            Union(parent, rank, srcPar, destpar);
            totalCost += edge.weight;
            connectedPoints++;
            if(connectedPoints == n-1) break;
        }
    }
    return totalCost;
}

int main(){
    vector<vector<int>> points = {{3,12},{-2,5},{-4,1}};
    cout << minCostConnectPoints(points) << endl;
}