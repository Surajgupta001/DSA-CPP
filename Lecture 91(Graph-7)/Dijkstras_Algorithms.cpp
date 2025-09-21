/*
- DS - Visited set, Priority_queue<pair>, unordered_map
- insert the pair of <-1,src> in the queue
- one bu one remove the root element of the queue
- if the root element is already visitedl, then we will just continue.
- we mark the root visited
- we store the wt of the pair in the ans
- update the mapping
- go to every neighbour of the curr element, and only add those which are non visited and have a better wt proposition.
*/

/*
Dijkstra's Algorithm (for graphs with non-negative edge weights)
- Graph: adjacency list storing (neighbor, weight)
- Priority queue (min-heap) on current best distance
- visited set finalizes shortest distance for a node when popped
- mp holds shortest known distance from src to any node
- via stores parent to reconstruct paths (optional; currently not printed)

Input format (0-indexed vertices):
n m
u v wt   (m lines, by default undirected edges)
src
dest

Output:
- First: all nodes with their distances (unordered_map iteration order)
- Then: distance from src to dest
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
#include <unordered_set>
#include <climits>
#define ll long long int
// #define pp pair<int, int>
using namespace std;

// Graph as adjacency list: for each node store list of (neighbor, weight)
vector<list<pair<int,int>>> graph; // <vertex, weight>

// Add an edge u --wt-- v; set bi_dir=false for directed graphs
void add_edge(int u, int v, int wt, bool bi_dir = true){
    graph[u].push_back({v, wt});
    if(bi_dir) graph[v].push_back({u, wt});
}

// Dijkstra's algorithm from 'src' over 'n' nodes labeled [0..n-1]
// Returns distance map: node -> shortest distance from src
// Time: O((V + E) log V)
unordered_map<int,int> dijkstra(int src, int n){
    // Min-heap of (distance_so_far, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // min-heap to get node with smallest tentative distance

    unordered_set<int> visited;       // nodes whose shortest distance is finalized
    vector<int> via(n+1);             // parent to reconstruct paths (not printed)
    unordered_map<int,int> mp;        // distance map; use INT_MAX as "infinity"

    // Initialize all distances to INF
    for(int i = 0; i < n; i++) mp[i] = INT_MAX;

    // Start with the source
    q.push({0, src});
    mp[src] = 0;

    while(!q.empty()){
        pair<int,int> curr = q.top(); // node with smallest tentative distance
        if(visited.count(curr.second)){
            q.pop();
            continue;                 // skip if already finalized
        }

        visited.insert(curr.second);  // finalize this node
        q.pop();

        // Relax all neighbors
        for(auto neighbour : graph[curr.second]){
            int v = neighbour.first;
            int w = neighbour.second;

            // Only consider if not finalized and a better path is found
            if(!visited.count(v) && mp[curr.second] != INT_MAX && mp[v] > mp[curr.second] + w){
                mp[v] = mp[curr.second] + w;
                via[v] = curr.second; // track path (optional)
                q.push({mp[v], v});
            }
        }
    }
    return mp;
}

int main(){
    int n, m;
    cin >> n >> m;

    // Initialize graph with n nodes
    graph.resize(n, list<pair<int,int>>());

    // Read edges (by default undirected; set add_edge(..., false) if directed)
    while(m--){
        int u, v, wt;
        cin >> u >> v >> wt;
        add_edge(u, v, wt);
    }

    int src;
    cin >> src;

    // Compute shortest distances from src
    unordered_map<int,int> mp = dijkstra(src, n);

    // Print distances (unordered order due to unordered_map)
    for(auto itr : mp){
        cout << itr.first << " " << itr.second << endl;
    }

    // Query a destination and print its distance
    int dest;
    cin >> dest;
    cout << mp[dest] << endl;

    return 0;
}