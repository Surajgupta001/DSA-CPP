/*
First negative integer in every window of size k
=================================================

Given an array and a positive integer k, find the first negative integer for each window(contiguous subarray) of size k. If a window does not contain a negative integer, then print 0 for that window.

Examples: 1:

Input : arr[] = {-8, 2, 3, -6, 10}, k = 2
Output : -8 0 -6 -6
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6

Example 2: 
Input : arr[] = {12, -1, -7, 8, -15, 30, 16, 28} , k = 3
Output : -1 -1 -7 -15 -15 0

*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    vector<int>v(n);
    cout<<"Enter the elements of vector: ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int k;
    cout<<"Enter the size of subarray: ";
    cin>>k;

    vector<int>ans(n-k+1);
    int p = -1;
    for(int i=0;i<k;i++){
        if(v[i]<0){
            p = i;
            break;
        }
    }

    if(p!=-1){
        ans[0] = v[p];
    }
    else{ // if no negative number found in the first window
        ans[0] = 0;
    }

    // Sliding window
    int ptr1 = 1;
    int ptr2 = k;
    while(ptr2 < v.size()){
        if(p >= ptr1){
            ans[ptr1] = v[p];
        }
        else{
            p = -1;
            for(int x=ptr1; x<=ptr2; x++){
                if(v[x] < 0){
                    p = x;
                    break;
                }
            }
            if(p != -1){
                ans[ptr1] = v[p];
            }
            else{ // if no negative number found in the current window
                ans[ptr1] = 0;
            }
        }
        ptr1++;
        ptr2++;
    }
    for(int i=0;i<n-k+1;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}