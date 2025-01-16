/*
Given an array of integer, print sums of all subsets in it. Output sum can be printed in any order.

INPUT: arr[] = {2,3}
OUTPUT: 0 2 3 5

INPUT: = {2,4,5}
OUTPUT: = {0 2 4 5 6 7 9 11}
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void function (int *arr, int n, int i, int sum, vector<int> &result){
    if(i==n) { // base value
    return result.push_back(sum);
    }
    function(arr,n,i+1,sum+arr[i],result); // pick the ith element
    function(arr,n,i+1,sum,result); // donot pick the ith element
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

    vector<int> result;

    cout<<"Sum of subset of array's element are: "<<endl;
    function(arr,n,0,0,result);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}