# Longest Common Subsequence (LCS) & Variants

A collection of LeetCode questions related to Longest Common Subsequence (LCS) and its variants, grouped by difficulty and DP patterns.

## 🟢 EASY (LCS Basics)

| Question | Description / Pattern |
| :--- | :--- |
| **1143 – Longest Common Subsequence** | ➜ 2D DP (Length only) |
| **1035 – Uncrossed Lines** | ➜ LCS in disguise (arrays) |

## 🟡 MEDIUM (Core Variants)

| Question | Description / Pattern |
| :--- | :--- |
| **718 – Maximum Length of Repeated Subarray** | ➜ Longest Common Substring |
| **516 – Longest Palindromic Subsequence** | ➜ LCS(s, reverse(s)) |
| **583 – Delete Operation for Two Strings** | ➜ Formula using LCS |
| **712 – Minimum ASCII Delete Sum for Two Strings** | ➜ Weighted LCS variant |
| **115 – Distinct Subsequences** | ➜ Counting DP (not length) |
| **1312 – Minimum Insertion Steps to Make a String Palindrome** | ➜ Based on LPS |

## 🔴 HARD / PREMIUM (Advanced Thinking)

| Question | Description / Pattern |
| :--- | :--- |
| **1092 – Shortest Common Supersequence** | ➜ Construct string from LCS DP |
| **1062 (Premium) – Longest Repeating Substring** | ➜ LCS with i ≠ j |
| **1216 (Premium) – Valid Palindrome III** | ➜ LCS + deletions constraint |

---

## 🧠 DP PATTERN CHEAT SHEET

| Pattern | Question Numbers |
| :--- | :--- |
| Classic LCS (2D DP) | 1143, 1035 |
| Longest Substring | 718 |
| LCS + Reverse | 516, 1312 |
| LCS + Operations | 583, 712 |
| Counting Subsequences | 115 |
| Construction from LCS | 1092 |
| Self-LCS Trick | 1062 |
| Constraint-based | 1216 |

## 🔑 Interview Tip

> If order matters but continuity doesn’t → think **LCS** immediately.
