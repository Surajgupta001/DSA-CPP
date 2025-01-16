/*
Given two sorted arrays, write a program to merge them in a sorted manner.

Input: 

    arr1[5 8 10]
    arr2[2,7,8];

Output: 

    result[2 5 7 8 8 10];
*/

#include <iostream>
using namespace std;

void merge(int arr[], int m, int brr[], int n, int result_arr[]){

    int i=0; //arr[] 
    int j=0; // brr[]
    int k=0; //result_arr[]

    while(i<m && j<n){
        if(arr[i]<brr[j]){
            result_arr[k++]=arr[i++];
        }
        else{
            result_arr[k++]=brr[j++];
        }
    }

    while(i<m){
        result_arr[k++]=arr[i++];
    }
    while(j<n){
        result_arr[k++]=brr[j++];
    }
    return ;
}
int main (){

    int m;
    cout<<"Enter the size of 1st array: ";
    cin>>m; 
    int arr[m];
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }

    int n;
    cout<<"Enter the size of 2nd array: ";
    cin>>n;
    int brr[n];
    for(int i=0;i<n;i++){
        cin>>brr[i];
    }
    
    int result[m+n];

    merge(arr,m,brr,n,result);

    cout<<"Merge 2 sorted array: "<<endl;
    for(int i=0;i<(m+n);i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}