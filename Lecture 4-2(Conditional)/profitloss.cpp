// WAP to take input from user for cost price (cp) and selling price (sp) and calculate profit and loss.
#include <iostream>
using namespace std;
int main(){
    int cp,sp;
    cout<<"Enter the cost price: ";
    cin>>cp;
    cout<<"Enter the selling price: ";
    cin>>sp;
    if(sp>cp){
        int profit = sp-cp;
        cout<<"Your profit is: "<<profit<<endl;
    }
    else if(cp>sp){
        int loss = cp-sp;
        cout<<"Your loss is: "<<loss<<endl;
    }
    else{
        cout<<"No profit or loss "<<endl;
    }
    return 0;
}