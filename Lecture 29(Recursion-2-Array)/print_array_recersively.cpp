#include <iostream>
using namespace std;

void function(int *arr, int idx, int n){
    // base case
    if(idx == n) return;
    // self work
    cout<<arr[idx]<<" ";
    // assume that
    function(arr,idx+1,n); // assume it works  correctly -> it will print the remaining arr.
}
int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<endl;

    cout<<"Printing Array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"After calling function: "<<endl;
    function(arr,0,n);
    
    return 0;
}