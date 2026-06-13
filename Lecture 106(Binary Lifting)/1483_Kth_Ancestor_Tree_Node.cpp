/*
Kth Ancestor of a Tree Node - [Leetcode - 1483(Medium)]
-------------------------------------------------------------
You are given a tree with n nodes numbered from 0 to n - 1 in the form of a parent array parent where parent[i] is the parent of ith node. The root of the tree is node 0. Find the kth ancestor of a given node.

The kth ancestor of a tree node is the kth node in the path from that node to the root node.

Implement the TreeAncestor class:

TreeAncestor(int n, int[] parent) Initializes the object with the number of nodes in the tree and the parent array.
int getKthAncestor(int node, int k) return the kth ancestor of the given node node. If there is no such ancestor, return -1.
 

Example 1:

Input
["TreeAncestor", "getKthAncestor", "getKthAncestor", "getKthAncestor"]
[[7, [-1, 0, 0, 1, 1, 2, 2]], [3, 1], [5, 2], [6, 3]]
Output
[null, 1, 0, -1]

Explanation
TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);
treeAncestor.getKthAncestor(3, 1); // returns 1 which is the parent of 3
treeAncestor.getKthAncestor(5, 2); // returns 0 which is the grandparent of 5
treeAncestor.getKthAncestor(6, 3); // returns -1 because there is no such ancestor
 
Constraints:

1 <= k <= n <= 5 * 10^4
parent.length == n
parent[0] == -1
0 <= parent[i] < n for all 0 < i < n
0 <= node < n
There will be at most 5 * 10^4 queries.
*/ 

/*
=======================================CONCEPTS USED================================================
- Scope Resolution Operator (::): Used to define member functions outside the class definition.
- Binary Lifting: The constructor precomputes an ancestor table to allow O(log k) ancestor retrieval.
- Bit Manipulation: getKthAncestor uses the binary representation of k to jump through the precomputed table.
- Complexity: Precomputation takes O(n log n) time and space; each query takes O(log k) time.
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class TreeAncestor {
public:
    vector<vector<int>> ancestorTable; // 2D vector to store the ancestor table for binary lifting
    int rows; // Number of nodes in the tree
    int cols; // Number of columns needed for binary lifting (log2(n) + 1)

    // Constructor to initialize the ancestor table using binary lifting technique
    TreeAncestor(int n, vector<int>& parent);

    // Function to get the kth ancestor of a node
    int getKthAncestor(int node, int k);
};

TreeAncestor::TreeAncestor(int n, vector<int>& parent) {
    rows = n;
    cols = log2(n) + 1; // Calculate the number of columns needed for binary lifting

    ancestorTable.resize(rows, vector<int>(cols, -1)); // Initialize the ancestor table with -1

    // Fill the first column of the ancestor table with the immidiate parents(ancestors) of each node
    for(int node=0; node<n; node++){
        ancestorTable[node][0] = parent[node];
    }

    // Fill the ancestor table using binary lifting technique
    for(int j=1; j<cols; j++){
        for(int node=0; node<n; node++){
            if(ancestorTable[node][j-1] != -1){ // If the (j-1)th ancestor exists
                ancestorTable[node][j] = ancestorTable[ancestorTable[node][j-1]][j-1]; // Fill the jth column using the (j-1)th column
            }
        }
    }
}
    
int TreeAncestor::getKthAncestor(int node, int k) {
    for(int j=0; j<cols; j++){
        if(k & (1 << j)){ // Check if the jth bit of k is set
            node = ancestorTable[node][j]; // Move to the jth ancestor of the current node
            if(node == -1){ // If there is no such ancestor, return -1
                return -1;
            }
        }
    }
    return node;
}

int main() {
    vector<int> parent = {-1, 0, 0, 1, 1, 2, 2};
    TreeAncestor treeAncestor(7, parent);

    cout << treeAncestor.getKthAncestor(3, 1) << endl; // Output: 1
    cout << treeAncestor.getKthAncestor(5, 2) << endl; // Output: 0
    cout << treeAncestor.getKthAncestor(6, 3) << endl; // Output: -1

    return 0;
}