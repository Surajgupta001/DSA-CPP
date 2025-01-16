#include <iostream>
using namespace std;
#include <set>
#include <vector>

int main(){

    int n;
    cout<<"Enter the size of 1st vector: ";
    cin>>n;
    vector<int>v1(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    
    int m;
    cout<<"Enter the size of 2nd vector: ";
    cin>>m;
    vector<int>v2(m);
    for(int i=0;i<m;i++){
        cin>>v2[i];
    }

    int ans_sum = 0;

    set<int>set;
    for(auto ele:v1){
        set.insert(ele);
    }
    
    for(auto ele:v2){
        if(set.find(ele)!=set.end()){
            ans_sum += ele;
        }
    }

    cout<<"Common Element Sum: "<<ans_sum<<endl;

    return 0;
}