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
    int brr[n];
    for(int i=0;i<n;i++){
        brr[i] = arr[n-1-i];
    }
    cout<<"Reversed array are: ";
    for(int i=0;i<n;i++){
        cout<<brr[i]<<" ";
    }
    return 0;
}