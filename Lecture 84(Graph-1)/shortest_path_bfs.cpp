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
Enter start vertices: 0 

OUTPUT:


*/ 


#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <queue>
#include <climits>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
vector<vector<int>> result;
int v; // no of vertices
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

void bfs(int src, vector<int>& dist){
    queue<int> q;
    visited.clear();
    dist.resize(v, (v, INT_MAX));
    dist[src] = 0;
    visited.insert(src);
    q.push(src);
    while(!q.empty()){
        int curr = q.front();
        cout<<curr<<" ";
        q.pop();
        for(auto neighbour : graph[curr]){
            if(!visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour] = dist[curr] + 1;
            }
        }
        cout<<endl;
    }
}

int main(){

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
    
    int start;
    cout<<"Enter start vertices: ";
    cin>>start;

    vector<int> dist;
    bfs(start, dist);
    for(int i=0;i<dist.size();i++){
        // cout << "Vertex " << i << " is at distance " << dist[i] << endl;
        cout<<dist[i]<<endl;
    }
    return 0;
}
