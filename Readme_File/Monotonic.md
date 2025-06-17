# What is a Monotonic Data Structure?

**A monotonic data structure** is a data structure that maintains its elements in a specific order, either non-decreasing or non-increasing. This means that as you traverse the structure, the elements will either always increase or always decrease, without any fluctuations in between.

**Monotonic data structures** are particularly useful in scenarios where you need to maintain a sorted order of elements while allowing for efficient insertions, deletions, and lookups. Examples of monotonic data structures include monotonic stacks, monotonic queues, and certain types of trees.

A **monotonic data structure** (usually a stack or a queue) maintains its elements in either **increasing** or **decreasing** order.

- **Monotonic Increasing**: Each element is greater than or equal to the previous one.
- **Monotonic Decreasing**: Each element is less than or equal to the previous one.

## Main Uses

Efficiently solve problems involving:

- Next/previous greater/smaller element
- Sliding window minimum/maximum
- Histogram largest rectangle
- Stock span problem

## Why Use Monotonic Data Structures?

- Reduce time complexity from O(N²) to O(N) for certain problems.
- Help in handling range queries, especially for contiguous subarrays/windows.

## Types of Monotonic Data Structures

### Monotonic Stack

A **monotonic stack** is a stack that maintains its elements in a specific order, either increasing or decreasing. It allows for efficient retrieval of the next greater or smaller element.

### Monotonic Queue

A **monotonic queue** is a queue that maintains its elements in a specific order, either increasing or decreasing. It allows for efficient retrieval of the maximum or minimum element in a sliding window.

## Stanadard Code Template

### 1. Monotonic Stack (Next Greater Element)

Problem: For each element in an array, find the next greater element to its right.

