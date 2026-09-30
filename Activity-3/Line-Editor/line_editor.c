#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 1024

static char **lines = NULL;
static int count = 0;
static int capacity = 0;

static char *copy_string(const char *s)
{
    char *p = malloc(strlen(s) + 1);
    if (p != NULL) {
        strcpy(p, s);
    }
    return p;
}

static int ensure_capacity(void)
{
    if (count < capacity) {
        return 1;
    }
    int new_cap = (capacity == 0) ? 8 : capacity * 2;
    char **tmp = realloc(lines, new_cap * sizeof(char *));
    if (tmp == NULL) {
        return 0;
    }
    lines = tmp;
    capacity = new_cap;
    return 1;
}

static void strip_newline(char *s)
{
    size_t len = strlen(s);
    while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r')) {
        s[--len] = '\0';
    }
}

static int parse_number(char **p, int *out)
{
    while (isspace((unsigned char)**p)) {
        (*p)++;
    }
    char *end;
    long v = strtol(*p, &end, 10);
    if (end == *p) {
        return 0;
    }
    *out = (int)v;
    *p = end;
    return 1;
}

static char *skip_spaces(char *p)
{
    while (isspace((unsigned char)*p)) {
        p++;
    }
    return p;
}

static int insert_line(int n, const char *text)
{
    if (n < 1 || n > count + 1) {
        printf("Error: line number must be between 1 and %d.\n", count + 1);
        return 0;
    }
    if (!ensure_capacity()) {
        printf("Error: out of memory.\n");
        return 0;
    }
    char *copy = copy_string(text);
    if (copy == NULL) {
        printf("Error: out of memory.\n");
        return 0;
    }
    for (int i = count; i > n - 1; i--) {
        lines[i] = lines[i - 1];
    }
    lines[n - 1] = copy;
    count++;
    return 1;
}

static int delete_line(int n)
{
    if (count == 0) {
        printf("Error: the document is empty, nothing to delete.\n");
        return 0;
    }
    if (n < 1 || n > count) {
        printf("Error: line %d does not exist (valid: 1 to %d).\n", n, count);
        return 0;
    }
    free(lines[n - 1]);
    for (int i = n - 1; i < count - 1; i++) {
        lines[i] = lines[i + 1];
    }
    count--;
    return 1;
}

static void display_document(void)
{
    if (count == 0) {
        printf("(document is empty)\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("%3d: %s\n", i + 1, lines[i]);
    }
}

static void free_document(void)
{
    for (int i = 0; i < count; i++) {
        free(lines[i]);
    }
    free(lines);
    lines = NULL;
    count = 0;
    capacity = 0;
}

static void save_file(const char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: could not open '%s' for writing.\n", filename);
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s\n", lines[i]);
    }
    fclose(fp);
    printf("Saved %d line(s) to '%s'.\n", count, filename);
}

static void load_file(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open '%s' for reading.\n", filename);
        return;
    }
    free_document();
    char buf[MAX_INPUT];
    while (fgets(buf, sizeof buf, fp) != NULL) {
        strip_newline(buf);
        if (!insert_line(count + 1, buf)) {
            break;
        }
    }
    fclose(fp);
    printf("Loaded %d line(s) from '%s'.\n", count, filename);
}

static void search_word(const char *word)
{
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(lines[i], word) != NULL) {
            printf("Found on line %d: %s\n", i + 1, lines[i]);
            found++;
        }
    }
    if (found == 0) {
        printf("'%s' not found.\n", word);
    }
}

static void show_counts(void)
{
    int words = 0;
    for (int i = 0; i < count; i++) {
        int in_word = 0;
        for (const char *p = lines[i]; *p != '\0'; p++) {
            if (isspace((unsigned char)*p)) {
                in_word = 0;
            } else if (!in_word) {
                in_word = 1;
                words++;
            }
        }
    }
    printf("Lines: %d, Words: %d\n", count, words);
}

static void print_help(void)
{
    printf("Commands:\n");
    printf("  i <n> <text>   insert text as line n\n");
    printf("  a <text>       append text at the end\n");
    printf("  d <n>          delete line n\n");
    printf("  p              print the document\n");
    printf("  w <file>       save to file\n");
    printf("  l <file>       load from file (replaces document)\n");
    printf("  s <word>       search for a word or phrase\n");
    printf("  c              show line and word count\n");
    printf("  h              show this help\n");
    printf("  q              quit\n");
}

int main(void)
{
    char input[MAX_INPUT];

    printf("Simple Line Editor. Type 'h' for help.\n");

    while (1) {
        printf("> ");
        if (fgets(input, sizeof input, stdin) == NULL) {
            break;
        }
        strip_newline(input);

        char *p = skip_spaces(input);
        if (*p == '\0') {
            continue;
        }

        char cmd = *p;
        p++;

        if (cmd == 'i') {
            int n;
            if (!parse_number(&p, &n)) {
                printf("Usage: i <line_number> <text>\n");
            } else {
                p = skip_spaces(p);
                if (insert_line(n, p)) {
                    printf("Inserted at line %d.\n", n);
                }
            }
        } else if (cmd == 'a') {
            p = skip_spaces(p);
            if (insert_line(count + 1, p)) {
                printf("Appended as line %d.\n", count);
            }
        } else if (cmd == 'd') {
            int n;
            if (!parse_number(&p, &n)) {
                printf("Usage: d <line_number>\n");
            } else if (delete_line(n)) {
                printf("Deleted line %d.\n", n);
            }
        } else if (cmd == 'p') {
            display_document();
        } else if (cmd == 'w') {
            p = skip_spaces(p);
            if (*p == '\0') {
                printf("Usage: w <filename>\n");
            } else {
                save_file(p);
            }
        } else if (cmd == 'l') {
            p = skip_spaces(p);
            if (*p == '\0') {
                printf("Usage: l <filename>\n");
            } else {
                load_file(p);
            }
        } else if (cmd == 's') {
            p = skip_spaces(p);
            if (*p == '\0') {
                printf("Usage: s <word or phrase>\n");
            } else {
                search_word(p);
            }
        } else if (cmd == 'c') {
            show_counts();
        } else if (cmd == 'h') {
            print_help();
        } else if (cmd == 'q') {
            break;
        } else {
            printf("Unknown command '%c'. Type 'h' for help.\n", cmd);
        }
    }

    free_document();
    printf("Goodbye!\n");
    return 0;
}