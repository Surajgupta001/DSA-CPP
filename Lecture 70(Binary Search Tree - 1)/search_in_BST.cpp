#include <iostream>
using namespace std;

class node {
public:
    int value;
    node *left;
    node *right;

    // constructor
    node(int data) {
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

node *searchBST(node *root, int target) {
    if (root == nullptr || root->value == target) return root;
    else if (root->value > target) return searchBST(root->left, target);
    else return searchBST(root->right, target);
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

    root = insertIntoBST(root, 50);
    insertIntoBST(root, 30);
    insertIntoBST(root, 20);
    insertIntoBST(root, 40);
    insertIntoBST(root, 70);
    insertIntoBST(root, 60);
    insertIntoBST(root, 80);

    cout<<"In-Order Traversal of the BST: ";
    inOrderTraversal(root);
    cout<<endl;

    int target;
    cout<<"Enter the element to search: ";
    cin>>target;

    node *result = searchBST(root, target);

    if(result) cout<<"Found node with value: "<<result->value<< endl;
    else cout<<"Node with value "<<target<<" not found"<<endl;

    return 0;
}