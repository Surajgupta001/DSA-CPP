/*
Lowest Common Ancestor of Deepest Leaves - [Leetcode - 1123(Medium)]
====================================================================
Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:

The node of a binary tree is a leaf if and only if it has no children
The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.
 

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest leaf-nodes of the tree.
Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.

Example 2:

Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree, and it's the lca of itself.

Example 3:

Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest leaf node in the tree is 2, the lca of one node is itself.
 

Constraints:

The number of nodes in the tree will be in the range [1, 1000].
0 <= Node.val <= 1000
The values of the nodes in the tree are unique.
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