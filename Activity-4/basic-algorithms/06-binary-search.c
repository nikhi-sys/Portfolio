#include <stdio.h>

int main() {
    int nums[] = {-1, 0, 3, 5, 9, 12};
    int n = 6;
    int target = 9;

    int left = 0;
    int right = n - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            result = mid;
            break;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("%d\n", result);

    return 0;
}