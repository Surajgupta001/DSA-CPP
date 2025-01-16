#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    vector<int>v(n);
    cout<<"Enter the elements of vector: ";
    for(int i=0;i<n;i++) cin>>v[i];

    int minCost = 0;
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i=0;i<n;i++) pq.push(v[i]);
    while(pq.size() > 1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        pq.push(a+b);
        minCost += a+b;
    }
    cout<<"Minimum cost is: "<<minCost;

    return 0;
}