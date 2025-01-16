/*
Q. Find the difference between the sum of element at even indices to the sum of element at odd indices.
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

    int sum_even = 0;
    int sum_odd = 0;

    for(int i=0;i<=n-1;i++){
        if(i%2 == 0){
            sum_even = sum_even + arr[i];
        }
        else{
            sum_odd = sum_odd + arr[i];
        }
    }

    int result;
    result = sum_even - sum_odd;
    cout<<result<<" ";

    return 0;
}