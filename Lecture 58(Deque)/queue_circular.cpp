#include <iostream>
using namespace std;
#include <vector>

class Queue{

    int front;
    int back;
    vector<int>v;
    int curr_size;
    int total_size;

    public:
    Queue(int n){
        v.resize(n);
        total_size = n;
        back = n-1;
        front = 0;
        curr_size = 0;
    }

    void Enqueue(int data){
        if(isFull()) return;
        back = (back + 1)%total_size;
        v[back] = data;
        curr_size++;
    }

    void Dequeue(){
        if(isEmpty()) return;
        front = (front + 1)&curr_size;
        curr_size--;
    }
    int getfornt(){
        if(front == -1){
            return -1;
        }
        return v[front];
    }

    bool isEmpty(){
        return curr_size == 0;;
    }

    bool isFull(){
        return curr_size == total_size;
    }
};
int main(){
    
    Queue qu(3);
    qu.Enqueue(10);
    qu.Enqueue(20);
    qu.Enqueue(30);
    qu.Dequeue();
    qu.Enqueue(40);
    qu.Dequeue();
    qu.Dequeue();
    qu.Dequeue();
    qu.Enqueue(400);
    qu.Enqueue(500);

    while(!qu.isEmpty()){
        cout<<qu.getfornt()<<" ";
        qu.Dequeue();
    }

    return 0;
}