#include <iostream>
using namespace std;

void reverse(int arr[], int si, int ei){
    for(int i=si,j=ei;i<j;i++,j--){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    return ;
}

int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int k;
    cout<<"Enter the number of rotation: ";
    cin>>k;

    // step to solve these type of problems;
    k = k%n;
    reverse(arr,0,n-1);
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    for(int i=0;i<=n-1;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}