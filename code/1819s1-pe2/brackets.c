#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define BUFSIZE 4096*4096

bool is_open(char c)
{
    return c == '(' || c == '{' || c == '<' || c == '[';
}

bool is_match(char c1, char c2)
{
    return (c1 == '(' && c2 == ')')
            || (c1 == '{' && c2 == '}')
            || (c1 == '<' && c2 == '>')
            || (c1 == '[' && c2 == ']');
}

long check_brackets(char *s, long len, long i)
{
    if (i == len) {
        return i;
    }

    char c = s[i];

    if (!is_open(c)) {
        return i;
    }

    long end = check_brackets(s, len, i + 1);
    if (is_match(c, s[end])) {
        return check_brackets(s, len, end + 1);
    }
    return i;
}

int main()
{
    char *s = malloc(BUFSIZE);
    scanf("%[^\n]", s);

    long i = check_brackets(s, strlen(s), 0);

    if (s[i] == '\0') {
        printf("yes\n");
    } else {
        printf("no\n");
    }
}
