#include <iostream>
using namespace std;
#include <climits>

class stack{
    int capacity;
    int *arr;
    int top;

    // constructor
    public:
    stack(int c){
        this -> capacity = c;
        arr = new int[c];
        this -> top = -1;
    }

    void push(int data){
        // check if stack is full or not
        if(this -> top == this -> capacity-1){
            cout<<"Overflow"<<endl;
            return;
        }
        this -> top++;
        this -> arr[this->top] = data;
    }

    int pop(){
        if(this -> top == -1){
            cout<<"Underflow"<<endl;
            return INT_MIN;
        }
        this -> top--;
    }

    int getTop(){
        // if top not exist
        if(this -> top == -1){
            cout<<"Underflow"<<endl;
            return INT_MIN;
        }
        return this -> arr[this -> top];
    }

    bool isEmpty(){
        return this -> top == -1;
    }

    int size(){
        return this -> top + 1;
    }

    bool isFull(){
        return this -> top == this -> capacity - 1;
    }
};
int main(){

    stack st(5);

    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.getTop()<<endl;

    st.push(4);
    st.push(5);
    cout<<st.getTop()<<endl;

    st.push(8);

    st.pop();
    st.pop();
    cout<<st.getTop()<<endl;

    return 0;
}