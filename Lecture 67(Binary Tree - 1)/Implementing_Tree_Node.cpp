/*
Implementing Tree nodes
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
        left = NULL;
        right = NULL;
    }

};

// Displaying the tree
void display(node *root){
    if(root == NULL){
        return;
    }
    // Displaying the root node
    cout<<root->value<<" ";
    // Displaying the left subtree
    display(root->left); // Left Recursion
    // Displaying the right subtree
    display(root->right); // Right Recursion
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
    display(a);

    return 0;
}