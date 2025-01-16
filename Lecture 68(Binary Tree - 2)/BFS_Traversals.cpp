#include <iostream>
#include <algorithm>
#include <queue>
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

int levels(node *root){
    if(root == nullptr) return 0;
    return 1 + max(levels(root->left),levels(root->right));
}

// nth Level of tree node - [Left ==> Right]
void nthLevel(node *root, int curr_level, int level){
    // Base Case
    if(root == NULL) return;
    // Displaying the root node
    if(curr_level == level){
        cout<<root->value<<" ";
        return;
    }
    // Displaying the left subtree
    nthLevel(root->left, curr_level+1, level); // Left Recursion
    // Displaying the right subtree
    nthLevel(root->right, curr_level+1, level); // Right Recursion
}

// Level Order Traversals - (Using DFS i.e nth level)
void levelOrder(node *root){
    int n = levels(root);
    for(int i=1;i<=n;i++){
        nthLevel(root, 1, i);
        cout<<endl;
    }
}

// nth Level of tree node - [Right ==> Left]
void nthLevelRev(node *root, int curr_level, int level){
    // Base Case
    if(root == NULL) return;
    // Displaying the root node
    if(curr_level == level){
        cout<<root->value<<" ";
        return;
    }
    // Displaying the right subtree
    nthLevelRev(root->right, curr_level+1, level); // Right Recursion
    // Displaying the left subtree
    nthLevelRev(root->left, curr_level+1, level); // Left Recursion
}

// Level Order Traversals - (Using BFS)
void levelOrderRev(node *root){
    int n = levels(root);
    for(int i=1;i<=n;i++){
        nthLevelRev(root, 1, i);
        cout<<endl;
    }
}

// Level Order Traversal Using Queue(BFS)
void levelOrderQueue(node *root){
    if(root == NULL) return;
    queue<node*>qu;
    qu.push(root);
    while(qu.size() > 0){
        node *temp = qu.front();
        qu.pop();
        cout<<temp->value<<" ";
        if(temp->left != nullptr) qu.push(temp->left);
        if(temp->right != nullptr) qu.push(temp->right);
    }
    cout<<endl;
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

    int current_level;
    cout<<"Enter a current Level: ";
    cin>>current_level;

    int nth_Level;
    cout<<"Enter the nth Level: ";
    cin>>nth_Level;

    cout<<"All nodes of nth level is: ";
    // printing all nodes of nth level
    nthLevel(root,current_level,nth_Level);
    
    cout<<endl<<"Levels Order Traverse(Left => Right): "<<endl;
    levelOrder(root);

    cout<<"Levels Order Traverse in Reverse Order(Right => Left): "<<endl;
    levelOrderRev(root);

    cout<<"All nodes of nth level(using Queue) is: ";
    levelOrderQueue(root);

    return 0;
}