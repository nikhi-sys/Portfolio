# Reverse a Linked List

## Problem
**Difficulty:** Easy

Given the head of a singly linked list, reverse the list and return the reversed list.

## Link
https://leetcode.com/problems/reverse-linked-list/

## Approach
Use three pointers:
- `prev` stores the previous node.
- `current` stores the current node.
- `next` temporarily stores the next node.

Move through the list and reverse each `next` pointer until the end is reached.

## Complexity
- **Time:** O(n)
- **Space:** O(1)

## Notes
Tested locally with:

- Input: `1 → 2 → 3`
- Output: `3 → 2 → 1`

The solution was also submitted to LeetCode.