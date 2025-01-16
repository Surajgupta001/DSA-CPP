/*
Find the square root of the given non-negative value x.Round it off to the nearest floor integer value.
INPUT:4
OUTPUT:2

INPUT:11
Output:3
*/ 

#include <iostream>
using namespace std;
int sqrt(int x){
    /*
    Time: O(logx)
    Space: O(1)
    */ 
    int low = 1;
    int high = x;

    int ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(mid*mid <= x){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<"square root the number is: "<<sqrt(n);

    return 0;
}