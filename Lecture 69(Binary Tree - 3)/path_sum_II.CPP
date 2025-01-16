/*
Path Sum II - [Leetcode - 113(Medium)]
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

Example 1:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

Example 2:

Input: root = [1,2,3], targetSum = 5
Output: []

Example 3:
Input: root = [1,2], targetSum = 0
Output: []

*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <queue>
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

// Helper Function
void helper(node *root, vector<int> v, vector<vector<int>>& ans, int sum){
    // Base Case
    if(root == nullptr) return;
    // Leaf Node
    if(root->left == nullptr && root->right == nullptr){
        // If the sum is equal to the target sum then add the path to the answer
        if(root->value == sum){
            v.push_back(root->value);
            ans.push_back(v);
        }
        return;
    }
    // Recursion
    v.push_back(root->value);
    // Recursive Call for Left Subtree
    helper(root->left,v,ans,sum-(root->value));
    // Recursive Call for Right Subtree
    helper(root->right,v,ans,sum-(root->value));
}

// Main Function
vector<vector<int>>pathSum(node *root, int targetSum){
    vector<vector<int>> ans;
    vector<int> v;
    helper(root, v, ans, targetSum);
    return ans;
}

int main(){
    
    int arr[] = {5,4,8,11,INT_MIN,13,4,7,2,INT_MIN,INT_MIN,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    node *root = constructTree(arr,n);

    int targetSum;
    cout<<"Enter the target sum: ";
    cin>>targetSum;

    vector<vector<int>> ans = pathSum(root, targetSum);
    cout<<"Paths that sum to "<<targetSum<<": "<<endl;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}