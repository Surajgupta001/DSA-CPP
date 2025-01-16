/*
WAP to find kth smallest element in an array using Quick sort.

INPUT: 
Enter the element array
3 5 2 1 4 7 8 6

Enter the value of k
5

OUTPUT:
K'th smallest element is 5
*/ 

#include <iostream>
using namespace std;
#include <vector>
#include <limits.h>

int partition (int arr[], int l, int r){
    int pivot = arr[r];
    int i=l;
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[r]);
    return i;
}
int kthSmallest(int arr[], int l, int r, int k){
    if(k>0 && k<=r-l+1){
        int position = partition(arr,l,r); // position of pivot element.
        if(position-l==k-1){
            return arr[position];
        }
        else if(position-l>k-1){
            return kthSmallest(arr,l,position-1,k);
        }
        else{
            return kthSmallest(arr,position+1,r,k-(position-l+1));
        }
    }
    return INT_MAX;
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
    cout<<"Enter the value of k: ";
    cin>>k;

    cout<<"K'th smallest element is: ";
    cout<<kthSmallest(arr,0,n-1,k);
    cout<<endl;
    return 0;
}