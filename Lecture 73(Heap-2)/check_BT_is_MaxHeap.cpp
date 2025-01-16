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

// Function to get the size of a binary tree
int sizeOfTree(node *root){
    if(root == nullptr) return 0;
    return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
}

// Function to check if a given binary tree is a Complete Binary Tree (CBT)
bool isCBT(node *root){
    int size = sizeOfTree(root);
    int count = 0;
    queue<node*>qu;
    qu.push(root);
    while(count < size){
        node* temp = qu.front();
        qu.pop();
        count++;
        if(temp != nullptr){
            qu.push(temp->left);
            qu.push(temp->right);
        }
    }
    while(qu.size() > 0){
        node* temp = qu.front();
        if(temp!= nullptr) return false;
        qu.pop();
    }
    return true;
}

// Function to check if a given binary tree is a Max-Heap
bool isMax(node *root){
    if(root == nullptr) return true;
    if(root->left != nullptr && root->value < root->left->value && root->right != nullptr && root->value > root->right->value) return false;
    return isMax(root->left) && isMax(root->right);
}

int main(){

    node *root = new node(20);
    root->left = new node(15);
    root->right = new node(10);
    root->left->left = new node(8);
    root->left->right = new node(11);
    root->right->left = new node(6);;
    root->right->right = nullptr;

    if(isCBT(root) && isMax(root)) cout<<"Binary Tree is Max-Heap.";
    else cout<<"Binary Tree is not a Max-Heap."<<endl;

    return 0;
}