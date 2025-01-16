/*
Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.

Example 1:

Input: arr = [2,6,4,1]
Output: false
Explanation: There are no three consecutive odds.

Example 2:
Input: arr = [1,2,34,3,4,5,7,23,12]
Output: true
Explanation: [5,7,23] are three consecutive odds.
*/

#include <iostream>
#include <vector>
using namespace std;

bool checkThreeConsecutiveOdd(vector<int> &v){
    int count = 0;
    for (int i=0; i<v.size();i++){
        if (v[i] % 2 != 0){
            count++;
            if(count == 3){
                return true;
            }
        }
        else{
            return false;
        }
    }
    return false;
}

int main(){

    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    vector<int>v(n);
    for (int i=0;i<n;i++){
        cin>>v[i];
    }

    if (checkThreeConsecutiveOdd(v)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

    return 0;
}