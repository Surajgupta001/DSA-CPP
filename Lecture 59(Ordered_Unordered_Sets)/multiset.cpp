#include <iostream>
using namespace std;
#include <set>
int main(){

    multiset<int>set;

    multiset<int,greater<int>>set1;

    set.insert(1);
    set.insert(3);
    set.insert(2);
    set.insert(3);
    
    set1.insert(1);
    set1.insert(3);
    set1.insert(2);
    set1.insert(3);

    

    for(auto itr = set.begin();itr!=set.end();itr++){
        cout<<*itr<<" ";
    }

    cout<<endl;

    for(auto itr = set1.begin();itr!=set1.end();itr++){
        cout<<*itr<<" ";
    }

    return 0;
}