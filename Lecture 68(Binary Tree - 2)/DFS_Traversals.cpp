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
        left = NULL;
        right = NULL;
    }

};

// Pre-Order Traversals 
void preOrder(node *root){
    // Base Case
    if(root == NULL) return;
    // Displaying the root node
    cout<<root->value<<" ";
    // Displaying the left subtree
    preOrder(root->left); // Left Recursion
    // Displaying the right subtree
    preOrder(root->right); // Right Recursion
}

// In-Order Traversals 
void inOrder(node *root){
    // Base Case
    if(root == NULL) return;
    // Displaying the left subtree
    inOrder(root->left); // Left Recursion
    // Displaying the root node
    cout<<root->value<<" ";
    // Displaying the right subtree
    inOrder(root->right); // Right Recursion
}

// In-Order Traversals 
void postOrder(node *root){
    // Base Case
    if(root == NULL) return;
    // Displaying the left subtree
    postOrder(root->left); // Left Recursion
    // Displaying the right subtree
    postOrder(root->right); // Right Recursion
    // Displaying the root node
    cout<<root->value<<" ";
}

int main(){

    // Creating Tree Node
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    // Pre-Order Traversals 
    cout<<"Pre-Order Traversals are: ";
    preOrder(root);

    // In-Order Traversals 
    cout<<endl<<"In-Order Traversals are: ";
    inOrder(root);

    // Post-Order Traversals 
    cout<<endl<<"Post-Order Traversals are: ";
    postOrder(root);
    
    return 0;
}