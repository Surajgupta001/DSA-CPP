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

    // arrange square of given element in inc order.
    int result_squr[n];
    int i=0;
    int j=n-1;
    int k=n-1;
    
    while(i<=j && k>=0){
        if(abs(arr[i])>abs(arr[j])){
            result_squr[k]=arr[i]*arr[i];
            i++;
            k--;
        }
        else{
            result_squr[k]=arr[j]*arr[j];
            j--;
            k--;
        }
    }

    // display the result
    for(int i=0;i<n;i++){
        cout<<result_squr[i]<<" ";
    }
    return 0;
}