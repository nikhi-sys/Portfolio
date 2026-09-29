#include <stdio.h>
#include <string.h>

int main() {
    char s[] = "anagram";
char t[] = "nagaram";

    int count[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
    }

    for (int i = 0; t[i] != '\0'; i++) {
        count[t[i] - 'a']--;
    }

    int isAnagram = 1;

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            isAnagram = 0;
            break;
        }
    }

    if (isAnagram)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}