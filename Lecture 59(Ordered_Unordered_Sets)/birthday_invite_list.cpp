#include <iostream>
using namespace std;
#include <set>
int main(){

    set<string> inviteList;

    int n;
    cout<<"Enter a number: ";
    cin>>n;

    while(n--){
        string name;
        cin>>name;
        inviteList.insert(name);
    }
    
    cout<<"Printing invite list: "<<endl;
    for(auto name:inviteList){
        cout<<name<<endl;
    }

    return 0;
}