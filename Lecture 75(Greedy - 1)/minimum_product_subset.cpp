/*
Minimum Product Subset - [GfG]
=====================================
Given array a, we have to find the minimum product possible with the subset of elements present in the array. The minimum product can be a single element also.

Examples: 

Input : a[] = { -1, -1, -2, 4, 3 }
Output : -24
Explanation : Minimum product will be ( -2 * -1 * -1 * 4 * 3 ) = -24

Input : a[] = { -1, 0 }
Output : -1
Explanation : -1(single element) is minimum product possible

Input : a[] = { 0, 0, 0 }
Output : 0
*/ 

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int minProduct(vector<int>& v){
    int countOfNeg = 0;
    int countOfZero = 0;
    int countOfPos = 0;
    int productOfPos = 1;
    int productOfNeg = 1;
    int largestNegative = INT_MIN;

    for(int i=0;i<v.size();i++){
        if(v[i] < 0){
            countOfNeg++;
            productOfNeg *= v[i];
            largestNegative = max(largestNegative, v[i]);
        }
        else if(v[i] == 0) countOfZero++;
        else{
            countOfPos++;
            productOfPos *= v[i];
        }
    }
    if(countOfNeg == 0){
        if(countOfZero > 0) return 0;
        else{
            auto itr = min_element(v.begin(), v.end());
            return *itr;
        }
    }
    else{
        if(countOfNeg % 2 == 0){
            // Even
            return (productOfNeg / largestNegative) * productOfPos;
        }
        else{
            // Odd
            return productOfNeg * productOfPos;
        }
    }
}

int main(){

    vector<int> v = {-2,-3,1,4,-2,-5};
    
    cout<<"Minmum Product Subset is: "<<minProduct(v) << endl;
    
    return 0;
}