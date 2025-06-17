#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// function to finding next greater element to the right
vector<int>NGER(vector<int> &v){
    
    vector<int> output(v.size(),-1);

    stack<int> st; // indexes

    st.push(0);

    for(int i=1;i<v.size();i++){
        while(!st.empty() && v[i] > v[st.top()]){ // next greater element.
            output[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }
    return output;
}

// function to finding next smaller element to the right
vector<int> NSER(vector<int> &v) {
    vector<int> output(v.size(), -1);
    stack<int> st; // indexes

    for (int i = 0; i < v.size(); i++) {
        while (!st.empty() && v[i] < v[st.top()]) {
            output[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }
    return output;
}

// function to finding next greater element to the left
vector<int> NGEL(vector<int> &v) {
    vector<int> output(v.size(), -1);
    stack<int> st; // indexes

    st.push(v.size() - 1);
    for (int i = v.size() - 2; i >= 0; i--) {
        while (!st.empty() && v[i] > v[st.top()]) {
            output[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }
    return output;
}

// function to finding next smaller element to the left
vector<int> NSEL(vector<int> &v) {
    vector<int> output(v.size(), -1);
    stack<int> st; // indexes

    st.push(v.size() - 1);
    for (int i = v.size() - 2; i >= 0; i--) {
        while (!st.empty() && v[i] < v[st.top()]) {
            output[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }
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
    
    // function calling next greater element to the right
    vector<int>result_nger = NGER(v);
    cout<<"Next Greater Element to Right: ";
    for(int i=0;i<result_nger.size();i++){
        cout<<result_nger[i]<<" ";
    }
    cout<<endl;

    // function calling next smaller element to the right
    vector<int>result_nser = NSER(v);
    cout<<"Next Smaller Element to Right: ";
    for(int i=0;i<result_nser.size();i++){
        cout<<result_nser[i]<<" ";
    }
    cout<<endl;

    // function calling next greater element to the left
    vector<int>result_ngel = NGEL(v);
    cout<<"Next Greater Element to Left: ";
    for(int i=0;i<result_ngel.size();i++){
        cout<<result_ngel[i]<<" ";
    }
    cout<<endl;

    // function calling next smaller element to the left
    vector<int>result_nsel = NSEL(v);
    cout<<"Next Smaller Element to Left: ";
    for(int i=0;i<result_nsel.size();i++){
        cout<<result_nsel[i]<<" ";
    }
    cout<<endl;

    return 0;
}