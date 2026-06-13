/*
Lowest Common Ancestor of a Binary Tree - [Leetcode - 236(Medium)]
------------------------------------------------------------------------
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 
Constraints:

The number of nodes in the tree is in the range [2, 105].
-10^9 <= Node.val <= 10^9
All Node.val are unique.
p != q
p and q will exist in the tree.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int data){
        value = data;
        left = nullptr;
        right = nullptr;
    }
};

int n; // Total number of nodes in the tree
int cols; // Number of columns needed for binary lifting (log2(n) + 1)

unordered_map<TreeNode*, int> id; // Map to store the unique ID of each node
unordered_map<int, TreeNode*> node; // Map to store the node corresponding to each unique ID

vector<vector<int>> ancestorTable; // 2D vector to store the ancestor table for binary lifting
vector<int> depth; // Vector to store the depth of each node in the tree

int idx = 0; // Index to assign unique IDs to nodes during DFS traversal

// Approach - 1: Recursive DFS
TreeNode* lowestCommonAncestorDFS(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) {
        return root; // If the current node is null or matches p or q, return it
    }

    // Recursively search for p and q in the left and right subtrees
    TreeNode* leftLCA = lowestCommonAncestorDFS(root->left, p, q);
    TreeNode* rightLCA = lowestCommonAncestorDFS(root->right, p, q);

    // If both left and right subtrees return non-null, then root is the LCA
    if (leftLCA != nullptr && rightLCA != nullptr) {
        return root;
    }

    // Otherwise, return the non-null child (either left or right)
    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

// Approach - 2: Binary Lifting
void dfs(TreeNode* root, int parent) {
    if(root == NULL) return;

    int curr = idx++;

    id[root] = curr;
    node[curr] = root;

    ancestorTable[curr][0] = parent;

    if(root->left) {
        depth[idx] = depth[curr] + 1;
        dfs(root->left, curr);
    }

    if(root->right) {
        depth[idx] = depth[curr] + 1;
        dfs(root->right, curr);
    }
}

void buildAncestorTable() {
    for(int j = 1; j < cols; j++) {
        for(int nodeIdx = 0; nodeIdx < n; nodeIdx++) {
            if(ancestorTable[nodeIdx][j-1] != -1) {
                ancestorTable[nodeIdx][j] = ancestorTable[ancestorTable[nodeIdx][j-1]][j-1];
            }
        }
    }
}

int findLCA(int u, int v) {

    if(depth[u] < depth[v]){
        swap(u, v);
    }

    int k = depth[u] - depth[v];

    for(int j = 0; j < cols; j++) {
        if(k & (1 << j)) {
            u = ancestorTable[u][j];
        }
    }

    if(u == v) return u;

    for(int j = cols-1; j >= 0; j--) {
        if(ancestorTable[u][j] == -1) continue;

        if(ancestorTable[u][j] != ancestorTable[v][j]) {
            u = ancestorTable[u][j];
            v = ancestorTable[v][j];
        }
    }
    return ancestorTable[u][0];
}

int countNodes(TreeNode* root) {
    if(root == NULL) return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Step-1: Perform a DFS to assign unique IDs to each node and calculate their depths in the tree.
    // Step-2: Build an ancestor table using binary lifting technique, where ancestorTable[node][j] stores the 2^j-th ancestor of the node.

    // Step-3: To find the LCA of nodes p and q, first equalize their depths by moving up the deeper node using the ancestor table.
    // Step-4: Then, move both nodes up simultaneously until they point to the same node, which will be their LCA.

    n = countNodes(root);
    cols = log2(n) + 1;

    ancestorTable.assign(n, vector<int>(cols, -1));
    depth.assign(n, 0);

    id.clear();
    node.clear();

    idx = 0;
    dfs(root, -1);

    buildAncestorTable();

    int u = id[p];
    int v = id[q];

    int lca = findLCA(u, v);

    return node[lca];
}

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left;   // Node with value 5
    TreeNode* q = root->right;  // Node with value 1

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca != nullptr) {
        cout << "Lowest Common Ancestor of " << p->value<< " and " << q->value<< " is: " << lca->value << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }

    return 0;
}