/*
A peak element ia an element thai is strictly greater than its neighbours.Given a 0-indexed integer array nums. finds a peak element element, and return its index. If the array multiples peaks, return the index to any of the peaks. You may imagine that nums[-1]=nums[n]=-infinite.In Other words, an element is always considered to be strictly greater than a neighbour that is outside the array.

INPUT: [1,2,1,2,6,10,3]

OUTPUT: Either index 1 or index 5 are the correct output. At index 1,2 is the peak element and at index 5,10 is the peak element.
*/ 

#include <iostream>
using namespace std;
#include <vector>
int MultiplePeak(vector<int> &v, int low, int high){
    while(low<=high){
        int mid = low + (high-low)/2;
        if(mid == 0){
            if(v[mid] > v[mid+1]){
                return 0;
            }
            else{
                return 1;
            }
        }
        else if(mid = v.size()-1){
            if(v[mid] > v[mid-1]){
                return v.size()-1;
            }
            else{
                return v.size()-2;
            }
        }
        else{
            if(v[mid] > v[mid+1] & v[mid] > v[mid+1]){
                return mid;
            }
            else if(v[mid] > v[mid-1]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
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

    cout<<"Peak index is: "<<MultiplePeak(v,1,v.size()-1)<<endl;

    return 0;
}