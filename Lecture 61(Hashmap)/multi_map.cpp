#include <iostream>
using namespace std;
#include <map>

int main(){

    multimap<string,int>directory;

    directory.insert(make_pair("Harapriya",2305128));
    directory.insert(make_pair("Suraj",2305173));
    directory.insert(make_pair("Sankalp",2305154));
    directory.insert(make_pair("Sankalp",2305154));

    for(auto element:directory){
        cout<<"Name - "<<element.first<<endl;
        cout<<"Roll No. - "<<element.second<<endl;
    }
    cout<<endl;

    cout<<"No. of Entries: "<<directory.count("Sankalp")<<endl;
    
    return 0;
}