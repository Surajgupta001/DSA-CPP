/*
Clone Graph - [Leetcode - 133(Medium)]
=============================================
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.


Example 1:

Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
Example 2:


Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
Example 3:

Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.
 

Constraints:

The number of nodes in the graph is in the range [0, 100].
1 <= Node.val <= 100
Node.val is unique for each node.
There are no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given node.
*/ 

#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node.
class node{
public:
    int value;
    vector<node*> neighbors;

    // Constructor - default
    node(){
        value = 0;
        neighbors = vector<node*>();
    }
    // constructor - with parameter
    node(int data) {
        value = data;
        neighbors = vector<node*>();
    }
    // constructor - with parameter
    node(int data, vector<node*> neighbors) {
        value = data;
        neighbors = neighbors;
    }
};


vector<node*> nodeRegister;

void dfs(node *actual, node *clone){
    for(auto neighbor : actual->neighbors){
        if(not nodeRegister[neighbor->value]){
            // Create the neighbour for the first time
            node *newNode = new node(neighbor->value);
            nodeRegister[newNode->value] = newNode;
            clone->neighbors.push_back(newNode);
            dfs(neighbor, newNode);
        }
        else{
            // If the neighbour is already created, just add it to the clone
            clone->neighbors.push_back(nodeRegister[neighbor->value]);
        }
    }
}

node *cloneGraph(node *original){
    if(original == nullptr) return nullptr;
    // Create a new node with the same value as the original node
    node *clone = new node(original->value);
    nodeRegister.resize(110, nullptr); // this array ref to the created nodes
    nodeRegister[original->value] = clone;
    dfs(original, clone);
    return clone;
};

void display(node *node){
    if(node == nullptr) return;
    cout<<"node "<<node->value<<" has neighbors: ";
    for(auto neighbor : node->neighbors){
        cout<<neighbor->value<<" ";
    }
    cout<<endl;
    for(auto neighbor : node->neighbors){
        display(neighbor);
    }
}

int main(){
    node *node1 = new node(1);
    node *node2 = new node(2);
    node *node3 = new node(3);
    node *node4 = new node(4);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    // clone the graph
    node *clone = cloneGraph(node1);

    // Display the original graph
    cout<<"Original Graph: "<<endl;
    display(node1);

    // Display the cloned graph
    cout<<"Cloned Graph: "<<endl;
    display(clone);

    return 0;
}