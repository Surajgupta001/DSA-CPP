#include <iostream>
#include <stdbool.h>
using namespace std;
int main(){

    int n;
    cout<<"Enter the size array: ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter the key element: ";
    cin>>key;

    bool flag = false; // false means not present;

    for(int i=0;i<n-1;i++){
        if(arr[i]==key){
            flag = true;
        }
    }
    
    if(flag==false){
        cout<<key<<" is not present in this array."<<endl;
    }
    else{
        cout<<key<<" is present in this array."<<endl;
    }

    return 0;
    
}