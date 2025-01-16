#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    bool sorted_flag = true; // sort i.e. output 1 
    for(int i=1;i<n;i++){
        if(arr[i]<=arr[i-1]){
            sorted_flag = false; // unsort i.e. output 0;
        }
    }

    if(sorted_flag==true){
        cout<<"Array is Sorted."<<endl;
    }
    else{
        cout<<"Array is Unsorted."<<endl;
    }

    cout<<sorted_flag<<endl;

    return 0;
}