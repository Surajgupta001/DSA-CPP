# Dijkstra’s Algorithm

Dijkstra’s algorithm computes shortest path distances from a single source to all vertices in a graph with non-negative edge weights.

Key ideas:

- Use a min-priority queue (min-heap) keyed by current best distance.
- Pop the node with the smallest tentative distance; once popped, its distance is finalized.
- Relax edges out of that node; if a better path to a neighbor is found, update its distance and push it to the heap.
- Never works with negative edge weights.

## When to use

- Graphs with non-negative weights (directed or undirected).
- Need shortest distances from a single source to all nodes (or to one target with early stopping).

Avoid when:

- Edge weights can be negative (use Bellman–Ford or SPFA).
- Need all-pairs shortest paths (consider repeated Dijkstra or Floyd–Warshall).

## Data structures

- Adjacency list: neighbors with weights.
- Min-heap (priority_queue with greater comparator).
- Distance array/map initialized to +∞ except source = 0.
- Optional: parent array to reconstruct paths.
- Visited/finalized set to avoid reprocessing nodes.

## Pseudocode

```cpp
Dijkstra(G = (V,E), w, src):
  for each v in V:
    dist[v] = +∞
    parent[v] = NIL
    visited[v] = false
  dist[src] = 0
  PQ = min-heap of pairs (dist, v)
  push (0, src) into PQ

  while PQ not empty:
    (d, u) = pop_min(PQ)
    if visited[u]: continue
    visited[u] = true

    for each (u, v) ∈ E with weight w(u,v):
      if visited[v]: continue
      if dist[u] + w(u,v) < dist[v]:
        dist[v] = dist[u] + w(u,v)
        parent[v] = u
        push (dist[v], v) into PQ

  return dist, parent
```

Notes:

- `dist[v]` holds the shortest distance from `src` to `v`.
- Using “visited” ensures each node is finalized once (the first time it’s popped).
- It’s okay to push multiple entries for the same node; stale entries are skipped when popped.

## Code

```cpp
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
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

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
```

## Complexity

- Using adjacency list + binary heap: O((V + E) log V).
- Space: O(V + E).

## Correctness (intuition)

- Greedy choice: when a node u is popped, all remaining nodes have distance ≥ dist[u]. Any alternative path to u must pass through nodes with distance ≥ dist[u], so cannot yield a shorter path to u.

## Implementation notes tied to the code

- Graph: vector<list<pair<int,int>>> where each pair is (neighbor, weight).
- Distances stored in unordered_map<int,int> mp; initialized to INT_MAX.
- via vector tracks parents (path reconstruction) but is optional.
- visited unordered_set finalizes nodes on first pop.
- add_edge(u, v, wt, bi_dir=true) — set bi_dir=false for directed graphs.

### Path reconstruction (optional)

After running Dijkstra, rebuild path to dest by following parents:

```cpp
path = []
cur = dest
while cur != NIL:
  path.push_back(cur)
  cur = parent[cur]
reverse(path)
```

### Early stop for single-target query

If only the distance to “dest” is needed, you can break once dest is popped (finalized).

## Input/Output used by the sample program

Input:

- n m
- m lines: u v wt  (by default treated as undirected; change to directed by passing bi_dir=false in add_edge)
- src
- dest

Output:

- Distances for all nodes (unordered order due to unordered_map).
- Distance from src to dest on the last line.

Example:

```plain
5 6
0 1 2
0 2 5
1 2 1
1 3 3
2 4 2
3 4 4
0
4
```

Possible output (node order may vary):
```
0 0
1 2
2 3
3 5
4 5
5
```

## Common pitfalls

- Negative weights invalidate Dijkstra (use Bellman–Ford).
- Integer overflow if path sums exceed int; use long long for large weights.
- Forgetting visited set leads to reprocessing and higher runtime.
- For directed graphs, remember to pass bi_dir=false when adding edges.
