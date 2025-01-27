/*
INPUT:

Enter the number of vertices: 7 
Enter the number of edges: 8
Enter edge (source destination): 0 1
Enter edge (source destination): 0 4
Enter edge (source destination): 1 3
Enter edge (source destination): 4 3
Enter edge (source destination): 1 5
Enter edge (source destination): 5 6
Enter edge (source destination): 6 2
Enter edge (source destination): 5 2
Enter start and end vertices: 0 6

OUTPUT:

0 1 5 6 
0 1 5 2 6 
0 4 3 1 5 6 
0 4 3 1 5 2 6 
*/ 


#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
vector<vector<int>> result;

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

/*
============ First Way ===============
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
*/ 

void dfs(int curr, int end, vector<int>& paths){
    if(curr == end){
        paths.push_back(curr);
        result.push_back(paths);
        paths.pop_back();
        return;
    }
    visited.insert(curr); // mark visited
    paths.push_back(curr);
    for(auto neighbour : graph[curr]){
        if(not visited.count(neighbour)){
            dfs(neighbour, end, paths);
        }
    }
    paths.pop_back();
    visited.erase(curr);
    return;
}

void allPath(int src, int dest){
    vector<int> v;
    dfs(src, dest, v);
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
        add_edge(src, dest);
    }
    
    int start, end;
    cout << "Enter start and end vertices: ";
    cin>>start>>end;
    allPath(start, end);
    for(auto path : result){
        for(auto ele : path){
            cout<<ele<< " ";
        }
        cout<<endl;
    }
    return 0;
}
