# Valid Parentheses

## Problem / Difficulty
Determine whether a string containing brackets is valid.

**Difficulty:** Easy

## LeetCode Link
https://leetcode.com/problems/valid-parentheses/

## Approach
Use a stack to store opening brackets.
When a closing bracket appears, check whether it matches the most recent opening bracket.

## Complexity

**Time Complexity:** O(n)

**Space Complexity:** O(n)

## Notes
- Tested locally with "()[]{}" → true.
- Tested locally with "(]" → false.
- LeetCode result: Accepted.