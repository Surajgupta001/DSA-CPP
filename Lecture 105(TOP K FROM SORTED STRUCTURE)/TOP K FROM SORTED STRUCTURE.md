# TOP K FROM SORTED STRUCTURE — Complete Pattern Guide

---

## 1. What Is This Pattern?

**"Top K from Sorted Structure"** is a DSA pattern where you need to efficiently find the **K smallest (or largest)** elements from one or more sorted sources (arrays, linked lists, matrices, virtual pair-spaces, etc.).

The core idea:
> Instead of generating all candidates and sorting them, use a **Min-Heap (or Max-Heap)** to lazily extract only what you need — one element at a time — in sorted order.

**Key Insight:** When data is already sorted, you don't need to look at everything. You just need to smartly decide *what to look at next*, and a heap does that in O(log k) per step.

---

## 2. The Core Thinking Shift 💡

Before writing any code, ask yourself:

> **"Can I avoid generating all possibilities?"**

### ❌ Brute Force Mindset
```
Generate Everything
    → Sort Everything
        → Pick Top K
```
**Cost:** `O(N² log N)` — you paid for everything you didn't need.

### ✅ Pattern Mindset
```
Start from the best candidate
    → Expand only neighbours
        → Maintain Min/Max Heap
            → Extract K times
```
**Cost:** `O(K log N)` or `O(K log K)` — you paid only for what you asked for.

### Why This Works

Sorted structure gives you a **guarantee**: the next best candidate is always adjacent to the current best. You never need to look far. The heap simply tracks *which adjacency to explore next*, so you expand lazily — one step at a time — and stop the moment you have K answers.

```
Brute force thinks in grids:    Pattern thinks in frontiers:

  [×][×][×][×][×]                [✓][ ][ ][ ][ ]
  [×][×][×][×][×]                [✓][✓][ ][ ][ ]
  [×][×][×][×][×]   →            [✓][✓][✓][ ][ ]
  [×][×][×][×][×]                [ ][ ][ ][ ][ ]
  [×][×][×][×][×]                [ ][ ][ ][ ][ ]

  visits N² cells                visits only K cells
```

### Complexity Comparison

| Approach | Time | Space | Why |
|---|---|---|---|
| Brute force (generate + sort) | O(N² log N) | O(N²) | Generates all N² pairs |
| Pattern A (K sorted lists) | O(K log K) | O(K) | Heap never exceeds K entries |
| Pattern B (2 sorted arrays) | O(K log K) | O(K) | Only K rows seeded, K pops |
| Pattern D (sorted matrix) | O(K log N) | O(N) | N rows seeded, K pops |

---

## 3. When to Use This Pattern

Recognize this pattern when you see:

| Signal | Example |
|---|---|
| "Find K smallest/largest" | K pairs with smallest sums |
| Multiple sorted lists/arrays | Merge K sorted linked lists |
| Sorted matrix or grid | Kth smallest in a sorted matrix |
| Implicit sorted space (pairs, tuples) | K closest points, K nearest elements |
| Streaming / online selection | Find median from data stream |
| "Return top K" from sorted input | K most frequent elements |

**Keywords to look for:** *k smallest, k largest, k closest, k pairs, merge k sorted, kth element, top k, find k.*

---

## 4. Core Mechanics

### The Min-Heap Approach (for K Smallest)

```
1. Seed the heap with the "frontier" — the smallest possible candidates.
2. Pop the top (current minimum).
3. Push the next logical candidate(s) from the same source.
4. Repeat K times.
```

### The Max-Heap Approach (for K Largest)

```
1. Maintain a max-heap of size K.
2. For each new element, push it.
3. If heap size > K, pop the maximum.
4. What remains is the K smallest (or K largest, depending on direction).
```

### Heap Entry Design

The heap stores a **tuple** that encodes:
- The **priority value** (what to sort by — usually a sum, value, or distance)
- The **index/pointer** needed to generate the next candidate

```
Min-Heap entry: (priority, index_info)
Example:        (node->value, ListNode*)
Example:        (nums1[i] + nums2[j], (i, j))
Example:        (matrix[r][c], (r, c))
```

---

## 5. General Template (C++)

```cpp
#include <queue>
#include <vector>
using namespace std;

// Min-Heap: finds K smallest
// Tuple: (value/priority, index1, index2, ...)
priority_queue<
    tuple<int,int,int>,
    vector<tuple<int,int,int>>,
    greater<tuple<int,int,int>>
> minHeap;

// --- SEED the heap ---
// Push the first "frontier" elements (the smallest candidates)
// e.g., first element of each list, or (nums1[i] + nums2[0]) for all i < k

// --- EXTRACT K times ---
vector<ResultType> result;
while (k-- && !minHeap.empty()) {
    auto [val, i, j] = minHeap.top();
    minHeap.pop();

    result.push_back(/* use val, i, j */);

    // Push NEXT candidate from the same sorted source
    if (/* next index is valid */) {
        minHeap.push({ nextVal, nextI, nextJ });
    }
}
return result;
```

---

## 6. General Code Patterns (Reference Templates)

These are the **4 canonical code skeletons** for this pattern. Pick the one that matches your problem, fill in the blanks, and you're done.

---

### Pattern A — K Smallest from K Sorted Lists / Arrays

**Use when:** You have K independent sorted sequences (linked lists, arrays) and want to merge or pick the smallest K elements overall.

```cpp
// ─── HEAP ENTRY: (value, listIndex, elementIndex) ───
priority_queue<
    tuple<int, int, int>,
    vector<tuple<int, int, int>>,
    greater<tuple<int, int, int>>
> minHeap;

// ─── STEP 1: SEED — push first element of every list ───
for (int i = 0; i < k; i++) {
    if (!lists[i].empty()) {
        minHeap.push({ lists[i][0], i, 0 });
        //              ^value      ^listIdx ^elemIdx
    }
}

// ─── STEP 2: EXTRACT K times ───
vector<int> result;
while (!minHeap.empty() && result.size() < k) {
    auto [val, listIdx, elemIdx] = minHeap.top();
    minHeap.pop();

    result.push_back(val);  // ← collect answer

    // ─── STEP 3: push NEXT element from the same list ───
    int nextElem = elemIdx + 1;
    if (nextElem < lists[listIdx].size()) {
        minHeap.push({ lists[listIdx][nextElem], listIdx, nextElem });
    }
}
// result now holds K smallest elements in sorted order
```

---

### Pattern B — K Smallest Pairs from 2 Sorted Arrays (Grid Traversal)

**Use when:** Candidates are formed by combining elements from two sorted arrays `nums1[i] + nums2[j]`, and you want the K smallest combinations.

```cpp
// ─── HEAP ENTRY: (sum, i, j) ───
priority_queue<
    tuple<int, int, int>,
    vector<tuple<int, int, int>>,
    greater<tuple<int, int, int>>
> minHeap;

int m = nums1.size(), n = nums2.size();

// ─── STEP 1: SEED — fix j=0, push one entry per row ───
for (int i = 0; i < min(k, m); i++) {
    minHeap.push({ nums1[i] + nums2[0], i, 0 });
    //              ^sum                 ^i  ^j=0
}

// ─── STEP 2: EXTRACT K times ───
vector<pair<int,int>> result;
while (k-- && !minHeap.empty()) {
    auto [sum, i, j] = minHeap.top();
    minHeap.pop();

    result.push_back({ nums1[i], nums2[j] });  // ← collect answer

    // ─── STEP 3: push NEXT element in the same row (j → j+1) ───
    if (j + 1 < n) {
        minHeap.push({ nums1[i] + nums2[j + 1], i, j + 1 });
    }
}
// result now holds K pairs with smallest sums
```

---

### Pattern C — K Largest from a Single Unsorted Array (Fixed-Size Heap)

**Use when:** You have ONE unsorted array and want K largest (or K smallest) elements. No sorted structure to exploit — just prune with a fixed-size heap.

```cpp
// ─── For K LARGEST: use a MIN-HEAP of size K ───
// Logic: min-heap keeps the K largest seen so far.
//        If a new element beats the heap's minimum → it belongs in top K.

priority_queue<int, vector<int>, greater<int>> minHeap;  // min-heap

for (int num : nums) {
    minHeap.push(num);

    // ─── Keep heap size exactly K ───
    if (minHeap.size() > k) {
        minHeap.pop();  // evict smallest → keeps K largest
    }
}

// minHeap now contains exactly the K largest elements
// To get them in sorted order:
vector<int> result;
while (!minHeap.empty()) {
    result.push_back(minHeap.top());
    minHeap.pop();
}
// result is in ascending order; reverse for descending
```

> **Flip for K Smallest:** Use a MAX-HEAP of size K. Pop when size > K.

---

### Pattern D — Kth Smallest in a Sorted 2D Matrix

**Use when:** You have a matrix where rows AND columns are sorted, and want the Kth smallest element overall.

```cpp
// ─── HEAP ENTRY: (value, row, col) ───
priority_queue<
    tuple<int, int, int>,
    vector<tuple<int, int, int>>,
    greater<tuple<int, int, int>>
> minHeap;

int n = matrix.size();

// ─── STEP 1: SEED — push first element of every row ───
for (int r = 0; r < n; r++) {
    minHeap.push({ matrix[r][0], r, 0 });
    //              ^value        ^row ^col=0
}

// ─── STEP 2: Pop K-1 times, then Kth pop is the answer ───
int val = -1;
while (k--) {
    auto [v, r, c] = minHeap.top();
    minHeap.pop();
    val = v;

    // ─── STEP 3: push NEXT element in the same row ───
    if (c + 1 < n) {
        minHeap.push({ matrix[r][c + 1], r, c + 1 });
    }
}
return val;  // ← Kth smallest
```

---

### Pattern E — Two-Heap (Find Median from Data Stream)

**Use when:** You need to continuously track the median as elements arrive — a "running top K" problem split at the midpoint.

```cpp
priority_queue<int>                     maxHeap;  // left half  (max on top)
priority_queue<int, vector<int>, greater<int>> minHeap;  // right half (min on top)

void addNum(int num) {
    // ─── STEP 1: Push to correct half ───
    if (maxHeap.empty() || num <= maxHeap.top())
        maxHeap.push(num);
    else
        minHeap.push(num);

    // ─── STEP 2: BALANCE — sizes must differ by at most 1 ───
    if (maxHeap.size() > minHeap.size() + 1) {
        minHeap.push(maxHeap.top()); maxHeap.pop();
    } else if (minHeap.size() > maxHeap.size()) {
        maxHeap.push(minHeap.top()); minHeap.pop();
    }
}

double findMedian() {
    if (maxHeap.size() == minHeap.size())
        return (maxHeap.top() + minHeap.top()) / 2.0;  // even count
    return maxHeap.top();                               // odd count
}
```

---

### How to Pick the Right Pattern

```
You have K sorted lists/linked lists           → Pattern A
You combine elements from 2 sorted arrays      → Pattern B
You have 1 unsorted array, want top K          → Pattern C
You have a sorted matrix (rows + cols sorted)  → Pattern D
You need running median from a stream          → Pattern E
```

---

## 7. Solved Problems (Annotated)

---

### Problem 1 — Merge K Sorted Lists (LC #23)

**Problem:** Given K sorted linked lists, merge them into one sorted list.

**Strategy:**
- Seed heap with the head node of each list.
- Each pop gives the current minimum; push its `.next` to maintain the frontier.

```cpp
// Custom comparator for ListNode*
static bool cmp(ListNode* a, ListNode* b) {
    return a->value > b->value; // min-heap
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, decltype(&cmp)> minHeap(&cmp);

    // SEED: push all non-null heads
    for (ListNode* node : lists)
        if (node) minHeap.push(node);

    if (minHeap.empty()) return nullptr;

    ListNode* head = minHeap.top(); minHeap.pop();
    if (head->next) minHeap.push(head->next);
    ListNode* tail = head;

    while (!minHeap.empty()) {
        ListNode* cur = minHeap.top(); minHeap.pop();
        tail->next = cur;
        tail = cur;
        if (cur->next) minHeap.push(cur->next);
    }
    return head;
}
```

**Complexity:**
- Time: O(N log K) — N total nodes, heap of size K
- Space: O(K) — heap holds at most K nodes

---

### Problem 2 — K Pairs with Smallest Sums (LC #373)

**Problem:** Given two sorted arrays `nums1` and `nums2`, find K pairs `(u, v)` with the smallest `u + v`.

**Strategy:**
- Seed heap with `(nums1[i] + nums2[0], i, 0)` for all `i < min(k, m)`.
- On each pop of `(sum, i, j)`, push `(nums1[i] + nums2[j+1], i, j+1)`.
- This explores the sorted pair-space lazily row by row.

```cpp
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    // Min-heap: (sum, index_in_nums1, index_in_nums2)
    priority_queue<
        pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>,
        greater<>
    > minHeap;

    int m = nums1.size(), n = nums2.size();

    // SEED: pair each nums1[i] with nums2[0]
    for (int i = 0; i < min(k, m); i++)
        minHeap.push({ nums1[i] + nums2[0], {i, 0} });

    vector<vector<int>> result;
    while (k-- && !minHeap.empty()) {
        auto [sum, idx] = minHeap.top(); minHeap.pop();
        auto [i, j] = idx;

        result.push_back({ nums1[i], nums2[j] });

        // NEXT CANDIDATE: move j forward in nums2
        if (j + 1 < n)
            minHeap.push({ nums1[i] + nums2[j+1], {i, j+1} });
    }
    return result;
}
```

**Complexity:**
- Time: O(K log K) — at most K pops, heap stays ≤ K
- Space: O(K)

---

## 8. More Problems That Use This Pattern

| # | Problem | Heap Type | Seed Strategy | Next Candidate |
|---|---|---|---|---|
| LC 23 | Merge K Sorted Lists | Min (node value) | Head of each list | `node->next` |
| LC 373 | K Pairs with Smallest Sums | Min (sum) | `(nums1[i], nums2[0])` for all i | `(nums1[i], nums2[j+1])` |
| LC 378 | Kth Smallest in Sorted Matrix | Min (value) | First element of each row | Right neighbor in same row |
| LC 632 | Smallest Range Covering K Lists | Min + tracking max | First element of each list | Next in same list |
| LC 1439 | 1st Smallest Sum of K Sorted Arrays | Min (sum) | Combo of first elements | Extend one index |
| LC 719 | Find K-th Smallest Pair Distance | Binary Search + Sliding Window | — | — |
| LC 786 | K-th Smallest Prime Fraction | Min (fraction value) | `(arr[0]/arr[n-1], 0, n-1)` | Advance row index |
| LC 295 | Find Median from Data Stream | Min + Max heap | — | — |

---

## 9. Variations & Decision Guide

```
Problem Type                         → Approach
─────────────────────────────────────────────────────────────
K smallest from K sorted lists       → Min-heap, seed with all heads
K smallest pairs from 2 sorted arrs  → Min-heap, seed row 0 of grid
K largest from unsorted array        → Min-heap of size K (trim as you go)
Kth smallest in sorted matrix        → Min-heap + (row, col) index
Merge K sorted arrays                → Min-heap, same as linked lists
Find median (stream)                 → Two heaps: max-heap (left) + min-heap (right)
K closest points to origin           → Max-heap of size K on distance
```

---

## 10. Heap Seeding Strategies

The most critical design decision is **what to put in the heap initially**.

### Strategy A — One entry per source
Use when you have K independent sorted sequences.
```
Seed: first element of each of the K lists/arrays
Next: the next element in the same list
Used in: Merge K Sorted Lists, Smallest Range
```

### Strategy B — One entry per row of an implicit grid
Use when candidates come from a 2D sorted space (i × j).
```
Seed: (nums1[i] + nums2[0], i, 0)  for i in 0..min(k, m)
Next: (nums1[i] + nums2[j+1], i, j+1)
Used in: K Pairs with Smallest Sums, K-th Smallest Prime Fraction
```

### Strategy C — Sliding window on size
Use when you want to maintain exactly K elements.
```
Push everything; if heap.size() > K → pop
Used in: K Largest Elements, K Closest Points
```

---

## 11. Common Pitfalls & How to Avoid Them

| Pitfall | Fix |
|---|---|
| Seeding with too many elements | Seed with only `min(k, size)` entries |
| Forgetting null/bounds check before push | Always guard: `if (node->next)` / `if (j+1 < n)` |
| Wrong comparator direction | Min-heap → `greater<>` or `a > b`; Max-heap → `less<>` or `a < b` |
| Duplicate entries in heap | Track visited indices with a `set<pair<int,int>>` if needed |
| Not using structured bindings | Use `auto [val, i, j] = heap.top()` for clarity |
| Mutating original list during merge | Work via pointers/indices, not values |

---

## 12. Complexity Summary

| Scenario | Time | Space |
|---|---|---|
| Merge K lists, N total elements | O(N log K) | O(K) |
| K pairs from two arrays of size m, n | O(K log K) | O(K) |
| Kth smallest in N×N matrix | O(K log N) | O(N) |
| K largest from unsorted array of N | O(N log K) | O(K) |

---

## 13. C++ Heap Quick Reference

```cpp
// MIN-HEAP (smallest on top)
priority_queue<int, vector<int>, greater<int>> minH;

// MAX-HEAP (largest on top) — default
priority_queue<int> maxH;

// MIN-HEAP of pairs (sorted by first element)
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minH;

// MIN-HEAP with custom comparator
auto cmp = [](Node* a, Node* b){ return a->val > b->val; };
priority_queue<Node*, vector<Node*>, decltype(cmp)> minH(cmp);

// Common operations
minH.push(val);      // O(log n)
minH.top();          // O(1)  — peek
minH.pop();          // O(log n)
minH.empty();        // O(1)
minH.size();         // O(1)
```

---

## 14. Problem-Solving Checklist

When you encounter a new problem, run through this:

```
[ ] Does it ask for K smallest / K largest / Kth element?
[ ] Is there a sorted structure I can exploit?
[ ] What is one "unit" of work? (pop one element → push next)
[ ] What goes INTO the heap? (value + indices to regenerate next)
[ ] What is the seeding strategy? (one per list? one per row? all?)
[ ] What is the "next candidate" rule after a pop?
[ ] Do I need to track visited cells to avoid duplicates?
[ ] What is the termination condition? (k == 0 or heap empty)
```

---

## 15. Final Tips
- Always start with a clear understanding of the problem and the data structure.
- Write out the heap entries on paper to visualize the frontier.
- Test your logic on a small example to ensure the seeding and next candidate rules are correct.
- Remember that the heap is just a tool to manage the frontier — the real logic is in how you generate candidates and when you stop.