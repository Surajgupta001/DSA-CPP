#include <iostream>
#include <set>
using namespace std;

int main(){

    set<int>set1;
    
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.insert(4);
    set1.insert(5);

    for(auto itr = set1.rbegin();itr != set1.rend();itr++) cout<<*itr<<" ";
    
    return 0;
}   