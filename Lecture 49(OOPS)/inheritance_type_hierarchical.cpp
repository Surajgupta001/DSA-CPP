#include <iostream>
using namespace std;

class parent1{
public:

    parent1(){
        cout<<"Parent1 class"<<endl;
    }
};

class parent2{
public:
    parent2(){
        cout<<"parent2 class"<<endl;
    }
};

class child1: public parent1{
public:
    child1(){
        cout<<"child1 class"<<endl;
    }
};

class child2: public parent2{
public:
    child2(){
        cout<<"child2 class"<<endl;
    }
};

class Grandchild: public parent1, public parent2{
public:
    Grandchild(){
        cout<<"Grandchild class"<<endl;
    }
};

int main(){
    
    Grandchild gc;

    return 0;
}