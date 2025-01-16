/*
Binary Tree Path - [Leetcode - 257(Easy)]
=============================================
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

Example 1:

Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Example 2:

Input: root = [1]
Output: ["1"]
*/ 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class node{
    public:
    int value;
    node *left;
    node *right;

    // constructor
    node(int data){
        value = data;
        left = nullptr;
        right = nullptr;
    }
};

void helper(node *root, string str, vector<string>& ans){
    // Base Case
    if(root == nullptr) return;

    string a = to_string(root->value);

    // Checking for leaf Node => Important
    if(root->left == nullptr && root->right == nullptr){
        str = str + a;
        ans.push_back(str);
        return;
    }
    // Recursion
    helper(root->left, str+a+"->", ans);
    helper(root->right, str+a+"->", ans);
}
vector<string>binaryTreePath(node *root){
    vector<string>ans;
    helper(root,"",ans);
    return ans;
}

int main(){

    // Creating a Binary Tree
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = nullptr;
    root->left->right = new node(5);

    // Printing the Binary Tree Path
    vector<string>ans = binaryTreePath(root);

    cout<<"Binary Tree Paths are: "<<endl;
    for(auto it:ans){
        cout<<it<<endl;
    }
    cout<<endl;

    return 0;
}