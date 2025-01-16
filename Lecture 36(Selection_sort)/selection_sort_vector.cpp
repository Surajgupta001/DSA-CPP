#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void selectionSort(vector<int> &v){
    int n = v.size();
    
    for(int i=0;i<n-1;i++){
        // finding min element in unsorted array
        int min_index = i;
        for(int j=i+1;j<n;j++){
            if(v[j]<v[min_index]){
                min_index = j;
            }
        }
        // placing min element at beginning
        if(i!=min_index){
            swap(v[i],v[min_index]);
        }
    }
}
int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter all the element of array: "<<endl;

    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<"Unsorted Array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    selectionSort(v);

    cout<<"Sorted array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

    return 0;
}