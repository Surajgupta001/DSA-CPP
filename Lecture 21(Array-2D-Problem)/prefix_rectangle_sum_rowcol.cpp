/*
Q. Given a matrix 'a' of dimension nXm and 2 coordinate (l1,r1) and (l2,r2).Return the sum of the rectangle from (l1,r1) to  (l2,r2).
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rectangle_sum(vector<vector<int>> &matrix,int l1, int r1, int l2, int r2){

    int sum = 0;
    // input prefix sum array row-wise
    for(int i=0;i<matrix.size();i++){
        for(int j=1;j<matrix[0].size();j++){
            matrix[i][j] += matrix[i][j-1];  
        }
    }

    // input prefix sum array column-wise;
    for(int i=1;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            matrix[i][j]+=matrix[i-1][j];
        }
    }

    // printing prefix sum array row wise
    cout<<"Printed prefix row wise sum of Matrix: "<<endl;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    // printing prefix sum array column wise
    cout<<"Printed prefix column wise sum of Matrix: "<<endl;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    int top_sum = 0, left_sum = 0, toplet_sum = 0;
    if(l1!=0) top_sum = matrix[l1-1][r2];
    if(r1!=0) left_sum = matrix[l2][r1-1];
    if(l1!=0 && r1!=0) toplet_sum = matrix[l1-1][r1-1];

    sum = matrix[l2][r2] - top_sum - left_sum + toplet_sum;

    return sum;

}
int main(){

    int m;
    cout<<"Enter the size of row: ";
    cin>>m;

    int n;
    cout<<"Enter the size of column: ";
    cin>>n;

    cout<<"Enter the all element of matrix: "<<endl;

    vector<vector<int>>matrix(m,vector<int>(n));
    // user input
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }

    int l1;
    cout<<"Enter the l1 coordinate of matrix: ";
    cin>>l1;

    int r1;
    cout<<"Enter the r1 coordinate of matrix: ";
    cin>>r1;

    int l2;
    cout<<"Enter the l2 coordinate of matrix: ";
    cin>>l2;

    int r2;
    cout<<"Enter the r2 coordinate of matrix: ";
    cin>>r2;


    // Display output
    cout<<"Printing 2D Arrays are: "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    int sum = rectangle_sum(matrix,l1,r1,l2,r2);
    cout<<"sum of prefix 2D Array are: "<<sum;
    return 0;
}