#include <iostream>
using namespace std;

void swap(int *a, int *b){
    // try to swap x and y;
    int temp = *a;
    *a = *b;
    *b = temp;
    return ;
}
int main(){
    int a;
    cout<<"Enter the 1st integer: ";
    cin>>a;

    int b;
    cout<<"Enter the 2nd integer: ";
    cin>>b;
    
    // 1st way
    swap(&a,&b);

    // 2nd way;
    int *ptr1 = &a;
    int *ptr2 = &b;

    swap(ptr1,ptr2);
    
    cout<<"The value of 1st integer is: "<<a<<endl;
    cout<<"The value of 2nd integer is: "<<b;

    return 0;
}