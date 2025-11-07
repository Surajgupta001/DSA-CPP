/*
Power Grid Maintenance - [Leetcode - 3607(Medium)]
----------------------------------------------------
You are given an integer c representing c power stations, each with a unique identifier id from 1 to c (1‑based indexing).

These stations are interconnected via n bidirectional cables, represented by a 2D array connections, where each element connections[i] = [ui, vi] indicates a connection between station ui and station vi. Stations that are directly or indirectly connected form a power grid.

Initially, all stations are online (operational).

You are also given a 2D array queries, where each query is one of the following two types:

[1, x]: A maintenance check is requested for station x. If station x is online, it resolves the check by itself. If station x is offline, the check is resolved by the operational station with the smallest id in the same power grid as x. If no operational station exists in that grid, return -1.

[2, x]: Station x goes offline (i.e., it becomes non-operational).

Return an array of integers representing the results of each query of type [1, x] in the order they appear.

Note: The power grid preserves its structure; an offline (non‑operational) node remains part of its grid and taking it offline does not alter connectivity.

Example 1:

Input: c = 5, connections = [[1,2],[2,3],[3,4],[4,5]], queries = [[1,3],[2,1],[1,1],[2,2],[1,2]]

Output: [3,2,3]

Explanation:

Initially, all stations {1, 2, 3, 4, 5} are online and form a single power grid.
Query [1,3]: Station 3 is online, so the maintenance check is resolved by station 3.
Query [2,1]: Station 1 goes offline. The remaining online stations are {2, 3, 4, 5}.
Query [1,1]: Station 1 is offline, so the check is resolved by the operational station with the smallest id among {2, 3, 4, 5}, which is station 2.
Query [2,2]: Station 2 goes offline. The remaining online stations are {3, 4, 5}.
Query [1,2]: Station 2 is offline, so the check is resolved by the operational station with the smallest id among {3, 4, 5}, which is station 3.
Example 2:

Input: c = 3, connections = [], queries = [[1,1],[2,1],[1,1]]

Output: [1,-1]

Explanation:

There are no connections, so each station is its own isolated grid.
Query [1,1]: Station 1 is online in its isolated grid, so the maintenance check is resolved by station 1.
Query [2,1]: Station 1 goes offline.
Query [1,1]: Station 1 is offline and there are no other stations in its grid, so the result is -1.
 

Constraints:

1 <= c <= 10^5
0 <= n == connections.length <= min(10^5, c * (c - 1) / 2)
connections[i].length == 2
1 <= ui, vi <= c
ui != vi
1 <= queries.length <= 2 * 10^5
queries[i].length == 2
queries[i][0] is either 1 or 2.
1 <= queries[i][1] <= c
*/ 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;

//Approach-1 (Using DFS)
//T.C : O((c + n) + q log c)
//S.C : O(c + n)
void dfs(int node, unordered_map<int, vector<int>> &graph, int id, vector<int>& nodeId, unordered_map<int, set<int>>& mp, vector<bool>& visited) {
    visited[node] = true;
    mp[id].insert(node);
    nodeId[node] = id;
    for(int &ngbr : graph[node]) {
        if(!visited[ngbr]) {
            dfs(ngbr, graph, id, nodeId, mp, visited);
        }
    }
}
vector<int> processQueriesDFS(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
    unordered_map<int, vector<int>> graph;

    // Build the graph
    for(auto &edge :  connections) {
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(c+1, false);
    vector<int> nodeId(c+1);
    
    //id -> {}
    unordered_map<int, set<int>> mp;
    
    //O(c+n)
    for(int node = 1; node <= c; node++) {
        if(!visited[node]) {
            int id = node;
            dfs(node, graph, id, nodeId, mp, visited);
        }
    }
    
    vector<int> result;
    //O(q * log(c))
    for(auto &query : queries) {
        int type = query[0]; //1, 2
        int node = query[1]; //station/node
        if(type == 1) {
            int id = nodeId[node];
            if(mp[id].count(node)) {
                result.push_back(node);
            } else if(!mp[id].empty()) {
                result.push_back(*mp[id].begin());
            } else {
                result.push_back(-1);
            }
        } else {
            int id = nodeId[node];
            mp[id].erase(node); //log(c)
        }
    }
    return result;
}

//Approach-2 (Using BFS)
//T.C : O((c + n) + q log c)
//S.C : O(c + n)
void bfs(int start, unordered_map<int, vector<int>> &graph, int id, vector<int>& nodeId, unordered_map<int, set<int>>& mp, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    nodeId[start] = id;
    mp[id].insert(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int &ngbr : graph[node]) {
            if (!visited[ngbr]) {
                visited[ngbr] = true;
                nodeId[ngbr] = id;
                mp[id].insert(ngbr);
                q.push(ngbr);
            }
        }
    }
}
vector<int> processQueriesBFS(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
    unordered_map<int, vector<int>> graph;

    // Build the graph
    for (auto &edge : connections) {
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(c + 1, false);
    vector<int> nodeId(c + 1);
    
    unordered_map<int, set<int>> mp;
    
    // O(c + n)
    for (int node = 1; node <= c; node++) {
        if (!visited[node]) {
            int id = node;
            bfs(node, graph, id, nodeId, mp, visited);
        }
    }
    
    vector<int> result;
    // O(q * log(c))
    for (auto &query : queries) {
        int type = query[0]; // 1 or 2
        int node = query[1]; // station/node
        if (type == 1) {
            int id = nodeId[node];
            if (mp[id].count(node)) {
                result.push_back(node);
            } else if (!mp[id].empty()) {
                result.push_back(*mp[id].begin());
            } else {
                result.push_back(-1);
            }
        } else {
            int id = nodeId[node];
            mp[id].erase(node); // O(log c)
        }
    }
    return result;
}


//Approach-3 (Using DSU)
//T.C : O((n+c+q)×α(c)), n = connections.size(), c = number of nodes, q = number of queries
//S.C : O(n + c + q)
int find(vector<int>& parent, int x){
    return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
}

void Union(vector<int>& parent, vector<int>& rank, int a, int b){
    a = find(parent, a);
    b = find(parent, b);
    
    if(a == b) return;
    
    if(rank[a] < rank[b]){
        parent[a] = b;
    } else if(rank[a] > rank[b]){
        parent[b] = a;
    } else {
        parent[b] = a;
        rank[a]++;
    }
}

vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
    vector<int> result;
    int n = connections.size();
    
    vector<int> parent(c+1);
    vector<int> rnk(c+1, 0);
    
    for(int i = 1; i <= c; i++) {
        parent[i] = i;
    }
    
    for(auto& edge : connections) {
        int u = edge[0];
        int v = edge[1];
        Union(parent, rnk, u, v);
    }
    
    unordered_map<int, set<int>> mp; //id -> {ordered set of nodes}
    vector<int> nodeId(c+1);
    
    for(int i = 1;i <= c; i++){
        int par = find(parent, i);
        mp[par].insert(i);
        nodeId[i] = par;
    }
    
    for(auto& query : queries){
        int type = query[0]; //1, 2
        int node = query[1]; //station/node
        int id = nodeId[node];
        if(type == 1) {
            if(mp[id].find(node) != mp[id].end()){
                result.push_back(node);
            } else if(!mp[id].empty()) {
                result.push_back(*mp[id].begin());
            } else {
                result.push_back(-1);
            }
        }
        else {
            mp[id].erase(node);
        }
    }
    return result;
}

int main() {
    int c = 5;
    vector<vector<int>> connections = {{1,2},{2,3},{3,4},{4,5}};
    vector<vector<int>> queries = {{1,3},{2,1},{1,1},{2,2},{1,2}};

    vector<int> results = processQueries(c, connections, queries);

    for(int res : results){
        cout << res << " ";
    }
    cout << endl;

    return 0;
}