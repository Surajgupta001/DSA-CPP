#include <iostream>
#include <unordered_map>
using namespace std;

int main(){

    unordered_map<int,string>record;

    record.insert(make_pair(2305173,"Suraj"));
    record.insert(make_pair(2305128,"HaraPriya"));
    record.insert(make_pair(2305154,"Sankalpa"));
    record.insert(make_pair(2305155,"Satyajeet"));

    for(auto itr=record.begin();itr!=record.end();itr++){
        cout<<"Roll No. - "<<itr->first<<endl;
        cout<<"Name - "<<itr->second<<endl;
    }
    cout<<endl;

    return 0;
}