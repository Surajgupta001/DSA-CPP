# C++ Stringstream Template

## What is `stringstream`?

- `std::stringstream` is a stream class in C++ that allows you to perform input and output operations on strings, similar to how you use streams with files or the console.

- `stringstream` (from `sstream`) lets you treat a string as a stream, just like `cin`/`cout`.

---

## Basic Template

```cpp
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string input = "123 45.67 hello";
    stringstream ss(input);

    int a;
    double b;
    string c;

    ss >> a >> b >> c;

    cout << a << " " << b << " " << c << endl;
    return 0;
}
```

---

## Common Use Cases

### 1. Convert String to Number

```cpp
string s = "42";
int x;
stringstream(s) >> x;
```

### 2. Convert Number to String

```cpp
int x = 42;
stringstream ss;
ss << x;
string s = ss.str();
```

### 3. Split String by Spaces

```cpp
string s = "a b c";
stringstream ss(s);
string word;
while (ss >> word) {
    // process word
}
```

### 4. Using getline with Delimiter

```cpp
string s = "a,b,c";
stringstream ss(s);
string token;
while (getline(ss, token, ',')) {
    // process token
}
```

---

## Tips

- Always check for conversion errors if input may be invalid.
- Use `clear()` and `str("")` to reuse a stringstream object.

---

## References

- [cplusplus.com - stringstream](http://www.cplusplus.com/reference/sstream/stringstream/)
- [cppreference.com - std::stringstream](https://en.cppreference.com/w/cpp/io/basic_stringstream)
