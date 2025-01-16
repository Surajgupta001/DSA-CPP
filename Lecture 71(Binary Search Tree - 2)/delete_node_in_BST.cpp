/*
Delete Node in a BST - [Leetcode - 450(Medium)]
=================================================
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

1. Search for a node to remove.
2. If the node is found, delete the node.
 

Example 1:

Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.

Example 3:

Input: root = [], key = 0
Output: []
*/ 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node{
    public:
    int value;
    node* left;
    node* right;

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

void inOrderTraversal(node *root){
    if(root != nullptr){
        inOrderTraversal(root->left);
        cout<<root->value<<" ";
        inOrderTraversal(root->right);
    }
}

node* inorderP(node *root){
    node *pred = root->left;
    while(pred->right != nullptr) pred = pred->right;
    return pred;
}

node* inorderS(node *root){
    node *suc = root->right;
    while(suc->left != nullptr) suc = suc->left;
    return suc;
}

node *deleteNode(node *root, int key){
    if(root == nullptr) return root;
    if(root->value == key){
        // CASE 1: No Child Node
        if(root->left == nullptr && root->right == nullptr) return nullptr;

        // CASE 2: 1 Child Node
        if(root->left == nullptr or root->right == nullptr){
            if(root->left != nullptr) return root->left;
            else return root->right;
        }

        // CASE 3: 2 Child Node
        if(root->left != nullptr && root->right != nullptr){
            // replace the root with its inorder Predecessor/Successor
            // After replacing delete the Predecessor/Successor
            node *pred = inorderP(root);
            root->value = pred->value;
            root->left = deleteNode(root->left,pred->value);
        }
    }
    else if(root->value > key){ // go left
        root->left = deleteNode(root->left,key);
    }
    else{ // root->value < key : go right
        root->right = deleteNode(root->right,key);
    }
    return root;
}

int main(){

    node *root = nullptr;

    root = insertIntoBST(root,5);
    insertIntoBST(root,3);
    insertIntoBST(root,6);
    insertIntoBST(root,2);
    insertIntoBST(root,4);
    insertIntoBST(root,7);

    cout<<"Original Binary Search Tree: ";
    inOrderTraversal(root);
    cout<<endl;

    int key;
    cout<<"Enter the key to be deleted: ";
    cin>>key;
    root = deleteNode(root,key);

    cout<<"Binary Search Tree "<<key<<": ";
    inOrderTraversal(root);
    cout<<endl;

    return 0;
}