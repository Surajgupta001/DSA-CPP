# Meet In The Middle (MITM)

## Concept & Questions: What? Why? How?

- **Not an algorithm** — there's no fixed template to memorize.
- It's simply a **technique/way of solving problems efficiently** by splitting work in half.

### The core idea

```plaintext
Input: { n elements }, size = n

           split
          /      \
     n/2          n/2
      |            |
  operation    operation
      |            |
    2^(n/2)      2^(n/2)
      |            |
   { subset }   { subset }
        \        /
     merge two half-arrays
```

- Normally, brute-forcing all possibilities over `n` elements costs **O(2ⁿ)** — exponential.
- MITM splits the array into two halves of size `n/2` each, solves each half independently (cost `O(2^(n/2))` per half), and then **merges** the two results efficiently.
- Since `2^(n/2) + 2^(n/2)` (plus merge cost) is far smaller than `2ⁿ`, this makes previously infeasible brute-force problems solvable.

> **MITM is a technique where the search space is divided into two parts of about equal size. A separate search is performed on both halves, and in the end the results are combined.**

**Used when:**

- There is an efficient way to combine the results of the two halves.
- The two halves together require less time than one single full search.

---

## Deep Dive — Example Problem

**Problem:** Count the number of subsets of `nums` whose sum equals `x`.

Constraints:

- `1 ≤ n ≤ 40`
- `1 ≤ x ≤ 10⁹`

```plaintext
nums = {1, 2, 3, 2},  n = 4,  x = 5  (target sum)

Valid subsets:
  {1, 2, 2}
  {2, 3}
  {3, 2}

Output = 3
```

### Approach 1 — DP (recursion)

```cpp
// solve(0, x)  →  dp[i][x] is the 2D state (n * x → time complexity)

solve(i, x) {
    if (i == n) {
        if (x == 0) return 1;
        return 0;
    }

    skip = solve(i+1, x);

    if (x >= nums[i]) {
        take = solve(i+1, x - nums[i]);
        return skip + take;
    }

    return skip;
}
```

- State space is `n * x`. Since `x` can be up to `10⁹`, this DP is **not feasible** — the table would be far too large.

### Approach 2 — Meet In The Middle

Split `nums` into two halves:

```plaintext
n1 = n / 2
n2 = n - n1
```

For each half, generate **all possible subset sums** (2ⁿ¹ and 2ⁿ² of them respectively).

```plaintext
nums = {1, 2 | 3, 2},  n = 4,  x = 5

Left half {1,2}:            Right half {3,2}:
  {}    = 0                   {}    = 0
  {1}   = 1                   {3}   = 3
  {2}   = 2                   {2}   = 2
  {1,2} = 3                   {3,2} = 5

Subset Sum A = {0, 1, 2, 3}
Subset Sum B = {0, 2, 3, 5}
```

For every value `a` in Subset Sum A, look for `x - a` in Subset Sum B (via **binary search**, since B is sorted).

```plaintext
Example: a = 3  →  x - a = 5 - 3 = 2  →  present in B ({2}) ✔
          → combine {2} (from A) with {3} (from B) → {2,3} sums to 5
```

### Complexity

```plain
n1 = n/2,  n2 = n - n1

Subset Sum A = {0,1,2,3}     (2^n1 subsets)
Subset Sum B = {0,2,3,5}     (2^n2 subsets, sorted)

x_rem = x - a         (value to search for in B)

Sort B → O(n2 · log n2)
Search each a in A using binary search → O(log n2) per lookup

Efficient merging = O(2^n1 * log(n2))
```

This is dramatically cheaper than brute force `O(2ⁿ)`.

---

## One More Example (with duplicate sums)

```plaintext
nums = {1, 2, 3 | 3, 3, 3},  x = 3,  n = 6
        n1 = n/2   n2 = n - n1
```

**Left half subset sums {1,2,3}:**

```plaintext
{}      = 0
{1}     = 1
{2}     = 2
{1,2}   = 3
{3}     = 3
{1,3}   = 4
{2,3}   = 5
{1,2,3} = 6

```plaintext
Subset Sum A (sorted) = `{0,1,2,3,3,4,5,6}`

**Right half subset sums {3,3,3}:**
```plaintext
{}       = 0
{3}      = 3
{3}      = 3
{3}      = 3
{3,3}    = 6
{3,3}    = 6
{3,3}    = 6
{3,3,3}  = 9

```plaintext
Subset Sum B (sorted) = `{0,3,3,3,6,6,6,9}`

### Merging

Take `a = 0` from A → `x_rem = x - a = 3 - 0 = 3`.
Search `3` in B → found (appears 3 times: indices 1, 2, 3).

```plaintext
lowerBound(3) = index 1
upperBound(3) = index 4
count = upperBound - lowerBound = 4 - 1 = 3
```

So there are **3 subsets** `{0}+{3}` combinations that sum to the target `3`.
(This uses `lower_bound` / `upper_bound` on the sorted array to count duplicates in O(log n2).)

---

## How to Find All Subset Sums (Bitmask Method)

Use recursion or a nested loop with **bitmasking** — each bit represents whether an element is included.

```plaintext
Subset Sum A = {2, 5, 1}   (indices: 0, 1, 2)

mask = 000 → {}        (nothing taken)
mask = 001 → {2}        (bit 0 set → index 0 taken)
mask = 010 → {5}        (bit 1 set → index 1 taken)
mask = 011 → {2, 5}     (bits 0,1 set)
mask = 100 → {1}        (bit 2 set → index 2 taken)
mask = 101 → {2, 1}
mask = 110 → {5, 1}
mask = 111 → {2, 5, 1}
```

- For `n1` elements, masks range from `0` to `2^n1 - 1` → total `2^n1` subsets.

```cpp
for (mask = 0; mask < (1 << n1); mask++) {
    for (i = 0; i <= n1 - 1; i++) {
        if (mask & (1 << i)) {
            sum += nums[i];
        }
    }
    subsetSumA.push_back(sum);
}
// Similar logic for subsetSumB
```

**Important question:** How is this different from Divide & Conquer?
> D&C recursively breaks a problem into subproblems of the *same type* and combines them (e.g., merge sort). MITM specifically splits into **exactly two halves**, exhaustively enumerates all possibilities in each half, and merges via search/matching — it's built for problems where brute force is exponential but splitting makes each half's exhaustive enumeration tractable.

---

## Story → Code (General Recipe)

1. `n1 = n/2 ; n2 = n - n1`
2. Generate `subsetSumA` and `subsetSumB` (all possible subset sums for each half).
3. Sort `subsetSumB`.
4. **Merge efficiently** to find subsets whose sum equals the target:
   - For each value in `subsetSumA`, compute `x_rem = x - a`.
   - **Search** for `x_rem` in `subsetSumB` using `lower_bound` / `upper_bound` (binary search).

---

## When to Think of Applying MITM

Consider MITM when the **natural/brute-force solution is exponential**:

1. **Constraints:** `n ≤ 40` (roughly 30–45).
   - Too big for brute force `O(2ⁿ)`.
   - But perfect for `O(2^(n/2))`.

2. **Brute force is exponential, not polynomial:**
   - e.g., "try all `2ⁿ` subsets" or "try all `2ⁿ` combinations."
   - If brute force were already `O(n²)` or `O(n³)`, MITM has nothing to add — it's meant to tame **exponential** blow-up.

3. **DP doesn't work** because of huge constraints (e.g., sum/target up to `10⁹`, making the DP table infeasible).

4. **The result is:** choose one option from the first part, combined with one option from the second part.
   > "MITM splits the problem cleanly into 2 halves only."

5. **Pattern:** matching / counting / optimizing over pairs from two groups.

---

## How to Identify a MITM Problem by Constraints

This is the fastest way to spot MITM in a contest/interview setting — **look at `n` first, before thinking about the algorithm.**

| `n` (input size) | What it usually signals |
|---|---|
| `n ≤ 20` | Plain brute force `O(2ⁿ)` or `O(n · 2ⁿ)` is fine |
| `n ≈ 30 – 45` | 🚩 **Classic MITM zone.** `O(2ⁿ)` is too slow, but `O(2^(n/2))` fits comfortably |
| `n ≤ 100` with small value range | Usually DP, not MITM |
| `n ≤ 1000` or more | DP / Greedy / Graph algorithms, not MITM |

Other red flags in the problem statement, alongside a small `n`:

- **Target value or sum is huge** (e.g., `x ≤ 10⁹`) — this *kills* a DP approach (`O(n·x)` table is impossible), even though `n` itself is small. This mismatch — "small n, huge secondary constraint" — is one of the strongest MITM signals.
- The problem says or implies: *count/find subsets, subsequences, combinations, pairs, or assignments* satisfying some condition (sum, XOR, product, etc.).
- Brute force naturally enumerates **all 2ⁿ subsets** (or `k^n` combinations for `k` choices per element) — i.e., the search space is a power set or a Cartesian product, not a sequential/optimal-substructure problem.
- No efficient greedy or DP recurrence exists (no clean "state" that keeps the table small).
- The answer only needs **combining independently computed halves** — no complex interaction that spans across the split point.

**Quick mental test:**
> "If I split my array/choices into two halves and solved each half completely on its own, could I combine the two answers with a search, sort, or hashmap lookup?"
If yes → MITM is very likely applicable.

---

## Where MITM Is Commonly Used (Problem Patterns)

- **Subset Sum / Count subsets equal to target** (the example above).
- **Closest subset sum to a target** — generate both halves' sums, sort one, and for each value in the other, binary-search for the closest match.
- **0/1 Knapsack with large weight/value limits** — split items into two halves, generate all `(weight, value)` pairs per half, sort one half by weight and keep a running max value (prefix-max), then binary search the other half.
- **XOR / bitwise problems** — e.g., "find two elements from disjoint halves whose XOR is maximum" — build values for each half and use a trie or hashmap to combine.
- **4-SUM problem** (find 4 numbers summing to a target) — split into pairs, compute all pairwise sums for both halves, then two-pointer or hashmap merge.
- **Counting equal-sum partitions / balanced subsets.**
- **Cryptography** — the *original* use of MITM (Diffie–Hellman-style attacks, meet-in-the-middle attack on double encryption like 2DES) — encrypt from one side, decrypt from the other, and match in the middle. This is where the name comes from.
- **Graph/State-space search** — e.g., searching for a path between two states where forward search from the start and backward search from the goal are both run halfway, then matched (classic in pathfinding / puzzle solving, like the 15-puzzle or word-ladder variants).

---

## General MITM Solution Template

```cpp
// Step 1: Split into two halves
int n1 = n / 2, n2 = n - n1;

// Step 2: Generate ALL possible results for each half
vector<long long> A, B;
generateAll(nums, 0, n1, A);        // 2^n1 combinations
generateAll(nums, n1, n, B);        // 2^n2 combinations

// Step 3: Sort the half you'll be searching into
sort(B.begin(), B.end());

// Step 4: Merge — for each value in A, search for the complement in B
long long count = 0;
for (long long a : A) {
    long long need = x - a;
    // use binary search / lower_bound / upper_bound / hashmap
    auto lo = lower_bound(B.begin(), B.end(), need);
    auto hi = upper_bound(B.begin(), B.end(), need);
    count += (hi - lo);
}
```

**Complexity:** `O(2^n1) + O(2^n2 · log(2^n2)) + O(2^n1 · log(2^n2))`
≈ `O(2^(n/2) · (n/2))` — far better than brute force `O(2ⁿ)`.

---

## Full Working Example — Subset Sum Count (CSES-style)

**Problem:** Given `n` numbers, count the number of subsets whose sum equals `x`.

```plaintext
Constraints:
1 <= n <= 40
1 <= x <= 10^9
1 <= t_i <= 10^9

Example
Input:
4 5
1 2 3 2

Output:
3
```

This is the exact template shape used above, filled in end-to-end:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int n;
    ll x;
    cin >> n >> x;

    vector<ll> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int n1 = n / 2;
    int n2 = n - n1;

    // Generate all subset sums of the FIRST half (2^n1 subsets)
    vector<ll> sumsA(1 << n1); // size of 2^n1
    for(int mask = 0; mask < (1 << n1); mask++){
        ll sum = 0;
        for(int i = 0; i < n1; i++){
            if(mask & (1 << i)){
                sum += v[i];
            }
        }
        sumsA[mask] = sum;
    }

    // Generate all subset sums of the SECOND half (2^n2 subsets)
    vector<ll> sumsB(1 << n2); // size of 2^n2
    for(int mask = 0; mask < (1 << n2); mask++){
        ll sum = 0;
        for(int i = 0; i < n2; i++){
            if(mask & (1 << i)){
                sum += v[n1 + i]; // offset into the second half of v
            }
        }
        sumsB[mask] = sum;
    }

    // Sort B once, so we can binary-search into it for every value in A
    sort(sumsB.begin(), sumsB.end());

    ll count = 0;
    for(auto sum : sumsA){
        ll needed = x - sum; // remaining sum needed from sumsB
        auto low = lower_bound(sumsB.begin(), sumsB.end(), needed);
        auto high = upper_bound(sumsB.begin(), sumsB.end(), needed);

        count += (high - low); // number of subsets in B that make up `needed`
    }

    cout << count << "\n";

    return 0;
}
```

### Walking through the example

```plaintext
n = 4, x = 5,  v = {1, 2, 3, 2}
n1 = 2, n2 = 2

First half  v[0..1] = {1, 2} → sumsA = {0, 1, 2, 3}
Second half v[2..3] = {3, 2} → sumsB = {0, 3, 2, 5} → sorted → {0, 2, 3, 5}

For each sum in sumsA, find how many values in sumsB equal (x - sum):
  sum = 0 → needed = 5 → found {5}   → +1
  sum = 1 → needed = 4 → none        → +0
  sum = 2 → needed = 3 → found {3}   → +1
  sum = 3 → needed = 2 → found {2}   → +1

Total count = 3  ✔ (matches expected output)
```

### Why each piece matters

| Line / Step | Purpose |
|---|---|
| `1 << n1`, `1 << n2` | Total number of subsets (bitmask enumeration) of each half |
| `mask & (1 << i)` | Checks if element `i` is included in the current subset |
| `v[n1 + i]` in the second loop | Offsets into the original array so the second half reads its own elements, not the first half's |
| `sort(sumsB...)` | Required before binary search; only sort once, outside the merge loop |
| `lower_bound` / `upper_bound` | Together give the **count of matching elements**, correctly handling duplicate sums (e.g., multiple subsets producing the same sum) |
| `ll` (long long) everywhere | `t_i` up to `10^9` and up to 40 elements means sums can exceed the range of a 32-bit `int` |

### Complexity of this exact code

- Generating `sumsA`: `O(2^n1 · n1)`
- Generating `sumsB`: `O(2^n2 · n2)`
- Sorting `sumsB`: `O(2^n2 · log(2^n2))`
- Merge loop: `O(2^n1 · log(2^n2))`

With `n1 ≈ n2 ≈ n/2 = 20`, this is roughly `2^20 · 20 ≈ 2×10⁷` operations — comfortably fast, whereas brute force `O(2⁴⁰)` would be astronomically slow.

---

## Complexity Comparison

| Approach | Time Complexity | Feasible when |
|---|---|---|
| Brute Force | `O(2ⁿ)` | `n ≤ ~20` |
| DP (sum/target as state) | `O(n · x)` | `x` (target) is small, e.g., `x ≤ 10⁵` |
| **Meet In The Middle** | `O(2^(n/2) · n)` (generation + merge) | `n ≤ ~40`, target `x` can be huge |
| Meet In The Middle + Hashmap | `O(2^(n/2))` avg (no sorting needed) | Same as above, when exact match (not range) is needed |

> Tip: If you only need to check *existence* of a matching sum (not counting duplicates or ranges), a **hashmap/unordered_set** on one half avoids the `log(n2)` factor from binary search, giving average `O(1)` lookups instead.

---

## Common Pitfalls / Things to Watch For

- **Overflow:** subset sums of up to `2^20` elements can exceed `int` range — use `long long`.
- **Off-by-one in splitting:** make sure `n1 + n2 == n` and every index is covered exactly once between the two halves.
- **Duplicate values:** if counting *distinct subsets* rather than *distinct sums*, remember that `lower_bound`/`upper_bound` range-counting (as in the "One More Example" section) correctly counts duplicate sums as separate subsets — don't accidentally deduplicate with a `set` if duplicates matter.
- **Sorting overhead:** always sort the *smaller-to-search* half once, not inside the loop — sorting inside the loop silently turns `O(2^(n/2)·log(n))` into something far worse.
- **Choosing which half to sort:** doesn't usually matter for complexity, but sort whichever half you're searching *into* (not the one you're iterating over).
- **Using MITM when DP would just work:** don't reach for MITM if `x` (target) is small enough for a normal DP — MITM adds implementation complexity (two generation passes + merge logic) that isn't needed if a simpler polynomial DP fits the constraints.

---

## MITM vs Divide & Conquer vs DP — Quick Contrast

| | Divide & Conquer | Dynamic Programming | Meet In The Middle |
|---|---|---|---|
| Splits problem into | Multiple recursive subproblems of the *same* structure | Overlapping subproblems with a recurrence | Exactly **two** independent halves |
| Combines via | Recursive merge (e.g., merge sort, quicksort) | Recurrence relation / memoized table | Search (binary search / hashmap) across two precomputed result sets |
| Goal | Reduce time complexity of an already-polynomial-ish process | Avoid recomputation via optimal substructure | Turn an exponential `O(2ⁿ)` brute force into `O(2^(n/2))` |
| Typical use | Sorting, searching, matrix multiplication | Optimal substructure problems (knapsack, LIS, edit distance) | Subset/combination enumeration problems with small `n` but large value ranges |

---

## Summary Table

| Aspect | Detail |
|---|---|
| Type | Technique, not a fixed algorithm |
| When to use | Brute force is `O(2ⁿ)`, `n` is small-ish (≤ ~40) |
| Core idea | Split into 2 halves → enumerate each half fully → merge |
| Per-half cost | `O(2^(n/2))` |
| Merge cost | `O(2^(n1) · log(n2))` using sorting + binary search |
| Total complexity | Roughly `O(2^(n/2) · n/2)` — exponentially better than `O(2ⁿ)` |
| Typical use cases | Subset-sum counting, meeting-in-the-middle knapsack, pairs matching across two halves |
