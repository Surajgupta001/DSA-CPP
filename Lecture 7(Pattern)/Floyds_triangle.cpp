/*
1
2 3
4 5 6
7 8 9 10
*/ 
#include <iostream>
using namespace std;
int main(){
    int rows,count=1;
    cout<<"Enter the values of rows: ";
    cin>>rows;
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=i;j++){
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
    return 0;
}