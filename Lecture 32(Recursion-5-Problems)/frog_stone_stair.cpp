#include <iostream>
using namespace std;

int function(int *h, int n, int i){
    // Base case
    if(i==n-1) return 0;
    if(i==n-2) return function(h,n,i+1) + abs(h[i]-h[i+1]);
    return min(function(h,n,i+1) + abs(h[i]-h[i+1]),function(h,n,i+2)+abs(h[i]-h[i+2]));
}
int main(){
    
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter all the element of array: "<<endl;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Minimum cost: "<<function(arr,n,0);
    return 0;
}
