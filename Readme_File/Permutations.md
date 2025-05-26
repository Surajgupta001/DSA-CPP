# Permutation Algorithms in C++ Standard Library

C++ provides several algorithms for working with permutations in the `<algorithm>` and `<ranges>` libraries. This README explains the following algorithms with code examples and outputs:

- `std::next_permutation`
- `std::prev_permutation`
- `std::is_permutation`
- `std::ranges::next_permutation`
- `std::ranges::prev_permutation`
- `std::ranges::is_permutation`

---

## 1. `std::next_permutation`

**Header:** `<algorithm>`

**Description:**  
Transforms the given range into the next lexicographically greater permutation. Returns `true` if such a permutation exists, otherwise returns `false` (and rearranges the range to the smallest permutation).

**Code Example:**

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {1, 2, 3};
    do {
        for (int n : v) std::cout << n << ' ';
        std::cout << '\n';
    } while (std::next_permutation(v.begin(), v.end()));
    return 0;
}
```

**Output:**

```plantext
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 1 2 
3 2 1 
```

---

## 2. `std::prev_permutation`

**Header:** `<algorithm>`

**Description:**  
Transforms the given range into the previous lexicographically ordered permutation. Returns `true` if such a permutation exists, otherwise returns `false` (and rearranges the range to the largest permutation).

**Code Example:**

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {3, 2, 1};
    do {
        for (int n : v) std::cout << n << ' ';
        std::cout << '\n';
    } while (std::prev_permutation(v.begin(), v.end()));
    return 0;
}
```

**Output:**

```plantext
3 2 1 
3 1 2 
2 3 1 
2 1 3 
1 3 2 
1 2 3 
```

---

## 3. `std::is_permutation`

**Header:** `<algorithm>`

**Description:**  
Checks whether one range is a permutation of another.

**Code Example:**

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {3, 1, 2};
    std::vector<int> v3 = {1, 2, 2};

    std::cout << std::boolalpha;
    std::cout << "v1 and v2: " << std::is_permutation(v1.begin(), v1.end(), v2.begin()) << '\n';
    std::cout << "v1 and v3: " << std::is_permutation(v1.begin(), v1.end(), v3.begin()) << '\n';
    return 0;
}
```

**Output:**

```plantext
v1 and v2: true
v1 and v3: false
```

---

## 4. `std::ranges::next_permutation` (C++23 and later)

**Header:** `<algorithm>` (`<ranges>` from C++20, but permutation helpers are from C++23)

**Description:**  
Returns a struct with the next lexicographical permutation of a range and a bool indicating success.

**Code Example:**

```cpp

#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {1, 2, 3};
    do {
        for (int n : v) std::cout << n << ' ';
        std::cout << '\n';
    } while (std::ranges::next_permutation(v).found);
    return 0;
}
```

**Output:**  
(Same as `std::next_permutation`)

```plantext
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 1 2 
3 2 1 
```

---

## 5. `std::ranges::prev_permutation` (C++23 and later)

**Header:** `<algorithm>`

**Description:**  
Returns a struct with the previous lexicographical permutation and a bool indicating success.

**Code Example:**

```cpp

#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {3, 2, 1};
    do {
        for (int n : v) std::cout << n << ' ';
        std::cout << '\n';
    } while (std::ranges::prev_permutation(v).found);
    return 0;
}
```

**Output:**  
(Same as `std::prev_permutation`)

```plantext
3 2 1 
3 1 2 
2 3 1 
2 1 3 
1 3 2 
1 2 3 
```

---

## 6. `std::ranges::is_permutation` (C++20 and later)

**Header:** `<algorithm>`

**Description:**  
Checks whether one range is a permutation of another, using ranges.

**Code Example:**

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {3, 1, 2};
    std::vector<int> v3 = {1, 2, 2};

    std::cout << std::boolalpha;
    std::cout << "v1 and v2: " << std::ranges::is_permutation(v1, v2) << '\n';
    std::cout << "v1 and v3: " << std::ranges::is_permutation(v1, v3) << '\n';
    return 0;
}
```

**Output:**

```plantext
v1 and v2: true
v1 and v3: false
```

---

## Notes

- The `std::ranges::*` algorithms require C++20 or later; `ranges::next_permutation` and `ranges::prev_permutation` are added in C++23.
- For maximum portability, use the non-ranges versions if you need to target C++17 or earlier.
- All these algorithms operate in-place on the given containers.

---

## References

- [cppreference.com - std::next_permutation](https://en.cppreference.com/w/cpp/algorithm/next_permutation)
- [cppreference.com - std::prev_permutation](https://en.cppreference.com/w/cpp/algorithm/prev_permutation)
- [cppreference.com - std::is_permutation](https://en.cppreference.com/w/cpp/algorithm/is_permutation)
- [cppreference.com - std::ranges::next_permutation](https://en.cppreference.com/w/cpp/algorithm/ranges/next_permutation)
- [cppreference.com - std::ranges::prev_permutation](https://en.cppreference.com/w/cpp/algorithm/ranges/prev_permutation)
- [cppreference.com - std::ranges::is_permutation](https://en.cppreference.com/w/cpp/algorithm/ranges/is_permutation)
