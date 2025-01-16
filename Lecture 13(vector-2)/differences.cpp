/*
Find the difference between the sum of element at even indices to the sun of element at odd indices.
*/ 

#include <iostream>
using namespace std;
#include <vector>

int main(){
    int arr[] = {1,2,1,2,1,2};
    int ansum = 0;
    for(int i=0;i<6;i++){
        if(i%2==0){
            ansum+=arr[i];
        }
        else{
            ansum-=arr[i];
        }
    }
    cout<<ansum<<endl;
    
    return 0;
}