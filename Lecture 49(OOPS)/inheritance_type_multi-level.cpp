#include <iostream>
using namespace std;

class parent{
public:

    parent(){
        cout<<"Parent class"<<endl;
    }
};

class child: public parent{
public:
    child(){
        cout<<"Child Class"<<endl;
    }
};

class Grandchild: public child{
public:
    Grandchild(){
        cout<<"Grandchild class"<<endl;
    }
};

int main(){
    
    Grandchild gc;

    return 0;
}