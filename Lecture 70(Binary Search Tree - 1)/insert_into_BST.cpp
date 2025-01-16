/*
You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

Example 1:


Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
Explanation: Another accepted tree is:

Example 2:

Input: root = [40,20,60,10,30,50,70], val = 25
Output: [40,20,60,10,30,50,70,null,null,25]
Example 3:

Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
Output: [4,2,7,1,3,5]

*/ 
#include <iostream>
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

int main(){

    node *root = nullptr;

    root = insertIntoBST(root,40);
    insertIntoBST(root,20);
    insertIntoBST(root,60);
    insertIntoBST(root,10);
    insertIntoBST(root,30);
    insertIntoBST(root,50);
    insertIntoBST(root,70);

    cout<<"In-Order Traversal of the BST: ";
    inOrderTraversal(root);
    cout<<endl;

    int element;
    cout<<"Enter the elemnt u want insert: ";
    cin>>element;

    node *result = insertIntoBST(root,element);
    cout<<"In-Order Traversal of the BST after insertion: ";
    inOrderTraversal(result);
    cout<<endl;

}