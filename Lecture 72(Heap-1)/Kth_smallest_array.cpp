/*
Find the Kth smallest element in a given array.

Input: {10,20,-4,6,18,24,105,118}
K = 3
Output: 10;
*/ 

#include <iostream>
#include <queue>
#include <vector>
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

    priority_queue<int>pq; // Max Heap
    for(int i=0;i<n;i++){
        pq.push(v[i]);
        if(pq.size() > k) pq.pop();
    }

    cout<<"Kth smallest element is: "<<pq.top()<<endl;

    return 0;
}