# Binary Search

## Problem / Difficulty
Search for a target value in a sorted array and return its index.

**Difficulty:** Easy

## LeetCode Link
https://leetcode.com/problems/binary-search/

## Approach
Use two pointers, left and right, to repeatedly divide the search range in half.
Compare the middle element with the target and eliminate half of the array each time.

## Complexity

**Time Complexity:** O(log n)

**Space Complexity:** O(1)

## Notes
- Tested locally with target 9 → index 4.
- Tested locally with target 2 → -1.
- LeetCode result: Accepted.