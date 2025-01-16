/*
Q.Find the total number of twice in the array whose sum is equal to the given value of x;
*/ 

#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int target;
    cout<<"Enter the target: ";
    cin>>target;

    int totalpairs = 0; // 0 - no pair.

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<=n-1;i++){
        for(int j=i+1;j<=n-1;j++){
                if(abs(arr[j])-abs(arr[i]) == target){
                    totalpairs++;
                }
        }
    }
    cout<<totalpairs<<endl;
    return 0;
}