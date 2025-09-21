/*
Given a directed graph, return true if there is a cycle in the graph, otherwise return false.

Example 1:

Input:
4 3
0 1
1 2
2 0

Output:
true

Explanation:
There is a cycle in the graph: 0 -> 1 -> 2 -> 0.

Example 2:

Input:
4 3
0 1
1 2
2 3

Output:
false

Explanation:
There is no cycle in the graph.
*/

#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

// vector<list<int>>undirected_unweighted_graph;
vector<vector<int>>graph;

int v; // no of vertices

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto ele:graph[i]){
            cout<<""<<ele<<" : ";
        }
        cout<<endl;
    }
}

bool dfs(int src, int parent, unordered_set<int> &visited) {
    visited.insert(src);
    for(auto neighbour : graph[src]) {
        if(visited.count(neighbour) and neighbour != parent) {
            // cycle detected
            return true;
        }
        if(!visited.count(neighbour)) {
            bool res = dfs(neighbour, src, visited);
            if(res == true) return true;
        }
    } 
    return false;
}

bool hasCycle() {
    unordered_set<int> visited;
    for(int i = 0; i < v; i++) {
        if(!visited.count(i)) {
            bool result = dfs(i, -1, visited);
            if(result == true) return true;
        }
    }
    return false;
}

int main(){

    cout << "Enter the number of vertices: ";
    cin >> v;
    // graph.resize(v, list<int> ());
    graph.resize(v);
    int e;
    cout << "Enter the number of edges: ";
    cin >> e;
    while(e--){
        int src, dest;
        cout << "Enter source and destination: ";
        cin >> src >> dest;
        add_edge(src, dest, false); // waighted graph
        /*
        When to use which:
        -> Directed graph: add_edge(s, d, false);
        -> Undirected graph: add_edge(s, d); or add_edge(s, d, true);
        */ 

    }
    display();
    cout<<boolalpha<<hasCycle();
    // true -> cycle present
    // false -> cycle not present
    return 0;
}