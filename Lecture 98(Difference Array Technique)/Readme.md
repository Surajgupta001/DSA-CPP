# Difference Array Technique

The **Difference Array Technique** is an efficient method for performing range updates on an array. It allows you to apply multiple updates to a range of elements in constant time and compute the final values of the array in linear time. This technique is particularly useful in scenarios where you need to perform many updates on a large array.

## Table of Contents

- [How It Works](#how-it-works)
- [Example](#example)
- [Complexity](#complexity)
- [Applications](#applications)
- [Implementation](#implementation)
- [Contributing](#contributing-1)
- [License](#license)

## How It Works

1. **Initialization**: Start with an array `A` of size `n`. Create a difference array `D` of size `n + 1`.

2. **Range Update**: To update a range of indices from `L` to `R` (inclusive) by a value `x`, perform the following operations on the difference array:
   - `D[L] += x`
   - `D[R + 1] -= x`

3. **Final Array Calculation**: After all updates are applied to the difference array, compute the final values of the original array `A` by taking the prefix sum of the difference array.

## Example

Let's say you have an array `A` of size 5, initialized to zeros:

### Step 2: Apply the Updates

1. For the first update (add 2 to [1, 3]):
   - `D[1] += 2` → `D = [0, 2, 0, 0, 0, 0]`
   - `D[4] -= 2` → `D = [0, 2, 0, 0, -2, 0]`

2. For the second update (add 3 to [2, 4]):
   - `D[2] += 3` → `D = [0, 2, 3, 0, -2, 0]`
   - `D[5] -= 3` → `D = [0, 2, 3, 0, -2, -3]`

### Step 3: Calculate the Final Array

Now, compute the prefix sum to get the final values of `A`:

So the final array `A` is:

## Complexity

- **Time Complexity**:
  - Each update operation takes O(1) time.
  - Calculating the final array takes O(n) time.
- **Space Complexity**: O(n) for the difference array.

## Applications

The Difference Array Technique is commonly used in:

- Range sum queries
- Range update problems in competitive programming.
- Problems involving cumulative frequency tables.
- Efficiently managing updates in data structures like segment trees or Fenwick trees.

## Implementation

Here is a simple implementation of the Difference Array Technique in c++ :

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> getModifiedArray(int length, vector<vector<int>>& updates){
    
    // Initialize the differnce array
    vector<int> diff(length, 0);

    // Step 1 : Apply update using the difference array
    for(auto &update : updates){
        int left = update[0];
        int right = update[1];
        int value = update[2];

        diff[left] += value; // Add increment at StartIndex
        if(right + 1 < length){
            diff[right + 1] -= value; // Subtract increment after endIndex
        }
    }
    // Step 2 : Compute the final array form the differnce array
    vector<int> ans(length, 0);
    int prefixSum = 0;
    for(int i = 0; i < length; i++){
        prefixSum += diff[i];
        ans[i] = prefixSum;
    }
    return ans;
}

int main(){
    int length = 5;
    
    vector<vector<int>> updates = {{1,3,2},{2,4,3},{0,2,-2}};
    vector<int> result = getModifiedArray(length, updates);
    
    cout<<"Applying all the updates in array is: ";
    
    for(auto &num : result) cout << num << " ";
    
    return 0;
}
```

## Conclusion

- The Difference Array Technique is a powerful tool for optimizing range update operations on arrays. By leveraging this technique, you can significantly reduce the time complexity of your algorithms, making them more efficient and scalable.

- Feel free to contribute or raise issues if you have any questions or suggestions!

This `README.md` provides a comprehensive overview of the Difference Array Technique, including its purpose, implementation, and examples. You can add more sections or modify existing ones based on your specific needs.
