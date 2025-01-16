/*
Sort a 'K' sorted array (sort a nearly sorted array)
======================================================
input: [6,5,3,2,8,10,9]
k = 3
output: [1,2,3,5,6,8,10]
*/ 

#include <iostream>
#include <queue>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    vector<int>v(n);
    cout<<"Enter the elements of vector: ";
    for(int i=0;i<n;i++) cin>>v[i];

    int k;
    cout<<"Enter the value of K: ";
    cin>>k;

    priority_queue<int, vector<int>, greater<int>>pq; // Min Heap
    int idx = 0;
    for(int i=0;i<n;i++){
        pq.push(v[i]);
        if(pq.size() > k){
            v[idx++] = pq.top();
            pq.pop();
        }
    }
    while(!pq.empty()){
        v[idx++] = pq.top();
        pq.pop();
    }
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++) cout<<v[i]<<" ";

    return 0;
}