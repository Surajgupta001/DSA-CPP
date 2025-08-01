/*
Rabbits in Forest - [Leetcode - 781(Medium)]
=============================================
There is a forest with an unknown number of rabbits. We asked n rabbits "How many rabbits have the same color as you?" and collected the answers in an integer array answers where answers[i] is the answer of the ith rabbit.

Given the array answers, return the minimum number of rabbits that could be in the forest.

Example 1:

Input: answers = [1,1,2]
Output: 5
Explanation:
The two rabbits that answered "1" could both be the same color, say red.
The rabbit that answered "2" can't be red or the answers would be inconsistent.
Say the rabbit that answered "2" was blue.
Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.

Example 2:

Input: answers = [10,10,10]
Output: 11 
*/ 

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int numRabbit(vector<int>& answer){
    unordered_map<int,int>m;
    int result = 0;
    for(int i=0;i<answer.size();i++){
        if(!m[answer[i] + 1]){
            result += answer[i] + 1; // We started a new gcolor group
            if(answer[i] == 0) continue;
            m[answer[i] + 1] = 1; // (1)
        }
        else{
            m[answer[i] + 1]++; // (1):2
            int key = answer[i] + 1;
            int value = m[key];
            if(key == value){
                // we found all the rabiit of the group
                // eliminate the group
                m.erase(key);
            }
        }
    }
    return result;
}

int main(){
    
    vector<int> answer1 = {1,1,2};
    vector<int> answer2 = {10,10,10};
    
    cout<<"Minimum number of rabbits in the forest for answer1: "<<numRabbit(answer1)<<endl;
    cout<<"Minimum number of rabbits in the forest for answer2: "<<numRabbit(answer2)<<endl;
    
    return 0;
}