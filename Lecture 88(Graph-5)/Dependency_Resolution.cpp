/*
Dependency Resolution in Graph
Problem Statement
Given a directed acyclic graph (DAG) representing dependencies between nodes, resolve the dependencies by ordering the nodes in a way that for every edge (u, v), node u comes before node v in the ordering.
*/

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>
using namespace std;

vector<list<int>> graph;
int v; // no of vertex;
void add_edge(int a, int b, bool biDir = true){
    graph[a].push_back(b);
    if(biDir) graph[b].push_back(a);
}

void topoBFS(){
    // Kahn algorithms
    vector<int> indegree(v, 0);
    for(int i = 0; i < v; i++){
        for(auto neighbour : graph[i]){
            // i -> neighbours
            indegree[neighbour]++;
        }
    }
    // Create a queue and enqueue all vertices with indegree 0
    queue<int>q;
    unordered_set<int> visited;
    for(int i = 0; i < v; i++){
        if(indegree[i] == 0){
            q.push(i);
            visited.insert(i);
        }
    }
    // Process all vertices in the queue
    while(!q.empty()){
        int node = q.front();
        q.pop();
        // Process this node
        cout<<node<<" ";
        for(auto neighbour : graph[node]){
            if(not visited.count(neighbour)){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
    }
}
int main(){
    
    cout<<"Enter the number of vertex: ";
    cin>>v;

    int e;
    cout<<"Enter the number of edges: ";
    cin>>e;

    graph.resize(v, list<int>());
    while(e--){
        int x, y;
        cin>>x>>y;
        add_edge(x, y, false);
    }
    topoBFS();
    return 0;
}