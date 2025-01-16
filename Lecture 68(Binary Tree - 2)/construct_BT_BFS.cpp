#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
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
        left = NULL;
        right = NULL;
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

// Level Order Traversal Using Queue(BFS)
void levelOrderQueue(node *root){
    if(root == NULL) return;
    queue<node*>qu;
    qu.push(root);
    while(qu.size() > 0){
        // temp is the current node
        node *temp = qu.front();
        qu.pop();
        cout<<temp->value<<" ";
        // if the left child is not null then push it to the queue
        if(temp->left != nullptr) qu.push(temp->left);
        // if the right child is not null then push it to the queue
        if(temp->right != nullptr) qu.push(temp->right);
    }
    cout<<endl;
}

int main(){

    int arr[] = {1,2,3,4,5,INT_MIN,6,INT_MIN,7,8,9};

    int n = sizeof(arr)/sizeof(arr[0]);

    // Constructing Tree
    node *root = constructTree(arr,n);
    
    levelOrderQueue(root);

    return 0;
}