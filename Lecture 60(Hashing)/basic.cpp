// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Hashing{

    public:
    
    vector<list<int>>hashtable;
    int bucket;
    
    // constructor
    Hashing(int size){
        bucket = size;
        hashtable.resize(size);
    }

    int hashValue(int key){
        return key%bucket; // division method
    }

    void addKey(int key){
        int idx = hashValue(key);
        hashtable[idx].push_back(key);
    }

    list<int>::iterator searchKey(int key){
        int idx = hashValue(key);
        return find(hashtable[idx].begin(),hashtable[idx].end(),key);
    }

    void deleteKey(int key){
        int idx = hashValue(key);
        if(searchKey(key)!=hashtable[idx].end()){ // key is present
            hashtable[idx].erase(searchKey(key));
            cout<<key<<" is deleted"<<endl;
        }
        else{
            cout<<"Key is not present in the hashtable"<<endl;
        }
    }
};
int main(){

    Hashing h(10);

    h.addKey(5);
    h.addKey(9);
    h.addKey(3);

    h.deleteKey(3);

    return 0;
}