# Valid Anagram

## Problem / Difficulty
Determine whether two strings are anagrams of each other.

**Difficulty:** Easy

## LeetCode Link
https://leetcode.com/problems/valid-anagram/

## Approach
Use a frequency array of 26 letters.
Increase the count for each character in the first string and decrease it for each character in the second string.
If all counts are zero, the strings are anagrams.

## Complexity

**Time Complexity:** O(n)

**Space Complexity:** O(1)

## Notes
- Tested locally with "anagram" and "nagaram" → true.
- Tested locally with "rat" and "car" → false.
- LeetCode result: Accepted.