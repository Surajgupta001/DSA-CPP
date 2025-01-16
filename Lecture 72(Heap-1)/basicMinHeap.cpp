#include <iostream>
#include <queue>
using namespace std;

int main(){

    priority_queue<int, vector<int>, greater<int>>pq; // decleration of min heap
    
    pq.push(10);
    pq.push(25);
    pq.push(-6);
    pq.push(81);

    cout<<pq.top();

    return 0;
}