#include <iostream>
using namespace std;

class Fruit{
public:
    string name;
    string color;
};
int main(){

    Fruit apple; // object
    
    apple.name = "Apple";
    apple.color = "Red";

    cout<<apple.name<<"-"<<apple.color<<endl;

    Fruit *mango = new Fruit(); // pointer declaration
    mango -> name = "mango";
    mango -> color = "Yellow";

    cout<<mango->name<<"-"<<mango->color<<endl;

    return 0;
}