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

// Reverse Inorder Traversal (Right Root Left)
void reverseInorder(node *root, vector<int>& v){
    if(root == nullptr) return;
    reverseInorder(root->right,v);
    v.push_back(root->value);
    reverseInorder(root->left,v);
}

// Preorder Traversal (Root Left Right)
void preorder(node *root, vector<int>& v, int &i){
    if(root == nullptr) return;
    root->value = v[i++]; // store the current node's value and increment the index
    preorder(root->left,v,i);
    preorder(root->right,v,i);
}

// Level Order Traversal (Breadth First Search)
void levelOrder(node *root){
    queue<node*>qu;
    qu.push(root);
    while(qu.size() > 0){
        node* temp = qu.front();
        qu.pop();
        cout<<temp->value<<" ";
        if(temp->left != nullptr) qu.push(temp->left);
        if(temp->right != nullptr) qu.push(temp->right);
    }
    cout<<endl;
}

int main(){

    node *root = new node(10);
    root->left = new node(5);
    root->right = new node(16);
    root->left->left = new node(1);
    root->left->right = new node(8);
    root->right->left = new node(12);
    root->right->right = new node(20);

    vector<int>v;
    reverseInorder(root, v);
    cout<<"Reverse Inorder Traversal: ";
    levelOrder(root);

    int idx = 0;
    preorder(root, v, idx); // BST Max-heap
    cout<<"Preorder Traversal / Max Heap: ";
    levelOrder(root);
    return 0;
}