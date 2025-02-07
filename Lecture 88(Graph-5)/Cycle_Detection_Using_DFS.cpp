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

bool dfs(int src, int parent, unordered_set<int> &vis) {
    vis.insert(src);
    for(auto neighbour : graph[src]) {
        if(vis.count(neighbour) and neighbour != parent) {
            // cycle detected
            return true;
        }
        if(!vis.count(neighbour)) {
            bool res = dfs(neighbour, src, vis);
            if(res == true) return true;
        }
    } 
    return false;
}

bool hasCycle() {
    unordered_set<int> vis;
    for(int i = 0; i < v; i++) {
        if(!vis.count(i)) {
            bool result = dfs(i, -1, vis);
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

    }
    display();
    cout<<boolalpha<<hasCycle();
    return 0;
}