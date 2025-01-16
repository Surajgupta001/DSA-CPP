#include <iostream>
using namespace std;

class parent{
public:
    parent(){
        cout<<"Parent class"<<endl;
    }
};

class child1:public parent{
public:
    child1(){
        cout<<"child1 class"<<endl;
    }
};

class child2:public parent{
public:
    child2(){
        cout<<"child2 class"<<endl;
    }
};

class Grandchild1:public child1, public child2{
public:
    Grandchild1(){
        cout<<"Grandchild class"<<endl;
    }
};
int main(){
    
    Grandchild1 gc;

    return 0;
}