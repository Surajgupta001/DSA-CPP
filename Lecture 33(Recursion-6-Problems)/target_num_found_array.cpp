#include <iostream>
using namespace std;

// function represent whether x is the range [i,n-1] or not ?
bool function(int *arr, int n, int i, int key){
    // base case
    if(i==n){
        // array is exhausted
        return false;
    }
    return (arr[i]==key || function(arr,n,i+1,key));
}

int main(){
    
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter all the element of array: "<<endl;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter a target value: ";
    cin>>key;

    bool result = function(arr,n,0,key);
    if(result) cout<<"yes";
    else cout<<"No";

    return 0;
}
