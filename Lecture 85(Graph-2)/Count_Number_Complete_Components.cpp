/*
Count the Number of Complete Components - [Leetcode - 2685(Medium)]
===================================================================
You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

Return the number of complete connected components of the graph.

A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be complete if there exists an edge between every pair of its vertices.

Example 1:

Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
Output: 3
Explanation: From the picture above, one can see that all of the components of this graph are complete.

Example 2:

Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
Output: 1
Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.

Constraints:

1 <= n <= 50
0 <= edges.length <= n * (n - 1) / 2
edges[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
There are no repeated edges.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

void dfs(int node, vector<bool> &visited, vector<int> &component, vector<vector<int>> &graph){
    if (node < 0 || node >= graph.size()) {
        throw out_of_range("Node out of bounds");
    }

    visited[node] = true;
    component.push_back(node);
    for (auto neighbor : graph[node]) {
        if (not visited[neighbor]) {
            dfs(neighbor, visited, component, graph);
        }
    }
}

int countCompleteComponents(int n, vector<vector<int>> &edges) {
    if (n == 0) return 0; // Empty graph
    if (n == 1) return 1; // Single node graph

    vector<vector<int>> graph(n);
    for (auto &edge : edges){
        if (edge.size() != 2 || edge[0] < 0 || edge[0] >= n || edge[1] < 0 || edge[1] >= n){
            throw invalid_argument("Invalid edge");
        }
        if (edge[0] != edge[1] &&
            std::find(graph[edge[0]].begin(), graph[edge[0]].end(), edge[1]) == graph[edge[0]].end()){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
    }
    int count = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++){
        if (not visited[i]) {
            vector<int> component;
            dfs(i, visited, component, graph);

            bool isComplete = true;
            for (int i = 0; i < component.size(); i++){
                for (int j = i + 1; j < component.size(); j++){
                    bool found = false;
                    for (int k = 0; k < graph[component[i]].size(); k++){
                        if (graph[component[i]][k] == component[j]){
                            found = true;
                            break;
                        }
                    }
                    if (!found){
                        isComplete = false;
                        break;
                    }
                }
            }
            if (isComplete || component.size() == 1){
                count++; // count single node components as complete
            }
        }
    }
    return count;
}

int main(){
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int numEdges;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> edges(numEdges, vector<int>(2));
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < numEdges; i++){
        cin >> edges[i][0] >> edges[i][1];
    }

    int count = countCompleteComponents(n, edges);
    cout << "Number of complete components: " << count << endl;

    return 0;
}

// Enter the number of nodes: 6
// Enter the number of edges: 4
// Enter the edges (u v):
// 0 1
// 0 2
// 1 2
// 3 4
// Number of complete components: 3Enter the number of nodes: 6
// Enter the number of edges: 4
// Enter the edges (u v):
// 0 1
// 0 2
// 1 2
// 3 4
// Number of complete components: 3

/*
================ Using Disjoint Set Union (DSU) ================
int find(vector<int>& parent, int x){
    return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
}

void Union(vector<int>& rank, vector<int>& parent, int a, int b){
    a = find(parent, a);
    b = find(parent, b);

    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
    }
    else{
        rank[b]++;
        parent[a] = b;
    }
}

bool edgesExist(int a, int b, vector<vector<int>> &edges) {
    for (auto &edge : edges) {
        if ((edge[0] == a && edge[1] == b) || (edge[0] == b && edge[1] == a)) {
            return true;
        }
    }
    return false;
}

int countCompleteComponents(int n, vector<vector<int>>& edges){
    vector<int> rank(n, 1);
    vector<int> parent(n);
    for(int i=0; i<n; i++) parent[i] = i;

    for(auto &edge : edges){
        Union(rank, parent, edge[0], edge[1]);
    }

    vector<unordered_set<int>> components(n);
    for(int i=0; i<n; i++){
        // int root = find(parent, i);
        // components[root].insert(i);
        components[find(parent, i)].insert(i);
    }

    int count = 0;
    for(auto &component : components){
        if(component.size() > 0){
            bool isComplete = true;
            for(int i : component){
                for(int j : component){
                    if(i != j and !edgesExist(i, j, edges)){
                        isComplete = false;
                    }
                }
            }
            if(isComplete or component.size() == 1) count++;
        }
    }
    return count;
}
*/ 