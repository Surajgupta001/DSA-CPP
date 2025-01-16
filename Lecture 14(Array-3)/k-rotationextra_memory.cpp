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

    int k;
    cout<<"Enter the number of rotation: ";
    cin>>k;

    k = k%n;

    int extra_arr[n];

    int j = 0;
    // Inserting last k element in extra_arr;
    for(int i=n-k;i<n;i++){
        extra_arr[j++]=arr[i];
    }

    // Inserting first (n-k) element in extra_arr;
    for(int i=0;i<=k;i++){
        extra_arr[j++]=arr[i];
    }

    cout<<"K times rotated array is: ";
    for(int i=0;i<n;i++){
        cout<<extra_arr[i]<<" ";
    }
    
    return 0;
}