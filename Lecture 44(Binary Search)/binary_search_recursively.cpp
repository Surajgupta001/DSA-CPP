#include <iostream>
using namespace std;
#include <vector>

int binarySearch(vector<int> &v, int low, int high, int target){

    if(low>high) return -1;

    // int mid = (low + high)/2;
    int mid = low + (high-low)/2; // modified mid to tackle overflow

    if(v[mid]==target) return mid;
    if(v[mid]>target){
        return binarySearch(v,0,mid-1,target);
    }
    else{
        return binarySearch(v,mid+1,v.size()-1,target);
    }
}

int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int target;
    cout<<"Enter the target value: ";
    cin>>target;

    cout<<"Target value is present at index : "<<binarySearch(v,0,v.size()-1,target);

    return 0;
}