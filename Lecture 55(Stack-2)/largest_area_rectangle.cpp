#include <iostream>
using namespace std;
#include <stack>
#include <vector>
#include <climits>

int histoGram(vector<int> &v){

    stack<int> st; // indexes

    int ans = INT_MIN;

    st.push(0);

    for (int i = 1; i < v.size(); i++){

        while (!st.empty() && v[i] < v[st.top()]){// next greater element.
            int element = v[st.top()]; // current bar to be removed and whose ans will be calculated.
            st.pop();
            int nsi = i;
            int psi = (st.empty()) ? -1 : st.top();
            ans = max(ans, element * (nsi - psi - 1));
        }
        st.push(i);
    }
    while (!st.empty()){
        int element = v[st.top()];
        st.pop();
        int nsi = v.size();
        int psi = (st.empty()) ? -1 : st.top();
        ans = max(ans, element * (nsi - psi - 1));
    }
    return ans;
}
int main(){

    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << "Largest Area Rectangle: " << histoGram(v) << endl;

    return 0;
}