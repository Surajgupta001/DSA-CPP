#include <iostream>
#include <map>
using namespace std;
int main(){
    
    map<string,int>directory;

    directory["Suraj"] = 2305173;
    directory["HaraPriya"] = 2305128;
    directory["Sankalp"] = 2305154;
    directory["Satyajeet"] = 2305155;

    // 1st way
    for(auto element:directory){
        cout<<"Name - "<<element.first<<endl;
        cout<<"Roll No. - "<<element.second<<endl;
    }
    cout<<endl;
    
    // 2nd way
    // Reverse Ordered
    for(auto itr=directory.rbegin();itr!=directory.rend();itr++){
        cout<<"Name - "<<itr->first<<endl;
        cout<<"Roll No. - "<<itr->second<<endl;
    }
    cout<<endl;

    return 0;
}