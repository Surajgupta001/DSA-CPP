/*
* A rotated sorted array is a sorted array on which rotation operation has been performed some number of times.Give a rotated sorted array, Find the index of the minimum element in the array.Follow 0 based indexing.
* It is guaranted that all the element in the array are uniue.

INPUT: 3 4 5 1 2

OUTPUT: 3
*/ 
#include <iostream>
using namespace std;
#include <vector>

int Find_minimum_In_Sorted_Rotated (vector<int> &v, int low, int high){
    /*
    * Time: O(logn)
    * Space: O(1)
    */ 
    if(v.size() == 1) return v[0];
    if(v[low] < v[high]){ // sorted array
        return low;
    }
    // sorted rotated array
    while(low<=high){
        int mid = low + (high-low)/2;
        if(v[mid] > v[mid + 1]) return mid + 1; // terminating contition
        if(v[mid] < v[mid - 1]) return mid; // terminating contition
        if(v[mid] > v[low]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}
int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<"Minimum element in sorted rotated array is: "<<Find_minimum_In_Sorted_Rotated(v,0,v.size()-1)<<endl;

    return 0;
}

