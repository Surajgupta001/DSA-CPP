/*
Search the 'target' value in 2D integer matrix of dimensions nxm and return 1 if found, else return 0. This matrix has the following properties:

1. Integer in each row are sorted from left to right.
2. The first integer of each row is graeter than the last integer of the previous row.

INPUT: 
    //  1  3  5  7
    //  10 11 16 20
    //  23 30 34 60

TARGET: 3

OUTPUT: 1

*/
#include <iostream>
using namespace std;
#include <vector>

int Search2DMatrix(vector<vector<int>> &v, int low, int high, int target){
    int m = v.size(); // number of rows
    int n = v[0].size(); // number of columns
    while(low<=high){
        int mid = low + (high-low)/2;
        int x = mid / n;
        int y = mid % n;
        if(v[x][y] == target){
            return low;
        }
        else if(v[x][y] < target){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    return false;
}
int main(){

    int m;
    cout<<"Enter the size of rows: ";
    cin>>m;

    int n;
    cout<<"Enter the size of columns: ";
    cin>>n;

    vector<vector<int>>v(m,vector<int>(n));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }

    int target;
    cout<<"Enter a target: ";
    cin>>target;
    
    cout<<"Target value is present at index is: ";
    cout<<Search2DMatrix(v,0,((v.size()*v[0].size())-1),target)<<endl;

    return 0;
}