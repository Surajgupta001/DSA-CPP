/*
Given an integer array 'a', return the prefix sum/running 
sum in the same array without creating a new array.
*/ 
#include <iostream>
#include <vector>
using namespace std;

void runningSum(vector<int> &v){
    for(int i=1;i<v.size();i++){
        v[i] = v[i-1] + v[i];
    }
    return;
}

int main(){

    int n;
    cout<<"Enter the size array: ";
    cin>>n;

    vector<int>v;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        v.push_back(element);
    }

    runningSum(v);

    cout<<"Sum of prefix running array are: "<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}