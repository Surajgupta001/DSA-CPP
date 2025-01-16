/*
Same Tree - [Leetcode - 100(Easy)]
=====================================
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:

Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:

Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:

Input: p = [1,2,1], q = [1,1,2]
Output: false
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

bool isSameTree(node* p, node *q){
    // base case
    if(p == nullptr && q == nullptr) return true;
    if(p == nullptr || q == nullptr) return false;

    // Recursion
    if(p->value != q->value) return false;

    bool leftSubAns = isSameTree(p->left , q->left);
    if(leftSubAns == false) return false;

    bool rightSubAns = isSameTree(p->right , q->right);
    if(rightSubAns == false) return false;

    return true;
}

int main(){

    // Creating the first tree
    node* root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);

    // creating the second tree
    node* root2 = new node(1);
    root2->left = new node(2);
    root2->right = new node(3);

    cout<<isSameTree(root1, root2)<<endl;
    
    return 0;
}