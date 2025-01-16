/*
Q.Given two array arr1[] and arr2[] of size m and n sorted in decreasing order.Merge the two array into a single sorted array of size m+n.
*/
#include <iostream>
using namespace std;
int main(){

    int m;
    cout<<"Enter the size of 1st array: ";
    cin>>m;
    int arr[m];
    for (int i = 0; i <m; i++){
        cin>>arr[i];
    }

    int n;
    cout<<"Enter the size of 2nd array: ";
    cin>>n;
    int brr[n];
    for (int i =0;i<n;i++){
        cin>>brr[i];
    }

    int result_arr[m+n];
    int i = 0; // will help us to iterate on arr.
    int j = 0; // will help us to iterate on brr.
    int k = 0; // will help us to iterate on result_arr.

    while (i < m && j < n){
        // both i and j should be within the limits or arr1 and arr2.
        if (arr[i] < brr[j]){
            result_arr[k] = arr[i];
            k++;
            i++;
        }
        else{
            result_arr[k] = brr[j];
            k++;
            j++;
        }
    }

    while(i<m){
        // brr was exhasuted ans we still got left in arr.
        result_arr[k] = arr[i];
        i++;
        k++;
    }

    while(j<n){
        // arr was exhasuted ans we still got left in brr.
        result_arr[k] = brr[j];
        j++;
        k++;
    }

    // Display result
    cout<<"Merged Sorted array: "<<endl;
    for(int i=0;i<m+n;i++){
        cout<<result_arr[i]<<" ";
    }

    return 0;
} 