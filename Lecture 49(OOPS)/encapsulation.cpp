#include <iostream>
using namespace std;

class ABC{
public:
    int x;
    void set(int n){
        x = n;
    }
    int get(){
        return x;
    }
};

int main(){
    
    ABC object1;
    object1.set(3);

    cout << object1.get() << endl;

    return 0;
}