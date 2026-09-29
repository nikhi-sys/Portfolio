#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "hello";

    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }

    printf("%s\n", str);

    return 0;
}