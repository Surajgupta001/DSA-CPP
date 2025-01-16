#include <iostream>
using namespace std;
#include <stack>
#include <vector>

// function to finding next greater element
vector<int>NGE(vector<int> &v){
    
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

// function to finding next smaller element
vector<int>NSE(vector<int> &v){
    
    vector<int> output(v.size(),-1);

    stack<int> st; // indexes

    st.push(0);

    for(int i=1;i<v.size();i++){
        
        while(!st.empty() && v[i] < v[st.top()]){ // next greater element.
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
    
    // function calling next greater element
    vector<int>result_nge = NGE(v);
    cout<<"Next Greater Element: ";
    for(int i=0;i<result_nge.size();i++){
        cout<<result_nge[i]<<" ";
    }

    cout<<endl;

    // function calling next smaller element
    vector<int>result_nse = NSE(v);
    cout<<"Next Smaller Element: ";
    for(int i=0;i<result_nse.size();i++){
        cout<<result_nse[i]<<" ";
    }

    return 0;
}