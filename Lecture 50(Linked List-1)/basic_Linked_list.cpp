#include <iostream>
using namespace std;

class node{

    public:
    int value;
    node* next;

    // constructor
    node(int data){
        
        // this -> value = data;
        // this -> next = NULL;

        value = data;
        next = NULL;
    }
};
int main(){

    node* n = new node(1);
    cout<<n->value<<" "<<n->next<<endl;

    return 0;
}