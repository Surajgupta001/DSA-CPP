#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <limits.h>
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
// left boundary traversal
void leftboundaryTraversal(node *root){
    if(root == nullptr) return;
    if(root->left == nullptr and root->right == nullptr) return;
    cout<<root->value<<" ";
    leftboundaryTraversal(root->left);
    if(root->left == nullptr) leftboundaryTraversal(root->right);
}
// bottom boundary traversal
void bottomboundaryTraversal(node *root){
    if(root == nullptr) return;
    if(root->left == nullptr and root->right == nullptr) cout<<root->value<<" ";
    bottomboundaryTraversal(root->left);
    bottomboundaryTraversal(root->right);
}
// right boundary traversal
void rightboundaryTraversal(node *root){
    if(root == nullptr) return;
    if(root->left == nullptr and root->right == nullptr) return;
    rightboundaryTraversal(root->right);
    if(root->right == nullptr) rightboundaryTraversal(root->left);
    cout<<root->value<<" ";
}

// Merged Boundry Traversal
void boundryTraversal(node *root){
    leftboundaryTraversal(root->left);
    bottomboundaryTraversal(root);
    rightboundaryTraversal(root->right);
}

int main(){

    int arr[] = {1,2,3,4,5,INT_MIN,6,7,INT_MIN,8,INT_MIN,9,10,INT_MIN,11,INT_MIN,12,INT_MIN,13,INT_MIN,14,15,16,INT_MIN,17,INT_MIN,INT_MIN,18,INT_MIN,19,INT_MIN,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,27,INT_MIN,INT_MIN,28,INT_MIN,INT_MIN};
    int n = sizeof(arr)/sizeof(arr[0]);

    node *root = constructTree(arr,n);

    // left boundary traversal
    cout<<"Left Boundary Traversal: ";
    leftboundaryTraversal(root);
    // bottom boundary traversal
    cout<<endl<<"Bottom Boundary Traversal: ";
    bottomboundaryTraversal(root);
    // right boundary traversal
    cout<<endl<<"Right Boundary Traversal: ";
    rightboundaryTraversal(root->right);

    // Merged Boundry Traversal (Left Boundary + Bottom Boundary + Right Boundary)
    cout<<endl<<"Merged Boundry Traversal: ";
    boundryTraversal(root);
    
    return 0;
}