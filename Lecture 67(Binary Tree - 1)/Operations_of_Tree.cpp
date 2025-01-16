/*
Some Operations On Tree Node
*/ 

#include <iostream>
#include <algorithm>
#include <limits.h>
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

// Displaying the tree
void display(node *root){
    if(root == nullptr){
        return;
    }
    // Displaying the root node
    cout<<root->value<<" ";
    // Displaying the left subtree
    display(root->left); // Left Recursion
    // Displaying the right subtree
    display(root->right); // Right Recursion
} 

// Sum of Tree Nodes
int sum(node *root){
    // Base Case
    if(root == nullptr) return 0;
    // Recursion
    return root->value + sum(root->left) + sum(root->right);
}

// Product Of Tree Node
int product(node *root){
    // Base Case
    if(root == nullptr) return 1;
    // Recursion
    return root->value * product(root->left) * product(root->right);
}

// Size of Tree Node
int size(node *root){
    // Base Case
    if(root == nullptr) return 0;
    // Recursion
    return 1 + size(root->left) + size(root->right);
}

// Maximum Value in a Tree Node
int maxInTree(node *root){
    // Base Case
    if(root == nullptr) return INT_MIN; 
    // Recursion
    int Lmax = maxInTree(root->left);
    int Rmax = maxInTree(root->right);
    return max(root->value, max(Lmax,Rmax));
}

// Minimum value in a Tree Node
int minInTree(node *root){
    // Base Case
    if(root == nullptr) return INT_MAX;
    // Recursion
    int Lmin = maxInTree(root->left);
    int Rmin = maxInTree(root->right);
    return min(root->value, max(Lmin,Rmin));
}

// Levels of Tree Node
int levels(node *root){
    // Base Case
    if(root == nullptr) return 0;
    // Recursion
    return 1 + max(levels(root->left), levels(root->right));
}

// Heights of Tree Node
int height(node *root){
    return levels(root) - 1;
}

int main(){
    // Implementing Tree
    node* a = new node(1); // root
    node* b = new node(2);
    node* c = new node(3);
    node* d = new node(4);
    node* e = new node(5);
    node* f = new node(6);
    node* g = new node(7);

    // Linking the nodes
    // Root Node
    a->left = b;
    a->right = c;
    // 2nd Level
    b->left = d;
    b->right = e;
    // 3rd Level
    c->left = f;
    c->right = g;

    // Displaying the tree
    cout<<"Implementing Tree Node: ";
    display(a);

    cout<<endl<<"Sum Of Tree Nodes are: "<<sum(a)<<endl;

    cout<<"Product Of Tree Nodes are: "<<product(a)<<endl;

    cout<<"Size of Tree Nodes are: "<<size(a)<<endl;

    cout<<"Maximum value in Tree Node is: "<<maxInTree(a)<<endl;

    cout<<"Minimum value in Tree Node is: "<<minInTree(a)<<endl;

    cout<<"Levels of Tree Nodes: "<<levels(a)<<endl;

    cout<<"Height of Tree Node: "<<height(a)<<endl;
    
    return 0;
}