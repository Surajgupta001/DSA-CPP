/*
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
*/ 

#include <iostream>
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

bool existInTree(node *root, node *target){
    if(root == nullptr) return false;
    if(root == target) return true;
    return existInTree(root->left, target) || existInTree(root->right, target);
}

node *lowestCommonAncestor(node *root, node *p, node *q){
    if(existInTree(root->left, p) && existInTree(root->left, q)) return lowestCommonAncestor(root->left, p, q);
    else if(existInTree(root->right, p) && existInTree(root->right, q)) return lowestCommonAncestor(root->right, p, q);
    else return root;
}

int main(){
    // create tree
    node *root = new node(3);
    root->left = new node(5);
    root->right = new node(1);
    root->left->left = new node(6);
    root->left->right = new node(2);
    root->right->left = new node(0);
    root->right->right = new node(8);
    root->left->left->left = nullptr;
    root->left->left->right = nullptr;
    root->left->right->left = new node(7);
    root->left->right->right = new node(4);
    
    node *p = root->left;
    node *q = root->left->right->right;

    node *ans = lowestCommonAncestor(root, p, q);
    cout<<"Lowest Common Ancestor of "<<p->value<<" and "<<q->value<<" is: "<<ans->value<<endl;
    
    return 0;
}
