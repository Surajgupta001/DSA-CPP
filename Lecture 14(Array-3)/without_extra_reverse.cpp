/*
Q.Write a program to reverse the array without using any-extra array.
*/ 
#include <iostream>
using namespace std;
void reverse(int arr[] , int n){ // pass by value

    int i = 0;
    int j = n-1; 
    
    while (i < j){
        // arr[i] and arr[j]; ---> swap;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
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

    reverse(arr,n);

    cout<<"Reversed array are: ";
    for (int i = 0; i <= n-1; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}