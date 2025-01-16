/*

REDUCING DISHES - (LEETCODE - 1402)
=====================================
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

 

Example 1:

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.

Example 2:

Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)

Example 3:

Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People do not like the dishes. No dish is prepared.
*/ 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSatisfaction(vector<int>&satisfaction){
    int n = satisfaction.size();

    // soring array
    sort(satisfaction.begin(),satisfaction.end());

    int suf[n];
    suf[n-1] = satisfaction[n-1];
    for(int i=n-2; i>=0; i--){
        suf[i] = (suf[i+1] + satisfaction[i]);
    }

    // find the pivot index
    int index = -1;
    for(int i=0; i<n; i++){
        if(suf[i] >= 0){
            index = i;
            break;
        }
    }
    if(index == -1) return 0;

    // max sum of like-time coefficent 
    int x = 1;
    int maxSum = 0;
    for(int i=index; i<n; i++){
        maxSum += (satisfaction[i]*x);
        x++;
    }
    return maxSum;
}

int main(){
    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    vector<int>v(n);
    cout<<"Enter the elements of vector: ";
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    cout<<"Maximum satisfaction is "<<maxSatisfaction(v)<<endl;
    return 0;
}