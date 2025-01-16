#include <iostream>
using  namespace std;
#include <unordered_set>
int main(){

    unordered_set<int>set;

    set.insert(3);
    set.insert(1);
    set.insert(2);
    set.insert(1);

    for(auto itr = set.begin(); itr != set.end();itr++){
        cout<<*itr<<" ";
    }

    return 0;
} 