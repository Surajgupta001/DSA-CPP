/*
Path Sum III - [Leetcode - 437(Medium)]
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

Example 1:

Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.

Example 2:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
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
void helper(node *root, long long sum, int &count){
    if(root == nullptr) return;
    if((long long)root->value == sum) count++;
    helper(root->left, sum-(long long)(root->value), count);
    helper(root->right, sum-(long long)(root->value), count);
}

int pathSum(node *root, int targetSum){ // to add the sums of every nodepath
    if(root == nullptr) return 0;
    int count = 0;
    helper(root,(long long)targetSum,count);
    count += (pathSum(root->left,targetSum) + pathSum(root->right,targetSum));
    return count;
}

int main(){
    int arr[] = {10,5,-3,3,2,INT_MIN,11,3,-2,INT_MIN,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    node *root = constructTree(arr,n);

    int targetSum;
    cout<<"Enter the target sum: ";
    cin>>targetSum;

    cout<<"Number of paths that sum to "<<targetSum<<": "<<pathSum(root,targetSum);
    return 0;
}