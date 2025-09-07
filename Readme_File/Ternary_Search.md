# Ternary Search

Ternary Search is a divide-and-conquer algorithm used to find the maximum or minimum of a unimodal function or to search for an element in a sorted array. It is similar to Binary Search but divides the search space into three parts instead of two.

## When to Use Ternary Search

1. **Unimodal Functions**: When the function is unimodal (increasing and then decreasing or vice versa), Ternary Search is used to find the maximum or minimum value.

2. **Sorted Arrays**: It can also be used to search for an element in a sorted array, though Binary Search is generally preferred due to its simplicity.

## Algorithm

1. Divide the search space into three parts by calculating two midpoints:
   - `mid1 = left + (right - left) / 3`
   - `mid2 = right - (right - left) / 3`

2. Compare the values at `mid1` and `mid2`:
   - If searching for a maximum:
     - If `f(mid1) < f(mid2)`, the maximum lies in the range `[mid1, right]`.
     - Otherwise, it lies in `[left, mid2]`.
   - If searching for a minimum:
     - If `f(mid1) > f(mid2)`, the minimum lies in the range `[mid1, right]`.
     - Otherwise, it lies in `[left, mid2]`.

3. Repeat the process until the search space is reduced to a single point.

## Pseudocode

```cpp
function ternarySearch(left, right, isMaximizing):
    while (right - left) > epsilon:
        mid1 = left + (right - left) / 3
        mid2 = right - (right - left) / 3

        if isMaximizing:
            if f(mid1) < f(mid2):
                left = mid1
            else:
                right = mid2
        else:
            if f(mid1) > f(mid2):
                left = mid1
            else:
                right = mid2

    return (left + right) / 2
```

## Code Example (C++)

### Finding the Maximum of a Unimodal Function

```cpp
#include <iostream>
#include <cmath>
using namespace std;

// Example unimodal function
double f(double x) {
    return -1 * (x - 2) * (x - 2) + 4; // Parabola with maximum at x = 2
}

double ternarySearch(double left, double right, double epsilon) {
    while (right - left > epsilon) {
        double mid1 = left + (right - left) / 3;
        double mid2 = right - (right - left) / 3;

        if (f(mid1) < f(mid2)) {
            left = mid1;
        } else {
            right = mid2;
        }
    }
    return (left + right) / 2;
}

int main() {
    double left = 0, right = 4, epsilon = 1e-6;
    double maxPoint = ternarySearch(left, right, epsilon);
    cout << "Maximum point is at x = " << maxPoint << endl;
    cout << "Maximum value is f(x) = " << f(maxPoint) << endl;
    return 0;
}
```

### Searching in a Sorted Array

```cpp
#include <iostream>
#include <vector>
using namespace std;

int ternarySearch(vector<int>& arr, int left, int right, int target) {
    while (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == target) return mid1;
        if (arr[mid2] == target) return mid2;

        if (target < arr[mid1]) {
            right = mid1 - 1;
        } else if (target > arr[mid2]) {
            left = mid2 + 1;
        } else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    return -1; // Element not found
}

int main() {
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14};
    int target = 10;
    int index = ternarySearch(arr, 0, arr.size() - 1, target);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}
```

### Example: Searching for a Target in a Sorted Array

Suppose we have a sorted array `{2, 4, 6, 8, 10, 12, 14}` and we want to find the position of the element `10` using Ternary Search.

#### Step-by-Step Illustration

1. **Initial Range**:
   - `left = 0`, `right = 6`
   - Array: `{2, 4, 6, 8, 10, 12, 14}`

2. **Calculate Midpoints**:
   - `mid1 = left + (right - left) / 3 = 0 + (6 - 0) / 3 = 2`
   - `mid2 = right - (right - left) / 3 = 6 - (6 - 0) / 3 = 4`

3. **Compare Target with Midpoints**:
   - `arr[mid1] = 6`, `arr[mid2] = 10`
   - Since `arr[mid2] == target`, the target is found at index `4`.

#### Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

int ternarySearch(vector<int>& arr, int left, int right, int target) {
    while (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == target) return mid1;
        if (arr[mid2] == target) return mid2;

        if (target < arr[mid1]) {
            right = mid1 - 1;
        } else if (target > arr[mid2]) {
            left = mid2 + 1;
        } else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    return -1; // Element not found
}

int main() {
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14};
    int target = 10;
    int index = ternarySearch(arr, 0, arr.size() - 1, target);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}
```

## Complexity

1. **Time Complexity**: `O(log3(n))` (slightly better than Binary Search's `O(log2(n))`).

2. **Space Complexity**: `O(1)` (iterative version).

---

## Advantages

- Faster than Binary Search in some cases due to smaller search space per iteration.

- Useful for optimization problems involving unimodal functions.

## Disadvantages

- More complex to implement than Binary Search.

- Binary Search is generally preferred for searching in sorted arrays due to its simplicity.
