#include <iostream>
using namespace std;

class sum{
public:
    void add(int x, int y){ // function define
        int sum = x + y;
        cout<<sum<<endl;
    }

    void add(int x, int y, int z){ // function define
        int sum = x + y + z;
        cout<<sum<<endl;
    }

    void add(float x, float y){ // function define
        float sum = x + y;
        cout<<sum<<endl;
    }
};
int main(){

    sum s;
    // function calling
    s.add(2, 3);
    s.add(2, 3, 4);
    s.add(float(2.1), float(2.2));

    return 0;
}
