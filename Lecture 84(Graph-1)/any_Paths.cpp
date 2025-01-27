#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

vector<list<int>>graph;
unordered_set<int> visited;

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

bool dfs(int curr, int end){
    if(curr == end) return true;
    visited.insert(curr); // mark visited
    for(auto neighbour : graph[curr]){
        if(not visited.count(neighbour)){
            bool result = dfs(neighbour, end);
            if(result) return true;
        }
    }
    return false;
}

bool anyPaths(int src, int dest){
    return dfs(src, dest);
}

int main(){

    int v;
    cout << "Enter the number of vertices: ";
    cin>>v;

    graph.resize(v, list<int> ());
    
    int e;
    cout << "Enter the number of edges: ";
    cin>>e;
    
    visited.clear();
    
    while(e--){
        int src, dest;
        cout << "Enter edge (source destination): ";
        cin>>src>>dest;
        add_edge(src, dest, false);
    }
    
    int start, end;
    cout << "Enter start and end vertices: ";
    cin>>start>>end;
    cout<<"Paths Exists: "<<boolalpha<<anyPaths(start, end)<<endl;
    
    return 0;
}