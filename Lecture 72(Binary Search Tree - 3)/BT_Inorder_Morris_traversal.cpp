#include <iostream>
#include <vector>
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

node *constructTree(int arr[], int n) { // n = size of array
    queue<node*> qu;
    node *root = new node(arr[0]);
    qu.push(root);

    // i and j are index numbers
    int i = 1; // index number
    int j = 2; // index number
    while (qu.size() > 0 && i < n) {
        node *temp = qu.front();
        qu.pop();

        // Create left and right child
        node *left_Child; // left child
        node *right_Child; // right child

        // if the value is not INT_MIN then create a new node
        if (arr[i] != INT_MIN) left_Child = new node(arr[i]);
        else left_Child = nullptr;

        // if the value is not INT_MIN then create a new node
        if (j != n && arr[j] != INT_MIN) right_Child = new node(arr[j]);
        else right_Child = nullptr;

        // assign the left and right child to the current node
        temp->left = left_Child;
        temp->right = right_Child;

        // if the left child is not null then push it to the queue
        if (left_Child != nullptr) qu.push(left_Child);
        if (right_Child != nullptr) qu.push(right_Child);
        
        i = i + 2; // increment index by 2
        j = j + 2; // increment index by 2
    }
    return root;
}

vector<int> inorderTraversal(node *root) {
    vector<int> ans;
    node *curr = root;
    while (curr != nullptr) {
        if (curr->left != nullptr) { // find the predecessor
            node *pred = curr->left;
            while (pred->right != nullptr && pred->right != curr) pred = pred->right;
            if (pred->right == nullptr) { // link
                pred->right = curr;
                curr = curr->left;
            } else { // pred->right = curr : unlink
                pred->right = nullptr;
                ans.push_back(curr->value);
                curr = curr->right;
            }
        } else { // curr->left == nullptr
            ans.push_back(curr->value);
            curr = curr->right;
        }
    }
    return ans;
}

int main() {
    // Example usage:
    int arr[] = {1,2,3,4,5,INT_MIN,8,INT_MIN,INT_MIN,6,7,9}; // INT_MIN represents null
    int n = sizeof(arr) / sizeof(arr[0]);

    // Construct the tree
    node *root = constructTree(arr, n);

    // Perform in-order traversal
    vector<int> inorder = inorderTraversal(root);

    // Print the in-order traversal
    cout << "In-order Traversal: ";
    for (int val : inorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}