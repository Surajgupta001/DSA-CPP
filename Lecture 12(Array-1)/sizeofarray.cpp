#include <iostream>
using namespace std;
int main(){
    
    int arr[]= {1,2,3,4};

    cout<<sizeof(arr)<<endl;
    
    cout<<sizeof(arr)/sizeof(arr[0])<<endl;

    return 0;
}