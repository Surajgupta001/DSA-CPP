# 📌 Precomputation-Based Problems (LeetCode)

## Core Idea

Compute once → reuse many times  
Avoid repeated work → reduce time complexity

---

## 🔹 What is Precomputation?

Precomputation means calculating and storing values **before the main logic** so that future operations become fast (`O(1)` or `O(n)`).

### When to Use Precomputation

- Repeated calculations exist
- Range queries are involved
- Left / right dependency appears
- Frequency or count is required

---

## 🔥 1. Prefix Sum Pattern

### 💡 When to Use Prefix Sum

- Range sum queries
- Subarray sum problems
- Continuous array operations

### 🧠 Prefix Sum Formula

```cpp
prefix[i] = prefix[i - 1] + nums[i];
```

### 🧩 Prefix Sum Problems

- 303 – Range Sum Query – Immutable
- 304 – Range Sum Query 2D – Immutable
- 560 – Subarray Sum Equals K
- 525 – Contiguous Array
- 974 – Subarray Sums Divisible by K
- 238 – Product of Array Except Self
- 1480 – Running Sum of 1D Array

---

## 🔥 2. Prefix Max / Suffix Max

### 💡 When to Use Prefix Max / Suffix Max

- Water trapping
- Boundary-based problems
- Left & right dependency

### 🧠 Formula

```cpp
leftMax[i]  = max(leftMax[i - 1], arr[i]);
rightMax[i] = max(rightMax[i + 1], arr[i]);
```

### 🧩 Prefix/Suffix Max Problems

- 42 – Trapping Rain Water
- 84 – Largest Rectangle in Histogram
- 2012 – Sum of Beauty in the Array
- 238 – Product of Array Except Self

---

## 🔥 3. Frequency / Hash Precomputation

### 💡 When to Use Frequency / Hash Precomputation

- Counting occurrences
- Matching patterns
- Majority or duplicates

### 🧠 Frequency/Hash Formula

```cpp
unordered_map<int, int> freq;
```

### 🧩 Frequency/Hash Problems

- 1 – Two Sum
- 242 – Valid Anagram
- 383 – Ransom Note
- 169 – Majority Element
- 451 – Sort Characters By Frequency
- 791 – Custom Sort String

---

## 🔥 4. DP Precomputation

### 💡 When to Use DP Precomputation

- Overlapping subproblems
- Optimal decisions
- Fibonacci-like patterns

### 🧠 DP Formula

```cpp
dp[i] = dp[i - 1] + dp[i - 2];
```

### 🧩 DP Precomputation Problems

- 70 – Climbing Stairs
- 198 – House Robber
- 746 – Min Cost Climbing Stairs
- 1137 – N-th Tribonacci Number
- 509 – Fibonacci Number

---

## 🔥 5. Stack-Based Precomputation

### 💡 When to Use Stack-Based Precomputation

- Next / Previous greater or smaller
- Monotonic stack patterns

### 🧠 Precompute

```cpp
nextGreater[i]
previousSmaller[i]
```

### 🧩 Stack-Based Problems

- 496 – Next Greater Element I
- 503 – Next Greater Element II
- 739 – Daily Temperatures
- 84 – Largest Rectangle in Histogram

---

## 🔥 6. Number Theory / Sieve Precomputation

### 💡 When to Use Number Theory / Sieve Precomputation

- Prime numbers
- Factorization
- Large constraints

### 🧠 Sieve Formula

```text
Sieve of Eratosthenes
```

### 🧩 Number Theory/Sieve Problems

- 204 – Count Primes
- 2521 – Distinct Prime Factors
- 2601 – Prime Subtraction Operation

---

## 🔥 7. Prefix XOR

### 💡 When to Use Prefix XOR

- XOR range queries
- Bit manipulation problems

### 🧠 Prefix XOR Formula

```cpp
prefixXor[i] = prefixXor[i - 1] ^ arr[i];
```

### 🧩 Prefix XOR Problems

- 1310 – XOR Queries of a Subarray
- 1442 – Count Triplets With Equal XOR
- 1829 – Maximum XOR for Each Query

---

## 🔥 8. 2D Grid Precomputation

### 💡 When to Use 2D Grid Precomputation

- Matrix range queries
- Submatrix calculations

### 🧠 2D Grid Formula

```cpp
prefix[i][j] = grid[i][j]
            + prefix[i - 1][j]
            + prefix[i][j - 1]
            - prefix[i - 1][j - 1];
```

### 🧩 2D Grid Problems

- 304 – Range Sum Query 2D
- 1277 – Count Square Submatrices with All Ones
- 1292 – Max Side Length of Square ≤ Threshold

---

## 🧠 Interview Recognition Checklist

If you see:

- ❓ Repeated calculation
- ❓ Range queries
- ❓ Left / right dependency
- ❓ Counting subarrays

👉 **Think PRECOMPUTATION first**

## 🚀 Practice Order (Recommended)

1. 303 → 304
2. 560 → 525
3. 739 → 496
4. 84 → 42

## 📌 Final Tip

Brute Force + Observation → Precomputation → Optimization
