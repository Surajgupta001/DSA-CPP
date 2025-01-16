/*
Diameter of Binary Tree - [Leetcode - 543(Easy)]
=====================================================
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree.This path may or may not pass through the root. If the tree is empty, return 0

The Length of  a path between two node id represented by the number of edge between them.

Example 1:

Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:

Input: root = [1,2]
Output: 1
*/ 

#include <iostream>
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

// Function to calculate the level of the tree
int levels(node *root){
    if(root == nullptr) return 0;
    return 1 + max(levels(root->left), levels(root->right));
}
// Function to calculate the diameter of the tree
void helper(node *root , int &maxDia){
    if(root == nullptr) return;
    int dia = levels(root->left) + levels(root->right);
    maxDia = max(maxDia, dia);
    helper(root->left, maxDia);
    helper(root->right, maxDia);
}
// Function to calculate the diameter of the tree
int diameterOfBinaryTree(node *root){
    int maxDia = 0;
    helper(root, maxDia);
    return maxDia;
}

int main(){
    
    // Creating the tree
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    cout<<"Diameter of Tree is: "<<diameterOfBinaryTree(root)<<endl;

    return 0;
}