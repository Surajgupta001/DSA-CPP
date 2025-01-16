#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r){
    int an = mid-l+1;
    int bn = r-mid;

    // create 2 temp array
    int a[an];
    for(int i=0;i<an;i++){
        a[i]=arr[l+i];
    }

    int b[bn];
    for(int j=0;j<bn;j++){
        b[j]=arr[mid+1+j];
    }

    int i=0; // initial index of first subarray, a
    int j=0; // initial index of second subarray, b
    int k=l; // initial index of merged subarray.

    while(i<an && j<bn){
        if(a[i]<b[j]){
            arr[k++]=a[i++];
        }
        else{
            arr[k++]=b[j++];
        }
    }

    while(i<an){
        arr[k++]=a[i++];
    }
    while(j<bn){
        arr[k++]=b[j++];
    }
    return;
}

void mergeSort(int arr[], int l, int r){ // l=0; r=n-1;
    // base case
    if(l>=r) return; 
    
    // recursively
    int mid = (l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);

    return;
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

    mergeSort(arr,0,n-1);

    cout<<"Merged Sorted Array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}