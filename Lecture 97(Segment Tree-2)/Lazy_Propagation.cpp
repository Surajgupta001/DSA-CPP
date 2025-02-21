#include <iostream>
#include <vector>
using namespace std;

vector<int> segmntTree;
vector<int> lazyTree;

void buildTree(vector<int>& v, int i, int low, int high){
    if(low == high){
        segmntTree[i] = v[low];
        return;
    }
    int mid = low + (high-low)/2;
    buildTree(v, 2*i+1, low, mid);
    buildTree(v, 2*i+2, mid+1, high);
    segmntTree[i] = segmntTree[2*i+1] + segmntTree[2*i+2];
}

int getSum(int i, int low, int high, int left, int right){
    // Check for pending lazy updates
    if(lazyTree[i] != 0){
        int rangeSize = high - low + 1;
        segmntTree[i] += rangeSize*lazyTree[i];
        if(low != high){ // send lazy to left and right child
            lazyTree[2*i+1] += lazyTree[i];
            lazyTree[2*i+2] += lazyTree[i];
        }
        lazyTree[i] = 0;
    }
    if(left > high or right < low) return 0;
    if(low >= left and high <= right) return segmntTree[i];
    int mid = low + (high-low)/2;
    int leftSum = getSum(2*i+1, low, mid, left, right);
    int rightSum = getSum(2*i+2, mid+1, high, left, right);
    return leftSum + rightSum;
}

void updateRange(int i, int low, int high, int left, int right, int value){
    // Check for pending lazy updates
    if(lazyTree[i] != 0){
        int rangeSize = high - low + 1;
        segmntTree[i] += rangeSize*lazyTree[i];
        if(low != high){ // send lazy to left and right child
            lazyTree[2*i+1] += lazyTree[i];
            lazyTree[2*i+2] += lazyTree[i];
        }
        lazyTree[i] = 0;
    }
    if(left > high or right < low) return;
    if(low >= left and high <= right){ // update entire [low,high]
        int rangeSize = high - low + 1;
        segmntTree[i] += rangeSize*value;
        if(low != high){ // send lazy to left and right child
            lazyTree[2*i+1] += value;
            lazyTree[2*i+2] += value;
        }
        return;
    }
    int mid = low + (high-low)/2;
    updateRange(2*i+1, low, mid, left, right, value);
    updateRange(2*i+2, mid+1, high, left, right, value);
    segmntTree[i] = segmntTree[2*i+1] + segmntTree[2*i+2];
}

int main(){
    vector<int> v = {1,4,2,8,6,4,9,3};
    int n = v.size();
    segmntTree.resize(4*n);
    lazyTree.resize(4*n, 0);
    buildTree(v, 0, 0, n-1);
    cout<<getSum(0,0,n-1,1,3)<<endl;
    updateRange(0,0,n-1,2,5,10);
    cout<<getSum(0,0,n-1,1,3);
    return 0;
}