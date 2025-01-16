#include <iostream>
using namespace std;

class parent{
public:
    int x;

protected:
    int y;

private:
    int z;
};

class child1: public parent{
    // x will remain public
    // y will remain protected
    // z will not be accessible
};

class child2: private parent{
    // x will remain private
    // y will remain private
    // z will not be inaccessible
};

class child3: protected parent{
    // x will be protected
    // y will be protected
    // z will be inaccessible
};

int main(){

    parent p;
    p.x;

    return 0;
}