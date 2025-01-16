#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <stdbool.h>

void bubbleSort(vector<int> &v){
    int n = v.size();
    
    for(int i=0;i<n-1;i++){
        bool flag = false;
        for(int j=0;j<n-i-1;j++){
            if(v[j]>v[j+1]){
                flag = true;
                swap(v[j],v[j+1]);
            }
        }
        if(!flag) break;
    }
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

    bubbleSort(v);
    
    cout<<"Sorted array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    
    return 0;
}