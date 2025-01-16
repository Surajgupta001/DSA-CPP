/*
Binary Search Tree to Greater Sum Tree - [Leetcode - 1038(Medium)]
===========================================================
Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

Example 2:

Input: root = [0,null,1]
Output: [1,null,1]
*/ 
#include <iostream>
#include <algorithm>
#include <limits.h>
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

    int sum = 0;
void reverseInorder(node *root){  
    if(root == nullptr) return;
    reverseInorder(root->right);
    root->value += sum;
    sum = root->value;
    reverseInorder(root->left);
}
node *bstToGst(node *root){
    reverseInorder(root);
    return root;
}

int main(){

    node *root = nullptr;

    root = insertIntoBST(root,4);
    insertIntoBST(root,1);
    insertIntoBST(root,6);
    insertIntoBST(root,0);
    insertIntoBST(root,2);
    insertIntoBST(root,5);
    insertIntoBST(root,7);
    insertIntoBST(root,3);
    insertIntoBST(root,8);

    cout<<"In-Order Traversal of the BST: ";
    inOrderTraversal(root);
    cout<<endl;

    bstToGst(root);
    cout<<"In-Order Traversal of the GST: ";
    inOrderTraversal(root);
    cout<<endl;


    return 0;
}