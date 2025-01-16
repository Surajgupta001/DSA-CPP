/*
Finding 3-Digit Even Numbers - [Leetcode - 2094(Medium)]
===========================================================

You are given an integer array digits, where each element is a digit. The array may contain duplicates.

You need to find all the unique integers that follow the given requirements:

The integer consists of the concatenation of three elements from digits in any arbitrary order.
The integer does not have leading zeros.
The integer is even.
For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.

Return a sorted array of the unique integers.

Example 1:

Input: digits = [2,1,3,0]
Output: [102,120,130,132,210,230,302,310,312,320]
Explanation: All the possible integers that follow the requirements are in the output array. 
Notice that there are no odd integers or integers with leading zeros.

Example 2:

Input: digits = [2,2,8,8,2]
Output: [222,228,282,288,822,828,882]
Explanation: The same digit can be used as many times as it appears in digits. 
In this example, the digit 8 is used twice each time in 288, 828, and 882. 

Example 3:

Input: digits = [3,7,5]
Output: []
Explanation: No even integers can be formed using the given digits.
*/ 
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

// ================ 2ND APPROACH USING HASHSET =============>
vector<int> findEvenNumbers(vector<int>& v) {
    int n = v.size();
    vector<int> ans;
    multiset<int> s;  // Use multiset to handle duplicates
    for(auto ele : v) s.insert(ele);
    
    for (int i=100; i<=999; i+= 2) {
        int x = i;
        int a = x % 10; // ones place digit
        x /= 10;
        int b = x % 10; // tens place digit
        x /= 10;
        int c = x;      // hundreds place digit
        
        // Check if we can form the number using the digits in the multiset
        if (s.count(a) > 0) {
            s.erase(s.find(a)); // Remove one occurrence of a
            if (s.count(b) > 0) {
                s.erase(s.find(b)); // Remove one occurrence of b
                if (s.count(c) > 0) {
                    ans.push_back(i); // Found a valid even number
                }
                s.insert(b); // Reinsert b back into the multiset
            }
            s.insert(a); // Reinsert a back into the multiset
        }
    }   
    return ans;
}

int main(){

    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    vector<int>v(n);
    cout<<"Enter the elements of vector: ";
    for(int i=0;i<n;i++) cin>>v[i];

    vector<int>result = findEvenNumbers(v);
    cout<<"Even numbers form by the digits of the given vector are: ";
    for(auto ele:result) cout<<ele<<" ";

    return 0;
}

/*
================ 2ND APPROACH USING HASHMAP =============>

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> findEvenNumbers(vector<int> &v){
    int n = v.size();
    vector<int> ans;
    unordered_map<int, int> m;
    for(auto ele:v)
        m[ele]++; // counting frequency

    for (int i = 100; i <= 999; i += 2){
        int x = i;
        int a = x%10; // ones place digit
        x /= 10;
        int b = x%10; // tens place digit
        x /= 10;
        int c = x; // hundres place digit
        if (m.find(a) != m.end()){
            m[a]--;
            if(m[a] == 0) m.erase(a);
            if (m.find(b) != m.end()){
                m[b]--;
                if(m[b] == 0) m.erase(b);
                if (m.find(c) != m.end()) ans.push_back(i);
                m[b]++;
            }
            m[a]++;
        }
    }
    return ans;
}

int main(){

    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    vector<int>v(n);
    cout<<"Enter the elements of vector: ";
    for(int i=0;i<n;i++) cin>>v[i];

    vector<int>result = findEvenNumbers(v);
    cout<<"Even numbers form by the digits of the given vector are: ";
    for(auto ele:result) cout<<ele<<" ";

    return 0;
}
*/  