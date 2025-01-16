/*
Invert Binary Tree - [Leetcode - (226)]
=====================================================
Given the root of a binary tree, invert the tree, and return its root.

Example 1:

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:

Input: root = [2,1,3]
Output: [2,3,1]

Example 3:

Input: root = []
Output: []
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

node *invertTreeNode(node *root){
    if(root == nullptr) return nullptr;

    // Swapping
    node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursion
    invertTreeNode(root->left);
    invertTreeNode(root->right);
    return root;
}

void display(node *root){
    if(root == nullptr) return;
    cout<<root->value<<" ";
    display(root->left);
    display(root->right);
}
int main(){
    
    node *root = new node(4);
    root->left = new node(2);
    root->right = new node(7);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(9);

    cout<<"Before Inverting: "<<endl;
    display(root);

    cout<<endl<<"After Inverting: "<<endl;
    invertTreeNode(root);
    display(root);

    return 0;
}