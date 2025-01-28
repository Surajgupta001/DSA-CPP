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

void dfs(int node, unordered_set<int>& visited){
    visited.insert(node);
    for(auto neighbor : graph[node]){
        if(not visited.count(neighbor)){
            dfs(neighbor, visited);
        }
    }
}

int connected_component(){
    unordered_set<int>visited;
    int count = 0;
    for(int i=0;i<v;i++){
        // go to every vertex
        // if from a vertex we can initialse a dfs, we got one more cc
        if(visited.count(i) == 0){
            count++;
            dfs(i, visited);
        }
    }
    return count; // return the count of connected components
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
        // add_edge(src, dest); // unwaighted graph
        add_edge(src, dest, false); // waighted graph

    }
    int connected_components = connected_component(); // call the function and store the result
    cout<<"Connected Component : "<<connected_components<<endl;

    return 0;
}