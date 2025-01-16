#include <iostream>
using namespace std;

class complex{
public:
    int real_part;
    int imaginary_part;

    complex(int x, int y){
        real_part = x;
        imaginary_part = y;
    }

    // function overloading
    complex operator+ (complex &c){
        complex ans(0,0);
        ans.real_part = real_part + c.real_part;
        ans.imaginary_part = imaginary_part + c.imaginary_part;
        return ans;

    }
};
int main(){

    complex c1(1,2);
    complex c2(1,3);

    complex c3 = c1+c2;

    cout<<"Complex sum is: ";
    cout<<c3.real_part<<" i"<<c3.imaginary_part<<endl;
    
    return 0;
}