/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

* MinStack() initializes the stack object.
* void push(int val) pushes the element val onto the stack.
* void pop() removes the element on the top of the stack.
* int top() gets the top element of the stack.
* int getMin() retrieves the minimum element in the stack.

You must implement a solution with O(1) time complexity for each function.
*/ 
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> dataStack; // The main stack for storing data
    stack<int> minStack; // The auxiliary stack for tracking the minimums

public:
    MinStack() {}

    void push(int val) {
        dataStack.push(val);
        if (minStack.empty() || val <= minStack.top()) { // If the new value is less than or equal to the current minimum
            minStack.push(val);
        }
    }

    void pop() {
        if (dataStack.top() == minStack.top()) {
            minStack.pop(); // If the top of the data stack is the current minimum, pop it from the min stack
        }
        dataStack.pop();
    }

    int top() {
        return dataStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(2);
    minStack.push(0);
    minStack.push(3);
    minStack.push(1);
    minStack.push(-1);

    cout << "Minimum: " << minStack.getMin() << endl; // Output: Minimum: -1

    minStack.pop();

    cout << "Minimum: " << minStack.getMin() << endl; // Output: Minimum: 0

    return 0;
}