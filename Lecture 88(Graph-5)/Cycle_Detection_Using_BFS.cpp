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
#include <bits/stdc++.h>
using namespace std;

vector<list<int>>graph;
int v; // no. of vertices

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

void display(){
    for(int i = 0; i < graph.size(); i++){
        cout << i << " -> ";
        for(auto itr = graph[i].begin(); itr != graph[i].end(); itr++){
            cout << *itr << " ";
        }
        cout << endl;
    }
}

bool bfs(int src){
    unordered_set<int>visited;
    queue<int>q;
    vector<int>parent(v,-1);
    q.push(src);
    visited.insert(src);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto neighbour : graph[curr]){
            if(visited.count(neighbour) and parent[curr] != neighbour) return true;
            if(visited.count(neighbour)){
                visited.insert(neighbour);
                parent[neighbour] = curr;
                q.push(neighbour);
            }
        }
    }
}

bool hasCycle(){
    unordered_set<int>visited;
    for(int i=0;i<v;i++){
        if(not visited.count(i)){
            bool result = bfs(i);
            if(result) return true;
        }
    }
}

int main() {

    cout<<"Enter number of vertices: ";
    cin>>v;
    graph.resize(v, list<int> ());
    int e;
    cout<<"Enter number of edges: ";
    cin>>e;
    while(e--) {
        int s, d;
        cout<<"Enter source and destination: ";
        cin>>s>>d;
        add_edge(s, d, false);

        /*
        When to use which:
        -> Directed graph: add_edge(s, d, false);
        -> Undirected graph: add_edge(s, d); or add_edge(s, d, true);
        */ 
    }
    display();
    
    cout<<boolalpha<<hasCycle()<<endl;
    // true -> cycle present
    // false -> cycle not present

    return 0;
}