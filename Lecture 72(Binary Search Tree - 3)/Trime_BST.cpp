/*
Trim A Binary Search Tree - [Leetcode-669(Medium)]
=============================================
Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high]. Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). It can be proven that there is a unique answer.

Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.

Example 1:

Input: root = [1,0,2], low = 1, high = 2
Output: [1,null,2]

Example 2:

Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
Output: [3,2,null,1]
*/ 
#include <iostream>
#include <climits>
#include <queue>
using namespace std;

class node{
    public:

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

// Level Order Traversal Using Queue(BFS)
void levelOrderQueue(node *root){
    if(root == NULL) return;
    queue<node*>qu;
    qu.push(root);
    while(qu.size() > 0){
        // temp is the current node
        node *temp = qu.front();
        qu.pop();
        cout<<temp->value<<" ";
        // if the left child is not null then push it to the queue
        if(temp->left != nullptr) qu.push(temp->left);
        // if the right child is not null then push it to the queue
        if(temp->right != nullptr) qu.push(temp->right);
    }
    cout<<endl;
}
// ==================================================================================== Leetcode ==>
// void trim(node *root, int low, int high){
//     if (root == nullptr) return;
//     while(root->left != nullptr){
//         if (root->left->value < low) root = root->left->right;
//         else if(root->left->value > high) root->left = root->left->left;
//         else break;
//     }
//     while(root->right != nullptr){
//         if (root->right->value > high) root->right = root->right->left;
//         else if(root->right->value < low) root->right = root->right->right;
//         else break;
//     }
//     trim(root->left,low,high);
//     trim(root->right,low,high);
// }

// node *trimBST(node *root, int low, int high){
//     node *dummy = new node(INT_MAX);
//     dummy->left = root;
//     trim(dummy,low,high);
//     return dummy->left;
// }
// =======================================================================================>

node* trim(node *root, int low, int high) {
    if (root == nullptr) return nullptr;

    // First, trim the left and right subtrees
    root->left = trim(root->left, low, high);
    root->right = trim(root->right, low, high);

    // Now decide whether to keep the current node
    if (root->value < low) {
        // If the current node's value is less than low, return the right subtree
        return root->right;
    }
    if (root->value > high) {
        // If the current node's value is greater than high, return the left subtree
        return root->left;
    }
    // Otherwise, return the current node
    return root;
}
node *trimBST(node *root, int low, int high) {
    return trim(root, low, high);
}
int main(){

    node *root = nullptr;
    root = insertIntoBST(root, 3);
    root = insertIntoBST(root, 0);
    root = insertIntoBST(root, 4);
    root = insertIntoBST(root, 2);
    root = insertIntoBST(root, 1);
    
    cout<<"Before Trimming: "<<endl;
    levelOrderQueue(root);
    
    root = trimBST(root, 1, 3);
    
    cout<<"After Trimming: "<<endl;
    levelOrderQueue(root);
    
    return 0;
}