# Non-Overlapping Events / Intervals — Variants

A collection of LeetCode questions related to non-overlapping events and intervals, grouped by difficulty and patterns.

## 🟢 EASY (Basics)

| Question | Description / Pattern |
| :--- | :--- |
| **252 – Meeting Rooms (Premium)** | ➜ Simple overlap check |
| **435 – Non-overlapping Intervals** | ➜ Simple overlap check |

## 🟡 MEDIUM (Greedy / Sorting)

| Question | Description / Pattern |
| :--- | :--- |
| **253 – Meeting Rooms II (Premium)** | ➜ Min rooms / resources |
| **646 – Maximum Length of Pair Chain** | ➜ Greedy chain |
| **1024 – Video Stitching** | ➜ Greedy chain |

## 🔵 MEDIUM–HARD (DP / Binary Search)

| Question | Description / Pattern |
| :--- | :--- |
| **1235 – Maximum Profit in Job Scheduling** | ➜ Interval DP + binary search |
| **1751 – Maximum Number of Events That Can Be Attended II** | ➜ Interval DP + binary search |
| **2008 – Maximum Earnings From Taxi** | ➜ Interval DP + binary search |

## 🔴 HARD (Advanced DP / Optimization)

| Question | Description / Pattern |
| :--- | :--- |
| **2054 – Two Best Non-Overlapping Events** | ➜ Pick best 2 events |
| **1353 – Maximum Number of Events That Can Be Attended** | ➜ Event scheduling with deadlines |

---

## 🧠 PATTERN CHEAT SHEET

| Pattern | Question Numbers |
| :--- | :--- |
| Simple overlap check | 252, 435 |
| Min rooms / resources | 253 |
| Greedy chain | 646, 1024 |
| Interval DP + binary search | 1235, 1751, 2008 |
| Pick best 2 events | 2054 |
| Event scheduling with deadlines | 1353 |

## 🔑 Recognition Rules (Interview Gold)

> “No overlap allowed” → sort by end time
>
> “Max profit / value” → DP + binary search
>
> “Pick at most k events” → DP[i][k], where k is the maximum number of events
>
> “Attend max events (1/day)” → priority queue
>
> Intervals + optimization = sort → greedy or DP
