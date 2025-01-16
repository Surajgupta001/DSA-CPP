/*
Binary Tree InOrder Traversal - [Leetcode - 94(Easy)]
===========================================================
Given the root of a binary tree, return the Inorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]

Output: [1,3,2]

Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,2,6,5,7,1,3,9,8]

Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <limits.h>
using namespace std;

class node {
public:
    int value;
    node *left;
    node *right;

    // Constructor
    node(int data) {
        value = data;
        left = nullptr;
        right = nullptr;
    }
};

// Constructing Tree
node *constructTree(int arr[], int n){ // n = size of array
    queue<node*>qu;
    node *root = new node(arr[0]);
    qu.push(root);

    // i and j are index numbers
    int i = 1; // index number
    int j = 1; // index number
    while(qu.size() > 0 && i < n){
        node *temp = qu.front();
        qu.pop();

        // Create left and right child
        node *left_Child; // left child
        node *right_Child; // right child

        // if the value is not INT_MIN then create a new node
        if(arr[i] != INT_MIN) left_Child = new node(arr[i]);
        else left_Child = nullptr;

        // if the value is not INT_MIN then create a new node
        if(j != n && arr[j] != INT_MIN) right_Child = new node(arr[j]);
        else right_Child = nullptr;

        // assign the left and right child to the current node
        temp->left = left_Child;
        temp->right = right_Child;

        // if the left child is not null then push it to the queue
        if(left_Child != nullptr) qu.push(left_Child);
        if(right_Child != nullptr) qu.push(right_Child);
        
        i = i + 2; // increment index by 2
        j = j + 2; // increment index by 2
    }
    return root;
}

// In-Order Traversal (Iterative)
vector<int>inOrderIterative(node *root){
    vector<int>ans;
    stack<node*>st;
    node *node = root;
    while(node != nullptr || st.size() > 0){
        if(node != nullptr){
            st.push(node);
            node = node->left;
        }
        else{ // node is null
            node *temp = st.top(); 
            st.pop();
            ans.push_back(temp->value);
            node = temp->right;
        }
    }
    return ans;
}

int main(){

    int arr[] = {1,2,3,4,5,INT_MIN,8,INT_MIN,INT_MIN,6,7,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    node *root = constructTree(arr,n);

    vector<int> ans = inOrderIterative(root);
    cout << "In-order traversal of the binary tree: ";
    for (int i=0; i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    
    cout<<endl;
}

