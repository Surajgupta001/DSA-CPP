#include <iostream>
using namespace std;
#include <vector>

class Queue{
    int front;
    int back;
    vector<int>v;
    public:
    Queue(){
        back = -1;
        front = -1;
    }

    void Enqueue(int data){
        v.push_back(data);
        back++;
        if(back == 0){
            front = 0;
        }
    }

    void Dequeue(){
        if(front == back){
            front = -1;
            back = -1;
            v.clear();
        }
        else{
            front++;
        }
    }
    int getfornt(){
        if(front == -1){
            return -1;
        }
        return v[front];
    }

    bool isEmpty(){
        return front == -1;
    }
};
int main(){
    
    Queue qu;
    qu.Enqueue(10);
    qu.Enqueue(20);
    qu.Enqueue(30);
    qu.Dequeue();
    qu.Enqueue(40);

    while(!qu.isEmpty()){
        cout<<qu.getfornt()<<" ";
        qu.Dequeue();
    }

    return 0;
}