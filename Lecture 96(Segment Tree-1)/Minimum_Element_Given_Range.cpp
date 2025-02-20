#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> segmentTree; // global Segment Tree

// Build the Segment Tree
void buildTree(vector<int>& v, int i, int low, int high) {
    if (low == high) { // Base case: leaf node
        segmentTree[i] = v[low];
        return;
    }
    int mid = low + (high - low) / 2;
    buildTree(v, 2 * i + 1, low, mid);     // Left subtree
    buildTree(v, 2 * i + 2, mid + 1, high); // Right subtree
    segmentTree[i] = min(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
}

// Query the minimum in the range [left, right]
int getMin(int i, int low, int high, int &left, int &right) {
    if (low > right || high < left) return INT_MAX; // Completely outside range
    if (low >= left && high <= right) return segmentTree[i]; // Completely inside range
    int mid = low + (high - low) / 2;
    int leftMin = getMin(2 * i + 1, low, mid, left, right);
    int rightMin = getMin(2 * i + 2, mid + 1, high, left, right);
    return min(leftMin, rightMin);
}

int main() {
    vector<int> v = {1, 4, 2, 8, 6, 4, 9, 3}; // Input array
    int n = v.size();
    segmentTree.resize(4 * n); // Initialize segmentTree with enough size
    buildTree(v, 0, 0, n - 1); // Build the tree

    int queries;
    cout<<"Enter the number of queries: ";
    cin>>queries;
    
    while (queries--) {
        int l, r;
        cout << "Enter the range (l r): ";
        cin >> l >> r;
        int minVal = getMin(0, 0, n - 1, l, r);
        cout<<"Minimum Element in given range is: "<<minVal<<endl;
    }
    return 0;
}