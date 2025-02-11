/*
Kruskal (MST - Minimum Spanning Tree) : Really Special SubTree [Hacker Rank]
===========================================================
Given an undirected weighted connected graph, find the Really Special SubTree in it. The Really Special SubTree is defined as a subgraph consisting of all the nodes in the graph and:

-> There is only one exclusive path from a node to every other node.
-> The subgraph is of minimum overall weight (sum of all edges) among all such subgraphs.
-> No cycles are formed.

To create the Really Special SubTree, always pick the edge with smallest weight. Determine if including it will create a cycle. If so, ignore the edge. If there are edges of equal weight available:

* Choose the edge that minimizes the sum u+v+wt where u and v are vertices and wt is the edge weight.
* If there is still collision, chose using any of them

Print the overall weight of the tree formed using the rules.

For example, given the following edges:
u   v   wt
1   2   2
2   3   3
3   1   5

First choose 1 -> 2 at weight 2. Next choose 2 -> 3 at weight 3. All nodes are connected without cycle for a total weight 3 + 2 = 5 
*/

/*
========== Understanding ==============
Special Subtree ===> tree ----> no cycle 
Subgraph ==> it containsn all the vertices.

MST = > Minimum Spanning Tree
Tree -> graph having no cycle
Spanning -> subgraph having all vertices but min no. of edges available to keep it connected.
*/ 

/*
KRUSKAL's Algorithms
1. One by one keep a picking edge with min weight
2. If choosing an edge forms a cycle avoid it, else it
edge list -> sort by weight
DSU
*/ 

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int find(vector<int> &parent, int a) {
    return parent[a] = ((parent[a] == a) ? a : find(parent, parent[a]));
}

void Union(vector<int> &par, vector<int> &rank, int a, int b) {
    a = find(par, a);
    b = find(par, b);
    if(a == b) return;
    if(rank[a] >= rank[b]) {
        rank[a]++;
        par[b] = a;
    } else {
        rank[b]++;
        par[a] = b;
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

ll kruskals(vector<Edge> &input, int n, int e) { // O(V + ElogE)
    sort(input.begin(), input.end(), cmp); // ElogE
    vector<int> parent(n+1);
    vector<int> rank(n+1, 1);
    for(int i = 0; i <= n; i++) {
        parent[i] = i;
    }
    int edgeCount = 0; // n-1
    int i = 0;
    ll ans = 0;
    while(edgeCount < n-1 and i < input.size()) { // V-1 -> O(Vlg*V)
        Edge curr = input[i]; // because input is sorted so we will get min wt edge
        int srcPar = find(parent, curr.src);
        int destpar = find(parent, curr.dest);
        if(srcPar != destpar) {
            // include edge as this will not make cycle
            Union(parent, rank, srcPar, destpar);
            ans += curr.wt;
            edgeCount++;
        }

        i++; // doesnt matter u picked the last edge or not, we still need to go to next edge
    }

    return ans;

}

int main(){   
    int n, e;
    cin>>n>>e;
    vector<Edge> v(e);
    for(int i = 0; i < e; i++) {
        cin>>v[i].src>>v[i].dest>>v[i].wt;
    }
    cout<<kruskals(v, n, e)<<endl;

    return 0;
}