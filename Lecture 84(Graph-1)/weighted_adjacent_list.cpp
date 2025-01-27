#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<vector<pair<int,int>>>graph;
int v; // no of vertices
void add_edge(int src, int dest, int wt, bool bi_dir = true){
    graph[src].push_back({dest, wt});
    if(bi_dir) graph[dest].push_back({src, wt});
}

void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto ele:graph[i]){
            cout<<"("<<ele.first<<" "<<ele.second<<"): ";
        }
        cout<<endl;
    }
}

int main(){

    cout << "Enter the number of vertices: ";
    cin >> v;
    // graph.resize(v, list<pair<int, int>> ());
    graph.resize(v);
    int e;
    cout << "Enter the number of edges: ";
    cin >> e;
    while(e--){
        int src, dest, wt;
        cout << "Enter source and vertex: ";
        cin >> src >> dest >> wt;
        add_edge(src, dest, wt); // unwaighted graph
        // add_edge(src, dest, wt, false); // waighted graph

    }
    display();
    return 0;
}