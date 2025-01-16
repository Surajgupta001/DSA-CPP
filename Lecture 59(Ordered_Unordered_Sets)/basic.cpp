#include <iostream>
using namespace std;
#include <set>

int main(){

    set<int> set1;

    set<int, greater<int>>set2;

    // insertion of element
    set1.insert(3);
    set1.insert(2);
    set1.insert(1);
    set1.insert(4);
    set1.insert(5);

    set2.insert(3);
    set2.insert(2);
    set2.insert(1);

    cout<<"Size: "<<set1.size()<<endl;

    set1.insert(3);

    // size remain same because duplicate value is added.
    // and seta contain only unique values.

    cout<<"Size: "<<set1.size()<<endl;

    // set<int>::iterator itr;
    
    cout<<"Increasing Order/By-default Order: ";
    for(auto itr = set1.begin();itr!=set1.end();itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;

    // // 2nd way
    // for(auto value:set1){
    //     cout<<value<<" ";
    // }
    // cout<<endl;

    cout<<"Decreasing Order: ";
    for(auto itr = set2.begin();itr!=set2.end();itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;

    // Deletion of element
    cout<<"Deletion of element: ";
    // set1.erase(4);

    // auto itr = set1.begin();
    // advance(itr,3);
    // set1.erase(itr);

    auto start_itr = set1.begin();
    start_itr++;

    auto end_itr = set1.begin();
    advance(end_itr,3); 

    set1.erase(start_itr,end_itr);

    for(auto itr = set1.begin();itr!=set1.end();itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;
     
    return 0;
}