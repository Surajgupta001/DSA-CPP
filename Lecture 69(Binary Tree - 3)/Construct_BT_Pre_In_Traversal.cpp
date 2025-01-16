/*
Construct Binary Tree from Preorder and Inorder Traversal - [Leetcode - 105(medium)]
=====================================================================================
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
*/ 
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
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

// Pre-Order Traversal with null in vector
void preOrder(node *root, vector<string>& ans){
    if(root == nullptr){
        ans.push_back("N");
        return;
    }
    ans.push_back(to_string(root->value));
    preOrder(root->left, ans);
    preOrder(root->right, ans);
}
// Helper Function
node *build(vector<int>& pre, int preLow, int preHigh, vector<int>& in, int inLow, int inHigh){
    // Base Case
    // If the preorder array is empty   
    if(preLow > preHigh) return nullptr;

    // Create the root node
    node *root = new node(pre[preLow]);

    // If the preorder array has only one element
    if(preLow == preHigh) return root;

    // Find the root node in the inorder array
    int i = inLow;

    // Find the root node in the inorder array
    while(i <= inHigh){
        // If the root node is found
        if(in[i] == pre[preLow]) break;
        i++;
    }
    // Calculate the number of elements in the left subtree and right subtree
    int leftCount = i - inLow;
    int rightCount = inHigh - i;

    // Recursively build the left and right subtrees
    root->left = build(pre, (preLow + 1), (preLow + leftCount), in, inLow, i-1);
    root->right = build(pre, (preLow + leftCount + 1), preHigh, in, i+1, inHigh);
    
    // Return the root node
    return root;
}

node *buildTree(vector<int>& pre, vector<int>& in){
    int n = pre.size();
    return build(pre,0,n-1,in,0,n-1);
}

int main(){

    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    // Build the Binary Tree
    node *root = buildTree(preorder, inorder);

    // Store the Preorder traversal including nulls
    vector<string>result;
    preOrder(root, result);

    // Print the result
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

    return 0;
}