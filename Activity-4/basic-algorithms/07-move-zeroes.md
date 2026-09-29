# Move Zeroes

## Problem / Difficulty
Move all zeroes to the end of the array while maintaining the relative order of non-zero elements.

**Difficulty:** Easy

## LeetCode Link
https://leetcode.com/problems/move-zeroes/

## Approach
Keep a position for the next non-zero element.
Move all non-zero elements forward, then fill the remaining positions with zeroes.

## Complexity

**Time Complexity:** O(n)

**Space Complexity:** O(1)

## Notes
- Tested locally with [0,1,0,3,12] → [1,3,12,0,0].
- Tested locally with [0,0,1] → [1,0,0].
- LeetCode result: Accepted.