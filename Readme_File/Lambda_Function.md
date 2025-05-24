# Lambda Function in C++

## Overview

A lambda function in C++ is a small anonymous function that can be defined inline within a larger expression. It is a shorthand way to create small, one-time use functions.

## Syntax

The syntax for a lambda function in C++ is as follows:

```cpp
auto lambda = [capture](parameters){ // -> return-type
    function-body
}
```

- `Capture` : Specifies how the lambda function captures variables from the surrounding scope.
- `Parameters` : The input parameters of the lambda function.
- `Return-type` : The return type of the lambda function. If omitted, the return type is deduced by the compiler.
- `Function-body` : The code that is executed when the lambda function is called.

## Capture Options

In C++, lambda functions can capture variables from their enclosing scope. The capture clause (inside the square brackets `[]`) specifies which variables are captured and how:

- `[=]` : Capture all automatic variables used in the lambda by value.
- `[&]` : Capture all automatic variables used in the lambda by reference.
- `[x]` : Capture variable `x` by value.
- `[&x]` : Capture variable `x` by reference.
- `[=, &y]` : Capture all variables by value, but capture `y` by reference.
- `[&, x]` : Capture all variables by reference, but capture `x` by value.
- `[this]` : Capture the `this` pointer by value (used in member functions).
- `[=, this]` : Capture all variables by value and the `this` pointer.

Capturing by value means the lambda gets its own copy of the variable, while capturing by reference means the lambda can modify the original variable.

## Example Use Cases

**Example 1 :**

### 1. Simple Lambda Function

```cpp
int main(){
    auto add = [](int x, int y) { return x + y; };
    cout << add(5, 3)<<endl;  // Outputs: 8
    return 0;
}
```

### 2. Capturing Variable

```cpp
int main(){
    int x = 5;
    auto add = [x](int y) { return x + y; };
    cout << add(3) << endl;  // Outputs: 8
    return 0;
}
```

### 3. Capturing Variables by Reference

```cpp
int main(){
    int x = 5;
    auto add = [&x](int y) { x += y; return x; };
    cout << add(3) << endl;  // Outputs: 8
    cout << x << endl;       // Outputs: 8
    return 0;
}
```

## Using Lambda Functions with STL Algorithms

C++ STL provides several algorithms that work seamlessly with lambda functions. Some commonly used ones are:

- `std::any_of`: Returns `true` if any element in a range satisfies a condition.
- `std::all_of`: Returns `true` if all elements in a range satisfy a condition.
- `std::none_of`: Returns `true` if no elements in a range satisfy a condition.
- `std::find_if`: Returns an iterator to the first element that satisfies a condition.

### Example: Using `any_of`, `all_of`, `none_of`, and `find_if`

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    // Check if any element is even
    bool anyEven = any_of(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
    cout << "Any even? " << anyEven << endl; // Outputs: 1 (true)

    // Check if all elements are positive
    bool allPositive = all_of(v.begin(), v.end(), [](int x) { return x > 0; });
    cout << "All positive? " << allPositive << endl; // Outputs: 1 (true)

    // Check if none of the elements are negative
    bool noneNegative = none_of(v.begin(), v.end(), [](int x) { return x < 0; });
    cout << "None negative? " << noneNegative << endl; // Outputs: 1 (true)

    // Find the first element greater than 3
    auto it = find_if(v.begin(), v.end(), [](int x) { return x > 3; });
    if (it != v.end())
        cout << "First element > 3: " << *it << endl; // Outputs: 4

    return 0;
}
```

These algorithms are powerful when combined with lambda functions, making code concise and expressive.

## Advantages

- Lambda functions are concise and can be defined inline, making the code more readable.
- Lambda functions can capture variables from the surrounding scope, making it easier to use them as event handlers or as arguments to algorithms.
- Lambda functions can be used as function objects, making it easier to use them with the Standard Template Library (STL).

## Disadvantages

- Lambda functions can be less efficient than regular functions because they involve dynamic memory allocation and deallocation.
- Lambda functions can be difficult to read and understand if they are too complex.
- Lambda functions can make the code harder to debug if they are not properly tested.
- Lambda functions can lead to code duplication if they are not properly refactored.

## Contributing

Contributions are welcome! If you have any suggestions or improvements, please submit a pull request.

## License

This code is licensed under the MIT License. See LICENSE.txt for details.
