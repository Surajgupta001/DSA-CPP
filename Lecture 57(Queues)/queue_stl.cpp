#include <iostream>
using namespace std;
#include <queue>
int main(){

    queue<int> qu;

    // Enqueue
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);

    // Dequeue
    qu.pop();

    while(!qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }

    return 0;
}