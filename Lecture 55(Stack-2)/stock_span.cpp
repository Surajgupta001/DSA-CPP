/*
Given a series of N daily price quoted for a stock we need to calculate the span of the stock's price of all N days. The span of the stock's price in oner day is the maximum number of consecutive days(starting from that day and going backward) for which the stock price was less than or equal to the price of tha day.
*/ 
#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <algorithm>

// function of Previous Greater Element
vector<int>PGE(vector<int>&v){
    int n = v.size();
    
    // reversing vector
    reverse(v.begin(), v.end());

    vector<int>output(n,-1);
    stack<int> st; // indexes
    st.push(0);
    for(int i=0;i<n;i++){
        while(!st.empty() && v[i] > v[st.top()]){
            output[st.top()] = n - i - 1; // because after reverse the indexes wiil change
            st.pop();
        }
        st.push(i);
    }
    // reversing output
    reverse(output.begin(), output.end());
    reverse(v.begin(), v.end());
    return output;
}
int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    // function calling
    vector<int>result = PGE(v);
    for(int i=0;i<result.size();i++){
        cout<<(i - result[i])<<" ";
    }

    return 0;
}