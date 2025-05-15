# Matrix Exponentions

Matrix exponentiation is a technique used to compute the power of a matrix efficiently, especially for large exponents. The most common algorithm for matrix exponentiation is based on the `exponentiation by squaring method`, which reduces the time complexity significantly compared to naive methods.

## Key Points

- **Purpose**: Matrix exponentiation is commonly used in problems involving recurrence relations, such as Fibonacci sequence computation.
- **Efficiency**: Reduces the time complexity of matrix exponentiation to `O(log n)` using the squaring method.
- **Applications**:
  - Solving linear recurrence relations.
  - Dynamic programming optimizations.
  - Graph theory problems like finding paths of fixed lengths.

## Steps for Matrix Exponentiation

1. **Matrix Representation**: Define a matrix structure or class to represent matrices.
2. **Matrix Multiplication**: Implement a function to multiply two matrices.
3. **Exponentiation by Squaring**:
   - If the exponent is `0`, return the `identity matrix`.
   - If the exponent is `1`, return the `matrix itself`.
   - If the exponent is `even`, `recursively` compute the `half power` and `square it`.
   - If the exponent is `odd`, `recursively` compute the `half power`, `square it`, and `multiply` by the original matrix.

4. **Modular Arithmetic**: If required, perform all operations modulo a certain number to `prevent overflow` and keep numbers manageable.

### Pseudocode

```plaintext

FUNCTION matrixMultiplication(A, B):
    rowsA = number of rows in A
    colsA = number of columns in A
    colsB = number of columns in B
    Initialize result as a matrix of size rowsA x colsB with all elements 0

    FOR i FROM 0 TO rowsA - 1:
        FOR j FROM 0 TO colsB - 1:
            FOR k FROM 0 TO colsA - 1:
                result[i][j] = (result[i][j] + (A[i][k] * B[k][j]) % mod) % mod
            END FOR
        END FOR
    END FOR

    RETURN result
END FUNCTION

FUNCTION matrixExponentiation(base, exponent):
    IF exponent == 0:
        size = size of base
        Initialize identity matrix of size x size with all elements 0
        FOR i FROM 0 TO size - 1:
            identity[i][i] = 1
        END FOR
        RETURN identity
    END IF

    half = matrixExponentiation(base, exponent / 2)
    result = matrixMultiplication(half, half)

    IF exponent is odd:
        result = matrixMultiplication(result, base)
    END IF

    RETURN result
END FUNCTION
```

### Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

int mod = 1e9 + 7;

// Generalized function to multiply two matrices
vector<vector<long long>> matrixMultiplication(vector<vector<long long>>& A, vector<vector<long long>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();

    vector<vector<long long>> result(rowsA, vector<long long>(colsB, 0));

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] = (result[i][j] + ((long long)A[i][k] * B[k][j]) % mod) % mod;
            }
        }
    }
    return result;
}

// Function to raise matrix base to the power exponent (Just like Binary exponentiation)
vector<vector<long long>> matrixExponentiation(vector<vector<long long>>& base, long long exponent) {
    if (exponent == 0) {
        int size = base.size();
        vector<vector<long long>> identity(size, vector<long long>(size, 0));
        for (int i = 0; i < size; i++) {
            identity[i][i] = 1;
        }
        return identity;
    }

    vector<vector<long long>> half = matrixExponentiation(base, exponent / 2);
    vector<vector<long long>> result = matrixMultiplication(half, half);

    if (exponent % 2 == 1) {
        result = matrixMultiplication(result, base);
    }
    return result;
}

int main() {
    // Input: Size of the transformation matrix
    cout << "Enter the size of the transformation matrix: ";
    int size;
    cin >> size;

    // Input: Transformation matrix
    vector<vector<long long>> base(size, vector<long long>(size));
    cout << "Enter the transformation matrix (row by row):" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> base[i][j];
        }
    }

    // Input: Initial vector
    vector<long long> initial(size);
    cout << "Enter the initial vector:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> initial[i];
    }

    // Input: Term to compute
    cout << "Enter the value of n to compute the nth term: ";
    long long n;
    cin >> n;

    // Base case
    if (n < size) {
        cout << "The nth term is: " << initial[n] << endl;
        return 0;
    }

    // Compute (base^(n-size+1)) using matrix exponentiation
    vector<vector<long long>> resultMatrix = matrixExponentiation(base, n - size + 1);

    // Compute the nth term by multiplying the result matrix with the initial vector
    long long nthTerm = 0;
    for (int i = 0; i < size; i++) {
        nthTerm = (nthTerm + (resultMatrix[0][i] * initial[i]) % mod) % mod;
    }

    cout << "The nth term is: " << nthTerm << endl;

    return 0;
}

/*
------- INPUTS -----
Enter the size of the transformation matrix: 2
Enter the transformation matrix (row by row):
1 1
1 0
Enter the initial vector:
1 0
Enter the value of n to compute the nth term: 10
*/ 
```

### Explanation

- The code defines a function `matrixMultiplication` to multiply two matrices and a function `matrixExponentiation` to compute the power of a matrix using the exponentiation by squaring method.
- The `main` function takes the size of the transformation matrix, the transformation matrix itself, the initial vector, and the term to compute as input.

## Time and Space Complexity

- **Time Complexity**: `O(log n * m^3)` where `n` is the exponent and `m` is the size of the matrix.

- **Space Complexity**: `O(m^2)` for storing the matrices.

## Conclusion

Matrix exponentiation is a powerful technique that allows for efficient computation of matrix powers, making it a valuable tool in various algorithmic problems. Understanding and implementing this technique can lead to significant performance improvements in many applications.

## Github liscense

This code is licensed under the MIT License. Feel free to use, modify, and distribute it as per the terms of the license.
