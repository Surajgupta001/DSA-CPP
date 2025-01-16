#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_map>
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

node *constructTree(int arr[], int n) { // n = size of array
    queue<node*> qu;
    node *root = new node(arr[0]);
    qu.push(root);

    // i and j are index numbers
    int i = 1; // index number
    int j = 2; // index number
    while (qu.size() > 0 && i < n) {
        node *temp = qu.front();
        qu.pop();

        // Create left and right child
        node *left_Child; // left child
        node *right_Child; // right child

        // if the value is not INT_MIN then create a new node
        if (arr[i] != INT_MIN) left_Child = new node(arr[i]);
        else left_Child = nullptr;

        // if the value is not INT_MIN then create a new node
        if (j != n && arr[j] != INT_MIN) right_Child = new node(arr[j]);
        else right_Child = nullptr;

        // assign the left and right child to the current node
        temp->left = left_Child;
        temp->right = right_Child;

        // if the left child is not null then push it to the queue
        if (left_Child != nullptr) qu.push(left_Child);
        if (right_Child != nullptr) qu.push(right_Child);
        
        i = i + 2; // increment index by 2
        j = j + 2; // increment index by 2
    }
    return root;
}

void topView(node *root){
    unordered_map<int,int>m; // Map to store <level,root->value>
    queue<pair<node*,int>>qu; // Queue to store <node,level>
    pair<node*,int>r; // Pair to hold node & its level
    r.first = root; // first element of the pair to the root node
    r.second = 0; // initial level to 0
    qu.push(r); // push the root node & its level onto the queue

    // Level Order Traversal to determine the top view
    while(qu.size() > 0){
        node *temp = (qu.front()).first; // Node form thr front of the Queue
        int  level = (qu.front()).second; // Corresponding level
        qu.pop(); // Remove the front element from the queue

        // If this level is not yet recorded in the map, record the node's value
        if(m.find(level) == m.end()) m[level] = temp->value;
        if(temp->left != nullptr){
            pair<node*,int>p; // Pair of Left Child
            p.first = temp->left; // Left Child
            p.second = level - 1; // level for the left child
            qu.push(p); // Push the left child onto the queue
        }

        if(temp->right != nullptr){
            pair<node*,int>p; // Pair of Right Child
            p.first = temp->right; // Right Child
            p.second = level + 1; // Level of the Right Child
            qu.push(p); // Push the Right child onto the queue
        }
    }

    int minVerticalLevel = INT_MAX;
    int maxVerticalLevel = INT_MIN;
    for(auto itr = m.begin(); itr != m.end(); itr++){
        minVerticalLevel = min(minVerticalLevel, itr->first);
        maxVerticalLevel = max(maxVerticalLevel, itr->first);
    }

    cout<<"Top View Of Binary Tree: ";
    for(int i = minVerticalLevel; i <= maxVerticalLevel; i++) cout<<m[i]<<" ";

    /*
    // Print the top view by iterating through the map
    for(auto itr = m.begin(); itr != m.end(); itr++) {
        cout<<itr->second<< " "; // Print the node values in the order they were first encountered
    }
    */ 
}


int main() {
    // Example usage:
    int arr[] = {1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8}; // INT_MIN represents null
    int n = sizeof(arr) / sizeof(arr[0]);
    node *root = constructTree(arr,n);

    topView(root);

    return 0;
}