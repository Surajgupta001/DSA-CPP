#include <iostream>
using namespace std;
#include <unordered_set>

int main(){

    int n,p,q;
    cin>>n>>p>>q;

    unordered_set<int>set;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){

            int correct = i;
            int incorrect = j;
            int unattended = n+(i-j);

            if(unattended>=0){
                int score = correct*p + incorrect*q;
                set.insert(score);
            }
            else{
                break;
            }
        }
    }
    for(auto score:set){
        cout<<score<<" ";
    }
    cout<<endl;
    cout<<"Ans: "<<set.size()<<endl;
}