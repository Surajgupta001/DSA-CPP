#include <iostream>
#include <vector>
using namespace std;

class MinHeap{
    public:
    vector<int>v;
    int idx;

    // Constructor
    MinHeap(int x){ // x is capacity
        idx = 1;
        vector<int>vec(x);
        v = vec;
        /* v.resize(x+1)*/ 
    }

    int top(){
        return v[1];
    }
    
    void push(int data){
        v[idx] = data;
        int i = idx;
        idx++;
        // Swapping of i with parent till i == 1;
        while(i != 1){ // Corrected condition
            int parent = i / 2;
            if(v[i] < v[parent]){
                swap(v[i],v[parent]);
                i = parent; // Move up to Parent
            }
            else{
                break;
            }
        }
    }
    void pop(){
        // Pop
        idx--;
        v[1] = v[idx];
        // Rearrangment
        int i = 1;
        while(true){
            int left = 2 * i;
            int right = 2 * i + 1;
            if(left > idx-1) break; // No left Child
            if(right > idx-1){ // Only Left Child
                if(v[i] > v[left]){
                    swap(v[i],v[left]);
                    i = left;
                }
                break;
            }
            // Both Child Exist
            if(v[left] < v[right]){
                if(v[i] > v[left]){
                    swap(v[i],v[left]);
                    i = left;
                }
                else break;
            }
            else{
                if(v[i] > v[right]){
                    swap(v[i],v[right]);
                    i = right;
                }
                else break;
            }
        }
    }
    
    int size(){
        return idx - 1;
    }
    
    void display(){
        for(int i=1;i<=idx-1;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    MinHeap pq(25); // 25 is maximum capacity

    pq.push(10);
    pq.push(20);
    cout<<pq.top()<<" "<<pq.size()<<endl; // Should output: 10 2
    pq.push(11);
    pq.push(2);
    cout<<pq.top()<<" "<<pq.size()<<endl; // Should output: 2 4
    pq.display();
    pq.pop();
    cout<<pq.top()<<" "<<pq.size()<<endl; // Should output: 10 3
    pq.display();

    return 0;
}