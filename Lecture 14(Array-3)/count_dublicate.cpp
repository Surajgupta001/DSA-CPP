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

    int count = 0;
    cout<<"Duplicate element are: ";
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                cout<<arr[i]<<" ";
                count++;
                break;
            }
        }
    }

    cout<<endl<<"count of the element: "<<count;

    return 0;
}