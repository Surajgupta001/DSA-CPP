#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    // create a vector copy
    // i.e. extra space occupied
    vector<int>ans = v;

    reverse(ans.begin(),ans.end());

    if(ans == v){
        cout<<"It is palindrome.";
    }
    else{
        cout<<"It is not palindrome.";
    }
    
    return 0;
}