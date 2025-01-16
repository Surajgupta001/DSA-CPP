#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
    
    unordered_multiset<int> set;

    set.insert(4);
    set.insert(8);
    set.insert(3);
    set.insert(1);
    set.insert(4);

    for(auto value:set){
        cout<<value<<" ";
    }

    return 0;
}