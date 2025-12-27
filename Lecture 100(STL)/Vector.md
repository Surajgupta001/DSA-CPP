# C++ STL Vector Operations - Complete Reference

A comprehensive guide to all C++ STL algorithms and operations that work with `vector`.

## 📚 Table of Contents

- [C++ STL Vector Operations - Complete Reference](#c-stl-vector-operations---complete-reference)
  - [📚 Table of Contents](#-table-of-contents)
  - [🚀 Quick Start](#-quick-start)
  - [1. Creation \& Initialization](#1-creation--initialization)
  - [2. Sorting Operations](#2-sorting-operations)
    - [Basic Sorting](#basic-sorting)
    - [Specialized Sorting](#specialized-sorting)
  - [3. Searching Operations](#3-searching-operations)
    - [Binary Search (Requires sorted vector)](#binary-search-requires-sorted-vector)
  - [4. Heap Operations](#4-heap-operations)
  - [5. Permutation Operations](#5-permutation-operations)
  - [6. Partitioning Operations](#6-partitioning-operations)
  - [7. Modifying Operations](#7-modifying-operations)
    - [Remove Operations](#remove-operations)
  - [8. Numeric Operations](#8-numeric-operations)
  - [9. Query Operations](#9-query-operations)
    - [Count Operations](#count-operations)
    - [Find Operations](#find-operations)
  - [10. Set Operations (Requires sorted vectors)](#10-set-operations-requires-sorted-vectors)
  - [11. Comparison Operations](#11-comparison-operations)
  - [12. Generation Operations](#12-generation-operations)
  - [13. Memory Operations](#13-memory-operations)
  - [14. Random Operations](#14-random-operations)
  - [15. Utility Operations](#15-utility-operations)
  - [16. Bulk Operations (C++17)](#16-bulk-operations-c17)
  - [17. Iterators \& Ranges (C++20)](#17-iterators--ranges-c20)
  - [📋 Complete Examples](#-complete-examples)
    - [Example 1: Common Operations](#example-1-common-operations)
    - [Example 2: Complex Data Processing](#example-2-complex-data-processing)
  - [🎯 Best Practices](#-best-practices)
  - [📦 Required Headers](#-required-headers)
  - [🔗 Useful Links](#-useful-links)
  - [📝 License](#-license)

## 🚀 Quick Start

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    // Create and initialize
    vector<int> v = {5, 3, 8, 1, 9, 2, 7, 4, 6};
    
    // Sort the vector
    sort(v.begin(), v.end());
    
    // Binary search
    if (binary_search(v.begin(), v.end(), 5)) {
        cout << "Found 5!" << endl;
    }
    
    // Calculate sum
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "Sum: " << sum << endl;
    
    // Display results
    for (int num : v) {
        cout << num << " ";
    }
    
    return 0;
}
```

## 1. Creation & Initialization

```cpp
vector<int> v1;                    // Empty vector
vector<int> v2(5, 10);             // 5 elements, each = 10
vector<int> v3 = {1, 2, 3, 4, 5};  // Initializer list (C++11)
vector<int> v4(v3.begin(), v3.end()); // From another container
vector<int> v5(v3);                 // Copy constructor
vector<int> v6(move(v5));      // Move constructor (C++11)
```

## 2. Sorting Operations

### Basic Sorting

```cpp
vector<int> v = {5, 3, 8, 1, 9};

// Sort entire vector (ascending)
sort(v.begin(), v.end());

// Sort in descending order
sort(v.begin(), v.end(), greater<int>());

// Sort with custom comparator
sort(v.begin(), v.end(), [](int a, int b) {
    return a > b;  // Custom descending
});
```

### Specialized Sorting

```cpp
// Stable sort (preserves order of equal elements)
stable_sort(v.begin(), v.end());

// Partial sort - first 3 smallest elements
partial_sort(v.begin(), v.begin() + 3, v.end());

// Check if sorted
bool is_sorted = is_sorted(v.begin(), v.end());
```

## 3. Searching Operations

### Binary Search (Requires sorted vector)

```cpp
sort(v.begin(), v.end());

// Binary search - returns bool
bool found = binary_search(v.begin(), v.end(), 5);

// Lower bound - first element ≥ value
auto lb = lower_bound(v.begin(), v.end(), 5);

// Upper bound - first element > value
auto ub = upper_bound(v.begin(), v.end(), 5);
```

## 4. Heap Operations

```cpp
vector<int> v = {3, 1, 4, 1, 5, 9};

// Make heap
make_heap(v.begin(), v.end());

// Push element
v.push_back(6);
push_heap(v.begin(), v.end());

// Pop maximum element
pop_heap(v.begin(), v.end());
v.pop_back();
```

## 5. Permutation Operations

```cpp
vector<int> v = {1, 2, 3};

// Generate all permutations
do {
    // Process permutation
} while(next_permutation(v.begin(), v.end()));
```

## 6. Partitioning Operations

```cpp
vector<int> v = {1, 9, 2, 8, 3, 7, 4, 6, 5};

// Partition based on condition
auto it = partition(v.begin(), v.end(), [](int x) {
    return x % 2 == 0;  // Even numbers first
});

// Check if partitioned
bool is_partitioned = is_partitioned(v.begin(), v.end(), 
    [](int x) { return x < 5; });
```

## 7. Modifying Operations

### Remove Operations

```cpp
vector<int> v = {1, 2, 3, 4, 5, 3, 6};

// Remove all 3's
auto new_end = remove(v.begin(), v.end(), 3);
v.erase(new_end, v.end());  // Actually resize

// Remove with condition
new_end = remove_if(v.begin(), v.end(), [](int x) {
    return x % 2 == 0;  // Remove even numbers
});
v.erase(new_end, v.end());
```

## 8. Numeric Operations

```cpp
#include <numeric>

vector<int> v = {1, 2, 3, 4, 5};

// Sum of elements
int sum = accumulate(v.begin(), v.end(), 0);

// Product of elements
int product = accumulate(v.begin(), v.end(), 1, 
    multiplies<int>());

// Partial sums
vector<int> partial(v.size());
partial_sum(v.begin(), v.end(), partial.begin());
```

## 9. Query Operations

### Count Operations

```cpp
vector<int> v = {1, 2, 2, 3, 3, 3, 4};

// Count occurrences of value
int count_3 = count(v.begin(), v.end(), 3);

// Count elements satisfying condition
int count_even = count_if(v.begin(), v.end(), [](int x) {
    return x % 2 == 0;
});
```

### Find Operations

```cpp
// Find value
auto it = find(v.begin(), v.end(), 3);

// Find with condition
it = find_if(v.begin(), v.end(), [](int x) {
    return x > 4;
});

// Find first of multiple values
vector<int> targets = {3, 5, 7};
it = find_first_of(v.begin(), v.end(), 
    targets.begin(), targets.end());
```

## 10. Set Operations (Requires sorted vectors)

```cpp
vector<int> v1 = {1, 3, 5, 7};
vector<int> v2 = {2, 3, 5, 8};
vector<int> result;

// Set union (elements in either)
set_union(v1.begin(), v1.end(), v2.begin(), v2.end(),
    back_inserter(result));

// Set intersection (elements in both)
set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(),
    back_inserter(result));

// Set difference (elements in v1 but not v2)
set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(),
    back_inserter(result));
```

## 11. Comparison Operations

```cpp
vector<int> v1 = {1, 2, 3};
vector<int> v2 = {1, 2, 3};
vector<int> v3 = {1, 2, 4};

// Equality
bool equal = equal(v1.begin(), v1.end(), v2.begin());

// Lexicographical comparison
bool lex_less = lexicographical_compare(v1.begin(), v1.end(),
    v3.begin(), v3.end());
```

## 12. Generation Operations

```cpp
vector<int> v(10);

// Fill with value
fill(v.begin(), v.end(), 42);

// Fill sequence with incrementing values
iota(v.begin(), v.end(), 1);  // 1, 2, 3, ...

// Generate values
int counter = 0;
generate(v.begin(), v.end(), [&counter]() {
    return counter++ * 2;
});
```

## 13. Memory Operations

```cpp
vector<int> v = {1, 2, 3, 4, 5};
vector<int> copy_vec(v.size());

// Copy elements
copy(v.begin(), v.end(), copy_vec.begin());

// Copy with condition
copy_if(v.begin(), v.end(), back_inserter(copy_vec),
    [](int x) { return x % 2 == 0; });

// Move elements (C++11)
vector<string> str_vec = {"hello", "world"};
vector<string> moved_vec(2);
move(str_vec.begin(), str_vec.end(), moved_vec.begin());
```

## 14. Random Operations

```cpp
#include <random>

vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

// Shuffle with random engine (C++11)
random_device rd;
mt19937 g(rd());
shuffle(v.begin(), v.end(), g);

// Sample elements (C++17)
vector<int> sample(3);
sample(v.begin(), v.end(), sample.begin(), 3, g);
```

## 15. Utility Operations

```cpp
vector<int> v = {1, 2, 3, 4, 5};

// Reverse elements
reverse(v.begin(), v.end());

// Rotate elements
rotate(v.begin(), v.begin() + 2, v.end());  // Left rotate by 2

// Swap ranges
vector<int> v1 = {1, 2, 3};
vector<int> v2 = {4, 5, 6};
swap_ranges(v1.begin(), v1.end(), v2.begin());
```

## 16. Bulk Operations (C++17)

```cpp
vector<int> v(1000000);

// Execute in parallel
sort(execution::par, v.begin(), v.end());

// Parallel unsequenced
sort(execution::par_unseq, v.begin(), v.end());
```

## 17. Iterators & Ranges (C++20)

```cpp
#include <ranges>

vector<int> v = {1, 2, 3, 4, 5, 6};

// Range-based sort
ranges::sort(v);

// Filter view
auto even_view = v | views::filter([](int x) { return x % 2 == 0; });

// Transform view
auto squared_view = v | views::transform([](int x) { return x * x; });

// Range algorithms
bool all_even = ranges::all_of(v, [](int x) { return x % 2 == 0; });
```

## 📋 Complete Examples

### Example 1: Common Operations

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    vector<int> numbers = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    
    // Sort
    sort(numbers.begin(), numbers.end());
    
    // Remove duplicates
    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
    
    // Transform
    transform(numbers.begin(), numbers.end(), numbers.begin(),
                   [](int x) { return x * 2; });
    
    // Filter (using remove_if)
    numbers.erase(
        remove_if(numbers.begin(), numbers.end(),
                      [](int x) { return x < 10; }),
        numbers.end()
    );
    
    // Calculate statistics
    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    auto [min_it, max_it] = minmax_element(numbers.begin(), numbers.end());
    
    cout << "Sum: " << sum << "\n";
    cout << "Min: " << *min_it << ", Max: " << *max_it << "\n";
    
    return 0;
}
```

### Example 2: Complex Data Processing

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Person {
    string name;
    int age;
    double salary;
};

int main() {
    vector<Person> people = {
        {"Alice", 30, 50000},
        {"Bob", 25, 45000},
        {"Charlie", 35, 60000},
        {"David", 28, 52000}
    };
    
    // Sort by age
    sort(people.begin(), people.end(),
              [](const Person& a, const Person& b) {
                  return a.age < b.age;
              });
    
    // Find person with salary > 55000
    auto it = find_if(people.begin(), people.end(),
                          [](const Person& p) {
                              return p.salary > 55000;
                          });
    
    if (it != people.end()) {
        cout << "Found: " << it->name << "\n";
    }
    
    // Count people under 30
    int young_count = count_if(people.begin(), people.end(),
                                   [](const Person& p) {
                                       return p.age < 30;
                                   });
    
    cout << "Young people: " << young_count << "\n";
    
    return 0;
}
```

## 🎯 Best Practices

1. **Always check iterator validity** before dereferencing
2. **Sort vectors** before using binary search, set operations, or unique
3. **Use `reserve()`** when you know the approximate size to avoid reallocations
4. **Prefer algorithms over manual loops** for readability and performance
5. **Use C++17 parallel algorithms** for large datasets
6. **Consider range-based operations in C++20** for cleaner code
7. **Be careful with iterator invalidation** when modifying vectors
8. **Use `emplace_back()`** instead of `push_back()` for complex types
9. **Prefer `find_if()`** over manual loops for searching
10. **Use `auto` with iterators** to avoid verbose type declarations

## 📦 Required Headers

```cpp
#include <vector>      // Vector container
#include <algorithm>   // Most algorithms (sort, find, etc.)
#include <numeric>     // Numeric operations (accumulate, iota)
#include <functional>  // Function objects (greater, less)
#include <iterator>    // Iterator utilities
#include <execution>   // Parallel execution (C++17)
#include <ranges>      // Ranges library (C++20)
```

## 🔗 Useful Links

- [C++ Reference - Algorithms](https://en.cppreference.com/w/cpp/algorithm)
- [C++ Reference - Vector](https://en.cppreference.com/w/cpp/container/vector)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
- [STL Algorithms Quick Reference](https://hackingcpp.com/cpp/cheat_sheets.html)

## 📝 License

This reference is provided for educational purposes. Feel free to use and modify as needed.

---

**Happy Coding!** 🚀
