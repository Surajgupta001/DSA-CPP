# Lambda Function in C++

## Overview

A lambda function in C++ is a small anonymous function that can be defined inline within a larger expression. It is a shorthand way to create small, one-time use functions.

## Syntax

The syntax for a lambda function in C++ is as follows:

```cpp
[capture](parameters) -> return-type
{
    function-body
}
```

- Capture: Specifies how the lambda function captures variables from the surrounding scope.
- Parameters: The input parameters of the lambda function.
- Return-type: The return type of the lambda function. If omitted, the return type is deduced by the compiler.
- Function-body: The code that is executed when the lambda function is called.

## Capture Options

The capture option specifies how the lambda function captures variables from the surrounding scope. The following capture options are available:

- [=]: Capture all variables by value.
- [&]: Capture all variables by reference.
- [this]: Capture the this pointer by value.
- [=x, &y]: Capture x by value and y by reference.

## Example Use Cases

**Example 1 :**

### 1. Simple Lambda Function

```cpp
int main()
{
    auto add = [](int x, int y) { return x + y; };
    cout << add(5, 3)<<endl;  // Outputs: 8
    return 0;
}
```

### 2. Capturing Variable

```cpp
int main()
{
    int x = 5;
    auto add = [x](int y) { return x + y; };
    cout << add(3) << endl;  // Outputs: 8
    return 0;
}
```

### 3. Capturing Variables by Reference

```cpp
int main()
{
    int x = 5;
    auto add = [&x](int y) { x += y; return x; };
    cout << add(3) << endl;  // Outputs: 8
    cout << x << endl;       // Outputs: 8
    return 0;
}
```

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
