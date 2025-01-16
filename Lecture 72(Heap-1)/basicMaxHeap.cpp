#include <iostream>
#include <queue>
using namespace std;

int main(){

    priority_queue<int>pq; // in c++ Max Heap (default)

    pq.push(10);
    pq.push(2);
    pq.push(-6);
    pq.push(8);
    cout<<pq.top();

    return 0;
}