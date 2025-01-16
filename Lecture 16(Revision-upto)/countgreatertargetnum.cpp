/*
Q. COunt the number of element in given array greater than a given number x.
*/ 
#include <iostream>
using namespace std;
int main(){

    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int key;
    cout << "Enter the key: ";
    cin >> key;
    
    int count=0;

    for(int i=0;i<n;i++){
        if(arr[i]>key){
            count++;
        }
    }

    cout<<count<<endl;

    return 0;
}