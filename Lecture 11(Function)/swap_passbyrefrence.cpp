#include <iostream>
using namespace std;
void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}
int main(){
    int a = 5;
    int b = 6;
    
    int &x = a; // koi sa bhi address possible hai and variable;

    swap(a,b);
    cout<<a<<" "<<b<<endl;
    return 0;


}