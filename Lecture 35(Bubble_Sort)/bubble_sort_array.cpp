#include <iostream>
using namespace std;
int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    
    cout<<"Enter all the element of array: ";

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Printing Unsorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    // Bubble sort
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout<<endl;
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}