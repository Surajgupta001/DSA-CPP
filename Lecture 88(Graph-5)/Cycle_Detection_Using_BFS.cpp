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

    cin>>v;
    graph.resize(v, list<int> ());
    int e;
    cin>>e;
    while(e--) {
        int s, d;
        cin>>s>>d;
        add_edge(s, d, false);
    }
    display();
    
    cout<<boolalpha<<hasCycle()<<endl;

    return 0;
}