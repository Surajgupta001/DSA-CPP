/*
Given the root of a binary tree, the depth of each node is the shortest distance to the root.

Return the smallest subtree such that it contains all the deepest nodes in the original tree.

A node is called the deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest nodes of the tree.
Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.

Example 2:

Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree.
Example 3:

Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest node in the tree is 2, the valid subtrees are the subtrees of nodes 2, 1 and 0 but the subtree of node 2 is the smallest.
 

Constraints:

The number of nodes in the tree will be in the range [1, 500].
0 <= Node.val <= 500
The values of the nodes in the tree are unique.Smallest Subtree with all the Deepest Nodes - [Leetcode - 865(Medium)]
*/ 

#include <iostream>
#include <unordered_map>
using namespace std;

class node{
    public:
    int value;
    node *left;
    node *right;

    // Constructor
    node(int data){
        value = data;
        left = nullptr;
        right = nullptr;
    }
};

unordered_map<int, int> mp;

int maxDepth = 0;

node *LCA(node *root){
    if (root == NULL || mp[root->value] == maxDepth) return root;

    node *left = LCA(root->left);
    node *right = LCA(root->right);

    if (left && right) return root;

    return left != NULL ? left : right;
}

void depth(node *root, int d){
    if (!root) return;

    maxDepth = max(maxDepth, d);
    mp[root->value] = d;
    depth(root->left, d + 1);
    depth(root->right, d + 1);
}

// T.C : O(n)
// S.C : O(maxDepth) system recursion stack space
node *lcaDeepestLeaves(node *root){
    depth(root, 0);
    return LCA(root);
}

/*
========== Effiecient Approche ============
pair<int, node*> solve(node* root) {
    if(root == NULL) return {0, NULL};

    auto left = solve(root->left);
    auto right = solve(root->right);

    if(left.first == right.first) return {left.first+1, root};
    else if(left.first > right.first) return {left.first+1, left.second};
    else  return {right.first+1, right.second};
}

node* lcaDeepestLeaves(node* root) {
    return solve(root).second;   
}
*/ 

int main(){
    // Create a binary tree
    node *root = new node(3);
    root->left = new node(5);
    root->right = new node(1);
    root->left->left = new node(6);
    root->left->right = new node(2);
    root->right->left = new node(0);
    root->right->right = new node(8);
    root->left->right->left = new node(7);
    root->left->right->right = new node(4);

    // Find the lowest common ancestor of its deepest leaves
    node *lca = lcaDeepestLeaves(root);

    // Print the value of the lowest common ancestor
    cout << "The lowest common ancestor of its deepest leaves is: " << lca->value << endl;

    // Print the values of its children
    cout << "The values of its children are: ";
    if (lca->left) cout << lca->left->value << " ";
    if (lca->right) cout << lca->right->value << " "<<endl;

    return 0;
}