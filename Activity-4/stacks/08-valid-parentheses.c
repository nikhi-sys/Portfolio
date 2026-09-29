#include <stdio.h>
#include <string.h>

int main() {
    char s[] = "()[]{}";
    char stack[100];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        } else {
            if (top == -1) {
                printf("false\n");
                return 0;
            }

            char open = stack[top--];

            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                printf("false\n");
                return 0;
            }
        }
    }

    if (top == -1)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}