#include <iostream>
using namespace std;

class rectangle{
public:

    int length;
    int breath;

    rectangle(){ // default constructor --> no argument passed
    length = 0;
    breath = 0;
    }

    rectangle(int x, int y){ // parametrised constructor - argument passed
        length = x;
        breath = y;
    }

    rectangle(rectangle &r){ // copy constructor - initialize an object by another existing object
        length = r.length;
        breath = r.breath;
    }

    ~rectangle(){ // desctructor
        cout<<"Destructor is called"<<endl;
    }
};

int main(){

    rectangle *r1 = new rectangle();
    cout<<r1->length<<" "<<r1->breath<<endl;
    delete r1;

    rectangle r2(3,4);
    cout<<r2.length<<" "<<r2.breath<<endl;

    rectangle r3 = r2;
    cout<<r3.length<<" "<<r3.breath<<endl;

    return 0;
}