/*
Construct Binary Search Tree From PreOrder Traversal - [Leetcode - 1008(Medium)]
=========================================================================================
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.


Example 1:

Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Example 2:

Input: preorder = [1,3]
Output: [1,null,3]
*/ 
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> // Include for queue in level-order traversal

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

node *insertIntoBST(node *root, int element) {
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

// Helper Function
node *build(vector<int>& pre, int preLow, int preHigh, vector<int>& in, int inLow, int inHigh) {
    if (preLow > preHigh) return nullptr;
    node *root = new node(pre[preLow]);
    if (preLow == preHigh) return root;
    int i = inLow;
    while (i <= inHigh) {
        if (in[i] == pre[preLow]) break;
        i++;
    }
    int leftCount = i - inLow;
    int rightCount = inHigh - i;
    root->left = build(pre, preLow + 1, preLow + leftCount, in, inLow, i - 1);
    root->right = build(pre, preLow + leftCount + 1, preHigh, in, i + 1, inHigh);
    return root;
}

node *bstFromPreorder(vector<int>& pre) {
    vector<int> in = pre; // Copy
    sort(in.begin(), in.end());
    int n = pre.size();
    return build(pre, 0, n - 1, in, 0, n - 1);
}

// ==================================================================================>
// Function to construct a binary search tree from a given preorder traversal
node *bstFromPreorder1(vector<int>& pre) {
    node *root = new node(pre[0]); // Correctly initialize the root node
    for (int i = 1; i < pre.size(); i++) {
        insertIntoBST(root, pre[i]);
    }
    return root;
}
// =====================================================================================>

int main(){

    vector<int> pre = {8,5,1,7,10,12};
    node *root = bstFromPreorder(pre);
    cout<<"Construction BST From PreOrder Traversal: ";
    levelOrderQueue(root);
    
    cout<<"===========2nd Approch ====================="<<endl;

    node *root1 = bstFromPreorder1(pre);
    cout<<"Construction BST From PreOrder Traversal: ";
    levelOrderQueue(root);

    return 0;
}