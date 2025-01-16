#include <iostream>
using namespace std;
int main(){
    cout<<"1st matrix order: "<<endl;
    int m;
    cout<<"Enter the rows of 1st matrix: ";
    cin>>m;
    int n;
    cout<<"Enter the column of 1st matrix: ";
    cin>>n;

    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    cout<<"2nd matrix order: "<<endl;
    int p;
    cout<<"Enter the rows of 2nd matrix: ";
    cin>>p;
    int q;
    cout<<"Enter the column of 2nd matrix: ";
    cin>>q;
    
    int brr[p][n];
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            cin>>brr[i][j];
        }
    }

    // check
    if(n!=p){
        cout<<"The entered matrix caanot multiplied for this input.";
    }
    else{
        // multiplication
        int res[m][q];
        for(int i=0;i<m;i++){
            for(int j=0;j<q;j++){
                res[i][j]=0;
                // i row of arr[][] and j column of brr[][]
                for(int k=0;k<n;k++){
                    res[i][j] = res[i][j] + (arr[i][k]*brr[k][j]);
                }
            }
        }
        // Disply result
        cout<<"The resultant matrix are:"<<endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<q;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}