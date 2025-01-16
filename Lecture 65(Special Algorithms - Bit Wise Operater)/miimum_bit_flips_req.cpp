#include <iostream>
using namespace std;

int main(){

    int x = 23;
    int y = 32;

    cout<<"Minimum Bits Required Flips are: "<<__builtin_popcount(x^y);

    return 0;
}