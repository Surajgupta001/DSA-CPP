/*
You are given an array of integer nums, there is a sliding window of size k which is moving from the very left of the array to the very right.

You can only see the K numbers in the windows.

Each time the sliding window move right by one position.

Return the max sliding window which basically contains the max element in each window;
*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>&v, int k) {
    vector<int> res;
    deque<int> dq;
    
    for (int i = 0; i < v.size(); i++) {
        // Remove elements from the back of the deque that are smaller than the current element
        while (!dq.empty() && v[dq.back()] < v[i]) {
            dq.pop_back();
        }
        
        // Add the current element to the back of the deque
        dq.push_back(i);
        
        // Remove elements from the front of the deque that are out of the current window
        if (dq.front() == i - k) {
            dq.pop_front();
        }
        
        // Add the maximum element in the current window to the result
        if (i >= k - 1) {
            res.push_back(v[dq.front()]);
        }
    }
    return res;
}
int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<v.size();i++){
        cin>>v[i];
    }

    int k;
    cout<<"Enter slide window number: ";
    cin>>k;
    
    vector<int> res = maxSlidingWindow(v, k);

    cout<<"Maximum slide window number: ";
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    
    return 0;
}