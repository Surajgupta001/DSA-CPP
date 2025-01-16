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

    int key;
    cout<<"Enter the key value: ";
    cin>>key;

    int ans = -1; // key element not present in array.

    for(int i=0;i<n;i++){
        if(arr[i]==key){
            ans = arr[i];
        }
    }

    cout<<ans<<endl;
    
    return 0;
}