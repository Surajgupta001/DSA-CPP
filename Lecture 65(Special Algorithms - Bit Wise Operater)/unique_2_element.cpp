#include <iostream>
#include <vector>
using namespace std;

void findUnique(vector<int>&v,int n){
    int result = 0;
    for(int i=0;i<n;i++){
        result = result ^ v[i];
    }
    int temp = result;
    int k = 0;
    while(true){
        if((temp & 1) == 1){
            break;
        }
        temp = temp >> 1;
        k++;
    }
    int retval = 0;
    for(int i=0;i<n;i++){
        int num = v[i];
        if(((num >> k) & 1) == 1){
            retval = retval ^ num;
        }
    }
    cout<<retval<<" ";
    result = retval ^ result;
    cout<<result<<" ";
}

int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int>v(n);
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<"Two element appear only once are: ";

    findUnique(v,n);

    return 0;
}