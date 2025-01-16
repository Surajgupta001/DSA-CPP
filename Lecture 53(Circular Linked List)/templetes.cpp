#include <iostream>
using namespace std;

template<typename t>
class node{ // templete class
    public:
    t value;
    node *next;

    node(t data){
        value = data;
        next = nullptr;
    }
};

int main(){
    
    node<int> *node1 = new node<int>(3);
    cout<<node1->value<<endl;

    node <char> *node2 = new node<char>('a');
    cout<<node2->value<<endl;

    return 0;
}