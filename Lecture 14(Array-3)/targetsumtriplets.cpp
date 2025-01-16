/*
Q.Find the total number pf triplets in the array whose sum is equal to the given value of x;
*/ 

#include <iostream>
using namespace std;

int main(){
    
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int target;
    cout<<"Enter the target: ";
    cin>>target;

    int totaltriplets = 0;

    for(int i=0;i<=n-1;i++){
        for(int j=i+1;j<=n-1;j++){
            for(int k=j+1;k<=n-1;k++){
                if(arr[i]+arr[j]+arr[k] == target){
                    totaltriplets++;
                }
            }
        }
    }

    cout<<"No. of totaltriplets of sum is: "<<totaltriplets<<endl;

    return 0;
}