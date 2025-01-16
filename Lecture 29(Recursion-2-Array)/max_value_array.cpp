#include <iostream>
using namespace std;

int function(int *arr, int idx, int n){
    // base case
    if(idx = n-1){
        // we only have one element left,so it is the maximum.
        return arr[idx];
    }
    return max(arr[idx],function(arr,idx+1,n));
}
int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter all the element of array."<<endl;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Maximum element in the array is: "<<function(arr,0,n);
    
    return 0;
}