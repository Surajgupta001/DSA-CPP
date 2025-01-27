#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<unordered_map<int, int>> graph;
int v; // no of vertices
void add_edge(int src, int dest, int wt, bool bi_dir = true){
    graph[src][dest] = wt;
    if(bi_dir) graph[dest][src] = wt;
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

    cin >> v;
    graph.resize(v, unordered_map<int, int> ());
    int e;
    cin >> e;
    while(e--){
        int src, dest, wt;
        cin >> src >> dest >> wt;
        add_edge(src, dest, wt); // unwaighted graph
        // add_edge(src, dest, wt, false); // waighted graph

    }
    display();
    return 0;
}