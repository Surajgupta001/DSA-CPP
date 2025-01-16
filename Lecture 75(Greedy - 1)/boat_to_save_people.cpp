/*
Boats to Save People - [Leetcode-881(Medium)]
==============================================
You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)

Example 2:

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)

Example 3:

Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numRescueBoat(vector<int>& people, int limit){
    sort(people.begin(),people.end());
    int i = 0;
    int j = people.size()-1;
    int boat = 0;

    while(i <= j){
        if(people[i] + people[j] <= limit){
            boat++; // Alocate a boat to the pair
            i++;
            j--;
        }
        else{
            boat++; // Alocate a boat to the haviest
            j--;
        }
    }
    return boat;
}

int main(){

    vector<int> people = {3,2,2,1};
    
    int limit = 3;
    cout<<"Number of Rescue Boat is: "<<numRescueBoat(people,limit) << endl;
    
    return 0;
}