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

    int max = arr[0];
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max = arr[i];
        }
    }

    cout<<"Maximum value of this array is: "<<max<<endl;
    return 0;
}