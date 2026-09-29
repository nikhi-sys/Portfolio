#include <stdio.h>
#include <string.h>

int main() {
    char *strs[] = {"flower", "flow", "flight"};
    int n = 3;

    int i = 0;

    while (strs[0][i] != '\0') {
        for (int j = 1; j < n; j++) {
            if (strs[j][i] != strs[0][i]) {
                printf("%.*s\n", i, strs[0]);
                return 0;
            }
        }
        i++;
    }

    printf("%s\n", strs[0]);

    return 0;
}