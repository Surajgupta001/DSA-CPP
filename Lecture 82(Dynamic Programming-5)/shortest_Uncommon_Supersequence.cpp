/*
Given two strings S and T, find the length of the shortest subsequence in S which is not a subsequence in T. If no such subsequence is possible, return -1. A subsequence is a sequence that appears in the same relative order, but is not necessarily contiguous. A string of length n has 2^n different possible subsequences.

String S of length m (1 <= m <= 1000) 
String T of length n (1 <= n <= 1000)

Examples: 


Input : S = “babab” T = “babba”
Output : 3
Explanation: The subsequence “aab” of length 3 is present in S but not in T.


Input :  S = “abb” T = “abab”
Output : -1
Explanation: There is no subsequence that is present in S but not in T.
*/ 