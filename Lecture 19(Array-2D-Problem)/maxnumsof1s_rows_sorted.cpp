#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// 0 1 1 1
// 0 0 0 1
// 0 0 1 1

// maxOnes = min_value
// maxOnesRow = -1
// columns = 4
// numberOfOnes = columns - j => 4 - 1 = 3

int maximumOnesrows(vector<vector<int>> &v){
    int maxOnes = INT_MIN; // climits
    int maxOnesRow = -1; // index
    int columns = v[0].size();

    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]==1){
                int numberOfOnes = columns - j;
                if(numberOfOnes > maxOnes){
                    maxOnes = numberOfOnes;
                    maxOnesRow = i;
                }
                break;
            }
        }
    }
    return maxOnesRow;
}

int main(){

    cout<<"Enter the matrix: ";
    int m;
    cout<<"Enter the size of rows: ";
    cin>>m;
    int n;
    cout<<"Enter the size of column: ";
    cin>>n;

    vector<vector<int>>vec(n,vector<int>(m));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>vec[i][j];
        }
    }

    cout<<"Maximum numners of 1s is ith rows: ";
    int result = maximumOnesrows(vec);
    cout<<result<<endl;

    return 0;
}