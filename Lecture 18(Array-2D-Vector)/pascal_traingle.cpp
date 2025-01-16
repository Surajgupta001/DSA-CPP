#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
OBSERVATION:
1. columns = rows - number;
2. a[i][j] = iCj;
3. a[i][j] = a[i-1][j] + a[i-1][j-1];
*/ 
vector<vector<int>>Pascal_triangle(int n){
    vector<vector<int>>pascal(n);
    for(int i=0;i<n;i++){
        pascal[i].resize(i+1);
        for(int j=0;j<i+1;j++){
            if(j==0 || j==i){
                pascal[i][j]=1;
            }
            else{
                pascal[i][j]=pascal[i-1][j] + pascal[i-1][j-1];
            }
        }
    }
    return pascal;
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<vector<int>>ans;
    ans = Pascal_triangle(n);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
