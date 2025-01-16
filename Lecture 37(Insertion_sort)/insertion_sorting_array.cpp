#include <iostream>
using namespace std;
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

    cout<<endl;
    // Insertion sort
    for(int i=1;i<n;i++){
        int current_element = arr[i];
        int j=i-1;
        
        while(j>=0 && arr[j]>current_element){
            arr[j+1] = arr[j];
            j--;
        }
        // insert current element
        arr[j+1] = current_element;
    }

    cout<<"Sorted array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}