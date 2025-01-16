#include <iostream>
using namespace std;
double area(int r){
    double area = 3.14*(r*r);
    return area;
}

double circumference(int r){
    double circumference = 2*3.14*r;
    return circumference;
}

int main(){
    
    int r;
    cout<<"Enter the value of radius:";
    cin>>r;

    cout<<"Area of this circle: ";
    cout<<area(r);

    cout<<endl;

    cout<<"Circumference of this circle: ";
    cout<<circumference(r);

    return 0;
}