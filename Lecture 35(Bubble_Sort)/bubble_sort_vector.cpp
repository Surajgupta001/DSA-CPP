#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void bubbleSort(vector<int> &v){
    int n = v.size();
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
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

    cout<<"Unsorted array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    bubbleSort(v);
    cout<<"Sorted array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}