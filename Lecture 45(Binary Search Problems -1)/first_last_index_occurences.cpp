/*
Given an array of integer 'a' that is sorted in non-decreasing order.Find the first and the last position of the given 'target' element un the sorted array. Follow 0-based indexing.

If 'target' is not found in the array, return[-1,1].

INPUT:
Array = [1,2,3,3,3,5,11], target = 3;

Output: [2,4].
*/

#include <iostream>
using namespace std;
#include <vector>
int lowerbound(vector<int> &v, int low, int high, int target){ // first index >= target.
/*
* Time: O(logn)
* Space: O(1)
*/ 
    int ans = -1;
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (v[mid] >= target){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
}

int upperbound(vector<int> &v, int low, int high, int target){ // first index > target.
/*
* Time: O(logn)
* Space: O(1)
*/ 
    int ans = -1;
    while (low <= high){
        int mid = low + (high - low) / 2;

        if (v[mid] > target){
            ans = mid;
            high = mid - 1; // discard right
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
}

int main(){

    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int target;
    cout << "Enter the value of target: ";
    cin >> target;

    vector<int> result;
    int lb = lowerbound(v, 0, v.size() - 1, target);
    if (v[lb] != target){
        result.push_back(-1);
        result.push_back(-1);
    }
    else{
        int ub = upperbound(v, 0, v.size() - 1, target);
        result.push_back(lb);
        result.push_back(ub - 1);
    }

    cout <<"First occurrence is: "<<result[0]<<endl;
    cout<<"Last occurrence is: "<<result[1];

    return 0;
}
