#include <iostream>
using namespace std;
int main(){

    int n;
    cout<<"Enter the 1st integer: ";
    cin>>n;

    int m;
    cout<<"Enter the 2nd integer: ";
    cin>>m;

    int *ptr_x = &n;
    int *ptr_y = &m;

    int result;
    int *ptr_result = &result;

    *ptr_result = *ptr_x + *ptr_y;

    cout<<"Sum of these 2 integer is: "<<*ptr_result;

    return 0;
}