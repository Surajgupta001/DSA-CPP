/*
Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree - [Leetcode - 1489(Hard)]
---------------------------------------------------------------------------------------------
Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.

Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.

Note that you can return the indices of the edges in any order.

Example 1:

Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
Output: [[0,1],[2,3,4,5]]
Explanation: The figure above describes the graph.
The following figure shows all the possible MSTs:

Notice that the two edges 0 and 1 appear in all MSTs, therefore they are critical edges, so we return them in the first list of the output.
The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are considered pseudo-critical edges. We add them to the second list of the output.

Example 2:

Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
Output: [[],[0,1,2,3]]
Explanation: We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.

Constraints:

2 <= n <= 100
1 <= edges.length <= min(200, n * (n - 1) / 2)
edges[i].length == 3
0 <= ai < bi < n
1 <= weighti <= 1000
All pairs (ai, bi) are distinct.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent) return;
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        }
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
};

int Kruskal(vector<vector<int>> &edges, int skip_edge, int add_edge, int n) {
    int sum = 0;
    DSU dsu(n);

    if (add_edge != -1) {
        dsu.Union(edges[add_edge][0], edges[add_edge][1]);
        sum += edges[add_edge][2];
    }

    for (int i = 0; i < edges.size(); i++) {

        if (i == skip_edge) continue;

        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        int parent_u = dsu.find(u);
        int parent_v = dsu.find(v);

        if (parent_u != parent_v) {
            dsu.Union(u, v);
            sum += wt;
        }
    }
    // Check if all vertices are included in MST
    for (int i = 0; i < n; i++) {
        if (dsu.find(i) != dsu.find(0)) return INT_MAX;
    }

    return sum;
}

vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges) {

    // since for kruskal's algo, we will sort our input by edge weight.
    // But since we need to return the index in the last
    for (int i = 0; i < edges.size(); i++) {
        edges[i].push_back(i);
    }

    auto cmp = [&](auto &v1, auto &v2) {
        return v1[2] < v2[2];
    };
    // Now sort based on weight
    // O(ElogE)
    sort(edges.begin(), edges.end(), cmp);

    // Find MST now
    // Find MST weight using union-find
    // O(E*@)
    int MST_WEIGHT = Kruskal(edges, -1, -1, n);

    vector<int> critical;
    vector<int> pseudo_critical;
    // O(E*E*@)
    for (int i = 0; i < edges.size(); i++) {

        if (Kruskal(edges, i, -1, n) > MST_WEIGHT) { // Skipping ith edge 
            critical.push_back(edges[i][3]);
        }
        else if (Kruskal(edges, -1, i, n) == MST_WEIGHT) { // Force add ith edge
            pseudo_critical.push_back(edges[i][3]);
        }
    }
    return {critical, pseudo_critical};
}

// Aproach-2 (Better Kruskal's Function)
/*
f ou remember, in the Kruskal's Function, in the end we checked if the graph was connected and wrote a for loop to check that as shown below :
forint i = 0; i<N; i++) {
        if(dsu.find(i) != dsu.find(0))
            return INT_MAX;
 }
BUBUT BUT, we can also directly check if the total edges we made from Union is equal to (V-1).
Remmber, in MST, there must be V vertices and must have (V-1) edges.
So,in Kruskal's function, whenever you do Union, just count the edges you draw.

Sosimply replace the for loop with :
if(dgesConnected != N-1)
        return INT_MAX;

Fu code below :
*/
class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    bool Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) return false;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        }
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
        return true;
    }
};

int Kruskal(vector<vector<int>> &edges, int skip_edge, int add_edge, int n) {

    int sum = 0;

    DSU dsu(n);
    int edgesConnected = 0;

    if (add_edge != -1) {
        dsu.Union(edges[add_edge][0], edges[add_edge][1]);
        sum += edges[add_edge][2];
        edgesConnected++;
    }

    // E

    for (int i = 0; i < edges.size(); i++) {

        if (i == skip_edge) continue;

        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        // O(@)
        int parent_u = dsu.find(u);
        int parent_v = dsu.find(v);

        if (parent_u != parent_v) {
            dsu.Union(u, v);
            edgesConnected++;
            sum += wt;
        }
    }

    if (edgesConnected != n - 1) return INT_MAX;

    return sum;
}

vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges) {
    for (int i = 0; i < edges.size(); i++) {
        edges[i].push_back(i);
    }

    auto lambda = [&](vector<int> &vec1, vector<int> &vec2) {
        return vec1[2] < vec2[2];
    };
    // ElogE
    sort(begin(edges), end(edges), lambda);

    int MST_WEIGHT = Kruskal(edges, -1, -1, n);

    vector<int> critical;
    vector<int> pseudo_critical;

    // E*E*@
    for (int i = 0; i < edges.size(); i++) {

        if (Kruskal(edges, i, -1, n) > MST_WEIGHT) { // skipping ith edge
            critical.push_back(edges[i][3]);
        }

        else if (Kruskal(edges, -1, i, n) == MST_WEIGHT) { // Force add this ith edge
            pseudo_critical.push_back(edges[i][3]);
        }
    }

    return {critical, pseudo_critical};
}

int main() {
    int n = 5;
    vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {2, 3, 2}, {0, 3, 2}, {0, 4, 3}, {3, 4, 3}, {1, 4, 6}};

    vector<vector<int>> result = findCriticalAndPseudoCriticalEdges(n, edges);

    cout << "Critical Edges: ";
    for (int edge : result[0]) {
        cout << edge << " ";
    }
    cout << endl;

    cout << "Pseudo-Critical Edges: ";
    for (int edge : result[1]) {
        cout << edge << " ";
    }
    cout << endl;

    return 0;
}