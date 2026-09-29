#include <stdio.h>

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int n = 4;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                printf("[%d, %d]\n", i, j);
                return 0;
            }
        }
    }

    return 0;
}
/*
Test Case 1 - Typical Case
Input: nums = [2,7,11,15], target = 9
Expected Output: [0,1]

Test Case 2 - Edge Case with Duplicate Values
Input: nums = [3,3], target = 6
Expected Output: [0,1]
*/