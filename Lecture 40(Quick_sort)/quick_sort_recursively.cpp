#include <iostream>
using namespace std;

int partition (int arr[], int first, int last){
    int pivot = arr[last];
    int i = first-1; // for inserting element < pivot.
    int j = first; // for finding elements < pivot.

    for(j=first;j<last;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // now i is pointing to the last element < pivot
    // correct position for pivot will be - i+1.
    swap(arr[i+1],arr[last]);
    return i+1;
}

void quickSort (int arr[], int first, int last){
    // base case
    if(first>=last) return;

    // recursive case
    int pivot_index = partition(arr, first, last);
    quickSort(arr, first, pivot_index-1);
    quickSort(arr, pivot_index+1, last);
    
    return;
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<"Unsorted array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    quickSort(arr,0,n-1);

    cout<<endl;
    cout<<"Quick Sorted array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}