/*
- DS - Visited set, Priority_queue<pair>, unordered_map
- insert the pair of <-1,src> in the queue
- one bu one remove the root element of the queue
- if the root element is already visitedl, then we will just continue.
- we mark the root visited
- we store the wt of the pair in the ans
- update the mapping
- go to every neighbour of the curr element, and only add those which are non visited and have a better wt proposition.
*/ 

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
#include <unordered_set>
#include <climits>
#define ll long long int
// #define pp pair<int, int>
using namespace std;

vector<list<pair<int,int>>>graph; // <int,int> ---> <vertex, weight> -- weighted graph
void add_edge(int u, int v, int wt, bool bi_dir = true){
    graph[u].push_back({v, wt});
    if(bi_dir) graph[v].push_back({u, wt});
}

unordered_map<int,int> dijkstra(int src, int n){ // O(VlogV + ElogV)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // {wt, node}
    unordered_set<int>visited;
    vector<int>via(n+1);
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++) mp[i] = INT_MAX; // O(V)
    q.push({0, src});
    mp[src] = 0;

    while(not q.empty()){ // O((V+E)logV)
        pair<int,int> curr = q.top();
        if(visited.count(curr.second)){
            q.pop();
            continue;
        }
        visited.insert(curr.second);
        q.pop();
        for(auto neighbour : graph[curr.second]){
            if(not visited.count(neighbour.first) and mp[neighbour.first] > mp[curr.second] + neighbour.second){
                q.push({mp[curr.second] + neighbour.second, neighbour.first});
                via[neighbour.first] = curr.second;
                mp[neighbour.first] = mp[curr.second] + neighbour.second;
            }
        }
    }
    return mp;
}

int main(){
    int n, m;
    cin >> n >> m;
    graph.resize(n, list<pair<int,int>>());
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        add_edge(u, v, wt);
    }
    int src;
    cin>>src;
    unordered_map<int,int> mp = dijkstra(src, n);
    for(auto itr : mp){
        cout<<itr.first<<" "<<itr.second<<endl;
    }
    int dest;
    cin>>dest;
    cout<<mp[dest]<<endl;
    
    return 0;
}