#include <iostream>
using namespace std;
#include <stdbool.h>
int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    
    cout<<"Enter all the element of array: "<<endl;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Unsorted array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    // Bubble sort;
    for(int i=0;i<n-1;i++){
        bool flag = true; // array is not sorted yet.
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = false;
            }
        }
        if(flag == true){
            break;
        }
    }
    cout<<endl;
    cout<<"Sorted array: "<<endl;
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}