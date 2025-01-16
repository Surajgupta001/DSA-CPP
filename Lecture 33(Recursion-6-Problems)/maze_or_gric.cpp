#include <iostream>
using namespace std;

int function(int i, int j, int m, int n){
    if(i==m-1 && j==n-1) return 1;
    if(i>=m || j>=n) return 0;
    return function(i,j+1,m,n) + function(i+1,j,m,n);
}
int main(){

    int i;
    cout<<"Enter ith rows of maze: ";
    cin>>i;

    int j;
    cout<<"Enter jth columns of maze: ";
    cin>>j;

    int m;
    cout<<"Enter number of rows of the maze: ";
    cin>>m;

    int n;
    cout<<"Enter number of columns of the maze: ";
    cin>>n;

    cout<<"NoOfways: "<<function(i,j,m,n);
    return 0;
}