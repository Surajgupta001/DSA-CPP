/*
2385. Amount of Time for Binary Tree to Be Infected - [Leetcode - 2385(Medium)]
-------------------------------------------------------------------------------
You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

Example 1:


Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2=
It takes 4 minutes for the whole tree to be infected so we return 4.

Example 2:

Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0.
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 105
Each node has a unique value.
A node with a value of start exists in the tree.

GFG -> Burning Tree => Same Problem
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Node {
public:
    int value;
    Node *left;
    Node *right;
    
    // Constructor to initialize a node with a value
    Node(int data){
        value = data;
        left = nullptr;
        right = nullptr;
    }
};

/*
1. Parent Map + BFS (Your Main Solution)
- How it works:
- First, a DFS (helper) traverses the tree to:
  - Build a map from each node to its parent.
  - Find the node with the target value.
- Then, a BFS starts from the target node and spreads the infection to left, right, and parent nodes, tracking time.

- Data Structures:
  - unordered_map<Node*, Node*> parent (maps child to parent)
  - unordered_set<Node*> visited for tracking visited nodes
  - queue<pair<Node*, int>> for BFS

- Traversal:
  - DFS to build parent map and find target.
  - BFS to simulate infection.

- Node Reference:
  - Works with Node pointers directly.
*/

// Helper DFS to fill parent map and find target node --> Level order Traversal
Node* helper(Node *root, int target, unordered_map<Node*, Node*>& parent) {
    // Base case: if the node is null, return null
    if (!root) return nullptr;

    // If the left child exists, set its parent to the current node
    if (root->left){ 
        parent[root->left] = root;
    }

    // If the right child exists, set its parent to the current node
    if (root->right){
        parent[root->right] = root;
    }

    // If the current node's value matches the target, return the node
    if (root->value == target){
        return root;
    }

    // Recursively search in the left subtrees
    Node* left = helper(root->left, target, parent);

    // If the target is found in the left subtree, return it
    if (left) return left;

    // Otherwise, recursively search in the right subtree
    return helper(root->right, target, parent);
}

// This function uses BFS to traverse the tree and calculate the time taken to infect all nodes
int amountOfTime(Node *root, int start){

    // Map to store parent pointers and <Node*, Node*> -> <child, parent>
    unordered_map<Node*, Node*> parent;

    // Finding the target node and fill the parent map
    Node* targetNode = helper(root, start, parent);

    // If the target node is not found, return 0
    if (!targetNode) return 0;

    // Queue to perform BFS and pair -> <Node*, level>
    queue<pair<Node*, int>> qu;

    // Starting BFS from the target node at level 0
    qu.push({targetNode, 0});

    // Set to keep track of visited nodes to avoid cycles and reprocessing
    unordered_set<Node *> visited;

    // Mark the target node as visited
    visited.insert(targetNode);
    
    // Variable to keep track of the maximum time taken to infect the tree
    int time = 0;

    // While there are nodes to process in the queue
    while (!qu.empty()){

        // Get the front node and its level from the queue and <Node*, int> -> <Node*, level>
        pair<Node*, int> front = qu.front();
        // auto front = qu.front(); // Get the front node and its level from the queue -----> <Node*, int> -> <Node*, level> This line is also correct
        
        qu.pop(); // Remove the front node from the queue
        
        Node *node = front.first; // Get the current node from the front pair
        int level = front.second; // Get the level of the current node from the front pair
        
        time = max(time, level); // Update the maximum time taken to infect the tree

        // If the left child exists and is not visited
        if (node->left && visited.find(node->left) == visited.end()){
            qu.push({node->left, level + 1}); // Push the left child into the queue with incremented level
            visited.insert(node->left); // Mark the left child as visited
        }

        // If the right child exists and is not visited
        if (node->right && visited.find(node->right) == visited.end()){
            qu.push({node->right, level + 1}); // Push the right child into the queue with incremented level
            visited.insert(node->right); // Mark the right child as visited
        }

        // Check if the parent of the current node exists and is not visited
        if (parent.count(node) && visited.find(parent[node]) == visited.end()){
            qu.push({parent[node], level + 1}); // Push the parent node into the queue with incremented level
            visited.insert(parent[node]); // Mark the parent node as visited
        }
    }
    
    return time;
}

/*
2. Graph + BFS Approach
- How it works:
  - First, a DFS (buildGraph) converts the tree into an undirected graph (adjacency list), where each node value is a vertex.
  - Then, a BFS starts from the target value and spreads the infection to all connected nodes, tracking time.
- Data Structures:
    - unordered_map<int, vector<int>> graph (to represent the undirected graph)
    - unordered_set<int> visited (to track visited nodes)
    - queue<int> for BFS
- Traversal:
    - DFS to build the graph.
    - BFS to simulate infection.
- Node Reference:
    - Works with node values (integers), not pointers.

// Note: This approach is less efficient than the first one, as it builds a graph representation of the tree.

============= Graph + BFS Approach =============
// Helper to build undirected graph from tree --> DFS
void buildGraph(Node* node, unordered_map<int, vector<int>>& graph, Node* parent = nullptr) {
    if (!node) return;
    if (parent) {
        graph[node->value].push_back(parent->value);
        graph[parent->value].push_back(node->value);
    }
    buildGraph(node->left, graph, node);
    buildGraph(node->right, graph, node);
}

// This function uses BFS to traverse the graph and calculate the time taken to infect all nodes
int amountOfTime(Node* root, int start) {
    unordered_map<int, vector<int>> graph;
    buildGraph(root, graph);

    unordered_set<int> visited;
    queue<int> q;
    q.push(start);
    visited.insert(start);

    int minutes = -1;
    while (!q.empty()) {
        int sz = q.size();
        minutes++;
        for (int i = 0; i < sz; ++i) {
            int curr = q.front(); q.pop();
            for (int neighbor : graph[curr]) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
    }
    return minutes;
}
*/ 

int main() {
    Node *root = new Node(1);
    root->left = new Node(5);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(10);
    root->right->right = new Node(6);
    root->left->left->left = new Node(9);
    root->left->left->right = new Node(2);

    int start = 3;
    cout << "Time to infect the entire tree: " << amountOfTime(root, start) << " minutes" << endl;

    return 0;
}