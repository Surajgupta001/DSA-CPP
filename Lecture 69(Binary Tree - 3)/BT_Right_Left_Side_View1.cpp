/*
Binary Tree Right Side View - [Leetcode - 199(Medium)]
===========================================================
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
*/ 
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace std;

class node{
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


// Constructing Tree
node *constructTree(int arr[], int n){ // n = size of array
    queue<node*>qu;
    node *root = new node(arr[0]);
    qu.push(root);

    // i and j are index numbers
    int i = 1; // index number
    int j = 2; // index number
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

int levels(node *root){
    if(root == nullptr) return 0;
    return 1 + max(levels(root->left), levels(root->right));
}
// PreOrder for Right side View of Binary Tree
void preOrderRight(node *root, vector<int>& ans, int levels){
    if(root == nullptr) return;
    ans[levels] = root->value;
    preOrderRight(root->left,ans,levels+1);
    preOrderRight(root->right,ans,levels+1);
}

// Right side View of Binary Tree
vector<int>rightSideView(node *root){
    vector<int>ans(levels(root),0);
    preOrderRight(root,ans,0);
    return ans;
}

// PreOrder for Left side View of Binary Tree
void preOrderLeft(node *root, vector<int>& ans, int levels){
    if(root == nullptr) return;
    if(ans[levels] == 0) ans[levels] = root->value;
    preOrderLeft(root->left,ans,levels+1);
    preOrderLeft(root->right,ans,levels+1);
}

// Right side View of Binary Tree
vector<int>leftSideView(node *root){
    vector<int>ans(levels(root),0);
    preOrderLeft(root,ans,0);
    return ans;
}

int main(){

    // Create a binary tree
    int arr[] = {1,2,3,INT_MIN,5,INT_MIN,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    node *root = constructTree(arr,n);

    vector<int>ansR = rightSideView(root);
    cout<<"Right side view of Binary Tree: ";
    for(int i=0;i<ansR.size();i++){
        cout<<ansR[i]<<" ";
    }
    cout<<endl;

    vector<int>ansL = leftSideView(root);
    cout<<"Left side view of Binary Tree: ";
    for(int i=0;i<ansL.size();i++){
        cout<<ansL[i]<<" ";
    }

    return 0;
}