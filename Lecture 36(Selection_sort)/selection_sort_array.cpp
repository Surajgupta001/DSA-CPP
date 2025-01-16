#include <iostream>
using namespace std;
#include <limits.h>

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter all the element of array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Unsorted array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    // Selection Sort
    for(int i=0;i<n-1;i++){
        int min = INT_MAX;
        int min_index = -1;
        for(int j=i;j<=n-1;j++){
            if(min > arr[j]){
                min = arr[j];
                min_index = j;
            }
        }
        // Swap the minimum element of unsorted parts;
        // Swap min_index and i;
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp; 
    }
    cout<<endl;
    cout<<"Sorted array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
