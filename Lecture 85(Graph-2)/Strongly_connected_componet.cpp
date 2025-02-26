/*
Strongly Connected Component (SCC)
==================================
Kosaraju's Algorithm
*/ 

#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <stack>
using namespace std;

vector<vector<int>> graph; // global
int v; // no. of vertices
vector<vector<int>> transposeGraph; // global

// Function to add edge to the graph
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

// Function to perform DFS and fill the stack with vertices in the order they finish
void fillStack(int vertex, vector<bool>& visited, stack<int>& st) {
    visited[vertex] = true;
    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            fillStack(neighbor, visited, st);
        }
    }
    st.push(vertex);
}

// Function to perform DFS on the transpose graph and find SCC
void findSCC(int vertex, vector<bool>& visited, vector<int>& scc) {
    visited[vertex] = true;
    scc.push_back(vertex);
    for (int neighbor : transposeGraph[vertex]) {
        if (!visited[neighbor]) {
            findSCC(neighbor, visited, scc);
        }
    }
}

// Function to find Strongly Connected Components
void findStronglyConnectedComponents() {
    stack<int> s;
    vector<bool> visited(v, false);
    int sccCount = 0; // Initialize SCC count

    // Fill the stack with vertices in the order they finish
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            fillStack(i, visited, s);
        }
    }

    // Create the transpose graph
    transposeGraph.resize(v);
    for (int i = 0; i < v; i++) {
        for (int neighbor : graph[i]) {
            transposeGraph[neighbor].push_back(i);
        }
    }

    // Reset the visited array
    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }

    // Find SCC
    while (!s.empty()) {
        int vertex = s.top();
        s.pop();
        if (!visited[vertex]) {
            vector<int> scc;
            findSCC(vertex, visited, scc);
            cout << "Strongly Connected Component: ";
            for (int i : scc) {
                cout << i << " ";
            }
            cout << endl;
            sccCount++; // Increment SCC count
        }
    }

    cout << "Number of Strongly Connected Components: " << sccCount << endl;
}

int main(){
    
    cout<<"Enter the number of vertices: ";
    cin>>v;
    
    graph.resize(v);
    
    int e;
    cout<<"Enter the number of edges: ";
    cin>>e;
    
    while(e--){
        int src, dest;
        cout<<"Enter source and destination: ";
        cin>>src>>dest;
        add_edge(src, dest, false); // Changed to false to create a directed graph
    }
    
    findStronglyConnectedComponents();
    
    return 0;
}