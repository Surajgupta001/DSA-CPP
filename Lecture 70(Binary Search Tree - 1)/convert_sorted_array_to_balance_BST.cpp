/*
Converted Sorted Array to Balanced BST - [Leetcode - 108(Easy)]
================================================================================================
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

Example 1:

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
*/ 

#include <iostream>
#include <vector>
using namespace std;

class node {
public:
    int value;
    node* left;
    node* right;

    // Constructor
    node(int data) {
        value = data;
        left = nullptr;
        right = nullptr;
    }
};

node* insertIntoBST(node* root, int element) {
    if (root == nullptr) return new node(element);
    else if (root->value > element) { // go left
        if (root->left == nullptr) // attach it here
            root->left = new node(element);
        else
            insertIntoBST(root->left, element);
    } else { // root->value < element : go right
        if (root->right == nullptr) // attach it here
            root->right = new node(element);
        else
            insertIntoBST(root->right, element);
    }
    return root;
}

void inOrderTraversal(node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left); // Visit left subtree first
        cout << root->value << " ";    // Visit the root
        inOrderTraversal(root->right); // Visit right subtree
    }
}

node* helper(vector<int>& v, int low, int high){
    if (low > high) return nullptr;
    int mid = low + (high - low) / 2;
    // Calculate the middle index to ensure the tree is balanced
    node* root = new node(v[mid]);
    root->left = helper(v, low, mid - 1);
    root->right = helper(v, mid + 1, high);
    return root;
}

node* sortedArrayToBST(vector<int>& v) {
    int n = v.size();
    return helper(v, 0, n - 1);
}

int main(){

    int arr[] = {-10,-3,0,5,9};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int>v(arr, arr + n);
    node* root = sortedArrayToBST(v);

    cout<<"Balanced Binary Search Tree (In-Order Traversal): ";
    inOrderTraversal(root);
    cout<<endl;

    return 0;
}