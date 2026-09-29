# Longest Common Prefix

## Problem / Difficulty
Find the longest common prefix shared by all strings.

**Difficulty:** Easy

## LeetCode Link
https://leetcode.com/problems/longest-common-prefix/

## Approach
Compare the characters of the first string with the corresponding characters of the other strings.
Stop when a mismatch is found.

## Complexity

**Time Complexity:** O(n × m)

**Space Complexity:** O(1)

## Notes
- Tested locally with ["flower","flow","flight"] → "fl".
- Tested locally with ["dog","racecar","car"] → "".
- LeetCode result: Accepted.