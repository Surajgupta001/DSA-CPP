/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

Input: root = [2,1,3]
Output: true

Example 2:

Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/ 
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
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

void inOrderTraversal(node *root){
    if(root != nullptr){
        inOrderTraversal(root->left);
        cout<<root->value<<" ";
        inOrderTraversal(root->right);
    }
}

/*
LEETCODE
long long maxTree(node *root){
    if(root == nullptr) return LLONG_MIN;
    return max((long long)(root->value),max(maxTree(root->left),maxTree(root->right)));
}

long long minTree(node *root){
    if(root == nullptr) return LLONG_MAX;
    return min((long long)(root->value),min(minTree(root->left),minTree(root->right)));
}

bool isValidBST(node *root){
    if(root == nullptr) return true;
    else if((long long)(root->value) <= maxTree(root->left)) return false;
    else if((long long)(root->value) >= maxTree(root->right)) return false;
    return isValidBST(root->left) && isValidBST(root->right);
}
*/

bool isValidBSTHelper(node* root, long long min, long long max) {
    if (root == nullptr) return true;
    if ((long long)root->value <= min || (long long)root->value >= max) return false;
    return (isValidBSTHelper(root->left, min, root->value)) && (isValidBSTHelper(root->right, root->value, max));
}

bool isValidBST(node* root) {
    return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
}

// ======================================================>
// next One Solution
void inOrder1(node *root, node *&prev, bool &flag){
    if(root = nullptr) return;
    inOrder1(root->left, prev, flag);
    if(prev != nullptr){
        if(root->value <= prev->value){
            flag = false;
            return;
        }
    }
    prev = root;
    inOrder1(root->right, prev, flag);
}
bool isValidBST1(node *root){
    node *prev = nullptr;
    bool flag = true;
    inOrder1(root, prev, flag);
    return flag;
}
// ========================================================>

int main(){
    
    node *root = new node(2);
    root->left = new node(1);
    root->right = new node(3);

    cout<<"In-Order Traversal of the BST: ";
    inOrderTraversal(root);
    cout<<endl;

    cout<<"Is the given BST a valid BST? "<<(isValidBST(root) ? "Yes" : "No")<<endl;
    
    node *root1 = new node(5);
    root1->left = new node(1);
    root1->right = new node(4);
    root1->right->left = new node(3);
    root1->right->right = new node(6);

    cout<<"In-Order Traversal of the BST: ";
    inOrderTraversal(root1);
    cout<<endl;

    cout<<"Is the given BST a valid BST? "<<(isValidBST(root1) ? "Yes" : "No")<<endl;
    
    return 0;
}