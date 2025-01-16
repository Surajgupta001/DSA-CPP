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

    for(int i=0;i<=n-1;i++){
        bool flag = false;
        for(int j=i+1;j<=n-1;j++){
            if(arr[i]==arr[j]){
                flag = true;
            }
        }
        if(flag == false){
            cout<<arr[i];
            break;
        }

    }
    return 0;
}