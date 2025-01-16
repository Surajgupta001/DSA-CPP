/*
GRUMPY BOOKSTORE OWNER - (LEETCODE-1052)
==========================================

There is a bookstore owner that has a store open for n minutes. You are given an integer array customers of length n where customers[i] is the number of the customers that enter the store at the start of the ith minute and all those customers leave after the end of that minute.

During certain minutes, the bookstore owner is grumpy. You are given a binary array grumpy where grumpy[i] is 1 if the bookstore owner is grumpy during the ith minute, and is 0 otherwise.

When the bookstore owner is grumpy, the customers entering during that minute are not satisfied. Otherwise, they are satisfied.

The bookstore owner knows a secret technique to remain not grumpy for minutes consecutive minutes, but this technique can only be used once.

Return the maximum number of customers that can be satisfied throughout the day.

Example 1:

Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3

Output: 16

Explanation:

The bookstore owner keeps themselves not grumpy for the last 3 minutes.

The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.

Example 2:

Input: customers = [1], grumpy = [0], minutes = 1

Output: 1
*/ 
#include <iostream>
#include <vector>
using namespace std;

int maxSatisfied(vector<int>& v, vector<int>& grumpy, int minutes){
    int k = minutes;

    int prevLoss = 0;
    for(int i=0;i<k;i++){
       if(grumpy[i] == 1) prevLoss += v[i]; 
    }

    int maxLoss = prevLoss;
    int maxIndex = 0;
    int ptr1 = 1; // i
    int ptr2 = k; // j

    while(ptr2 < v.size()){
        int currLoss = prevLoss;
        if(grumpy[ptr2] == 1) currLoss += v[ptr2];
        if(grumpy[ptr1-1] == 1) currLoss -= v[ptr1-1];
        if(maxLoss < currLoss){
            maxLoss = currLoss;
            maxIndex = ptr1;
        }
        prevLoss = currLoss;
        ptr1++;
        ptr2++;
    }

    // Filling 0s in the grumpy array window
    for(int i=maxIndex;i<(maxIndex + k);i++){
        grumpy[i] = 0;
    }

    // Maximum satisfaction
    int sum = 0;
    for(int i=0;i<v.size();i++){
        if(grumpy[i] == 0) sum += v[i]; // Changed v[ptr1] to v[i]
    }
    
    return sum;
}

int main(){

    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    vector<int>customers(n);
    cout<<"Enter the elements of Customers: ";
    for(int i=0;i<n;i++){
        cin>>customers[i];
    }

    vector<int>grumpy(n);
    cout<<"Enter the elements of Grumpy: ";
    for(int i=0;i<n;i++){
        cin>>grumpy[i];
    }

    int minutes;
    cout<<"Enter the minutes: ";
    cin>>minutes;


    int result = maxSatisfied(customers, grumpy, minutes);
    cout<<"Maximum number of customers that can be satisfied: "<<result<<endl;

    return 0;
}