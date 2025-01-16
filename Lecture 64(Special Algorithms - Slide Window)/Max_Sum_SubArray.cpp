/*
Maximum sum subarray of size K

Example 1:

input : nums = [2,3,4,4,5], k = 4;
output : 16
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

    int MaxSum = 0;
    int maxIndex = -1;

    for(int i=0;i<n-k;i++){ // Total No.of operation: n-k+1
        int sum = 0;
        for(int j=i;j<i+k;j++){ // k times
            sum = sum + v[j];
        }
        if(sum > MaxSum){
            MaxSum = sum;
            maxIndex = i;
        }
    }

    // TNo. = (n-k+1)*k
    // TIME: O(k*n)

    cout<<"Starting index of maximum sum subarray is: "<<maxIndex<<endl;
    cout<<"Maximum sum subarray of size "<<k<<" is: "<<MaxSum<<endl;

    return 0;
}



#include <iostream>
#include <vector>
#include <climits>
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

    int maxSum = INT_MIN;
    int maxIndex = 0;
    int sum = 0;
    for(int i=0;i<k;i++){ // Time: k
        sum += v[i];
    }
    maxSum = sum;
    // sliding window
    int ptr1 = 1;
    int ptr2 = k;
    while(ptr2 < n){ // Time: n-k;
        sum = sum + v[ptr2] - v[ptr1-1];
        if(maxSum < sum){
            maxSum = sum;
            maxIndex = ptr1;
        }
        ptr1++;
        ptr2++;
    }
    cout<<"Starting index of maximum sum subarray is: "<<maxIndex<<endl;
    cout<<"Maximum sum subarray of size "<<k<<" is: "<<maxSum<<endl;

    return 0;
}