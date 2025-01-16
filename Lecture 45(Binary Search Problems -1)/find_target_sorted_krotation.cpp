/*
Given the rotated sorted array of integers, which contains djstinct element, and an integer target, return the index of target if it in the array. Otherwise return -1;

INPUT: 3 4 5 1 2

TARGET: 4

OUTPUT: 1
*/ 
#include <iostream>
using namespace std;
#include <vector>

int find_target_sorted_krotation(vector<int> &v, int low, int high, int target){
    while(low<=high){
        int mid = low + (high-low)/2;
        if(v[mid] == target) return mid;
        if(v[mid] > v[low]){
            if(target >= v[low] && target <= v[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(target >= v[mid] && target <= v[low]){
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
    int target;
    cout<<"Enter a target: ";
    cin>>target;
    
    cout<<"Index of target is: "<<find_target_sorted_krotation(v,0,v.size()-1,target);

    return 0;
}