#include <iostream>
using namespace std;

int function(int *arr, int idx, int n){
    // base case
    if(idx == n-1){
        // idx is the the last index so there is only one element under consideration.
        return arr[idx];
    }
    return arr[idx] + function(arr,idx+1,n);
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"sum of element of the array is: "<<function(arr,0,n);
    return 0;
}