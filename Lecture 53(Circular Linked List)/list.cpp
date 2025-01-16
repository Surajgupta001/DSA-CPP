#include <iostream>
#include <list>
using namespace std;
int main(){

    list <int> l1 = {1,2,3,4};
    //list <int> :: iterator itr;
    auto itr = l1.begin();
    // l1.end() - iterator pointing to the memory location after 4.

    // cout<<*itr<<endl;

    // auto rev_itr = l1.rbegin();
    // cout<<*rev_itr<<endl;
    // // l1.rend() - iterator pointing yo thr memory location after 1

    // advance(itr,2);
    // cout<<*itr<<endl;

    // Traversal in a list
    // 1. USING RANGE-BASED LOOP
    for(auto num: l1){
        cout<<num<<endl;
    }

    // 2. UISNG ITERATOR
    for(auto itr = l1.begin(); itr != l1.end(); itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;

    // Reverse traversal
    for(auto itr = l1.rbegin(); itr != l1.rend(); itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;

    // inserting element
    advance(itr,2);
    l1.insert(itr,5);
    
    for(auto itr = l1.begin(); itr != l1.end(); itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;

    l1.insert(itr,3,5);
    for(auto itr = l1.begin(); itr != l1.end(); itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;
    
    auto l = l1.begin();
    auto r = l1.end();

    l1.insert(itr,l,r);

    advance(itr,2); // now is pointing to 3

    for(auto itr = l1.begin(); itr != l1.end(); itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;

    // deletion of element
    auto s_itr = l1.begin();
    advance(s_itr,2); // s_itr pointing to 3rd element
    auto e_itr = l1.begin();
    advance(e_itr,4); // e_itr pointing to 5th element

    l1.erase(s_itr,e_itr);
    for(auto itr = l1.begin(); itr != l1.end(); itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;

    return 0;
}