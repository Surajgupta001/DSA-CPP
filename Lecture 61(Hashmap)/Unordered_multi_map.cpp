#include <iostream>
using namespace std;
#include <unordered_map>

int main(){

    unordered_multimap<string,int>directory;

    directory.insert(make_pair("Harapriya",2305128));
    directory.insert(make_pair("Suraj",2305173));
    directory.insert(make_pair("Sankalp",2305154));
    directory.insert(make_pair("Satyajeet",2305155));

    for(auto element:directory){
        cout<<"Name - "<<element.first<<endl;
        cout<<"Roll No. - "<<element.second<<endl;
    }

    return 0;
}