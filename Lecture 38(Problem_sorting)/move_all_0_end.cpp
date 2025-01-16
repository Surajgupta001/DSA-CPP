/*
Given an integer arr, move all 0's to the end of it while maitaining the relative order of the non-zero element.

Note that you must do this in-place without making a copy of the array.

INPUT: 0 5 0 3 4 2

OUTPUT: 5 3 4 2 0 0

*/ 

#include <iostream>
using namespace std;
#include <vector>

void swapZerosToEnd(vector<int> &v){
    
    int n = v.size();
    
    for(int i=n-1;i>=0;i--){
        int j = 0;
        bool flag = false;
        while(j!=i){
            if(v[j]==0 && v[j+1]!=0){
                swap(v[j],v[j+1]);
                flag = true;
            }
            j++;
        }
        if(!flag)
        break;
    }
    return;
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter all the element of array: "<<endl;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    swapZerosToEnd(v);

    cout<<"Sorted array: "<<endl;
    cout<<"All Zeros move to end:  ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}