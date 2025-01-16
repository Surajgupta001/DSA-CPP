/*
Lowest Common Ancestor - [Leetcode - 235(Medium)]
=====================================================
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Example 3:

Input: root = [2,1], p = 2, q = 1
Output: 2
*/ 
#include <iostream>
using namespace std;

class node{
    public:
    int value;
    node* left;
    node* right;

    // constructor
    node(int data){
        value = data;
        left = nullptr;
        right = nullptr;
    }
};

node *insertIntoBST(node *root , int element){
    if(root == nullptr) return new node(element);
    else if(root->value > element){ // go left
        if(root->left == nullptr) /*attch it here*/ root->left = new node(element);
        else insertIntoBST(root->left,element);
    }
    else{ // root->value < element : go right
        if(root->right == nullptr) /*attch it here*/ root->right = new node(element);
        else insertIntoBST(root->right,element);
    }
    return root;
}

void inOrderTraversal(node *root){
    if(root != nullptr){
        inOrderTraversal(root->left);
        cout<<root->value<<" ";
        inOrderTraversal(root->right);
    }
}


node *lowestCommonAnscestor(node *root, node *p, node*q){
    if(root->value < p->value and root->value < q->value) return lowestCommonAnscestor(root->right,p,q);
    else if(root->value > p->value and root->value > q->value) return lowestCommonAnscestor(root->left,p,q);
    else return root;
}

int main(){

    node *root = nullptr;

    root = insertIntoBST(root,6);
    insertIntoBST(root,2);
    insertIntoBST(root,8);
    insertIntoBST(root,0);
    insertIntoBST(root,4);
    insertIntoBST(root,7);
    insertIntoBST(root,9);
    insertIntoBST(root,3);
    insertIntoBST(root,5);

    cout<<"In-Order Traversal of the BST: ";
    inOrderTraversal(root);
    cout<<endl;

    int p,q;
    cout<<"Enter the values of p and q: ";
    cin>>p>>q;
    node *pNode = new node(p);
    node *qNode = new node(q);
    cout<<"The Lowest Common Ancestor of "<<p<<" and "<<q<<" is: "<<lowestCommonAnscestor(root,pNode,qNode)->value<<endl;
    return 0;
}