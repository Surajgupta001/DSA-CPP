#include <iostream>
#include <vector>
#include <list>
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

int main(){

    cin >> v;
    // graph.resize(v, list<int> ());
    graph.resize(v);
    int e;
    cin >> e;
    while(e--){
        int src, dest;
        cin >> src >> dest;
        add_edge(src, dest); // unwaighted graph
        add_edge(src, dest, false); // waighted graph

    }
    display();
    return 0;
}