#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define BUFSIZE 4096*4096

bool isletter(char c)
{
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

char *clean_up(char *s)
{
    size_t len = strlen(s);
    char *ret = malloc(len + 1);

    long k = 0;

    long i;
    for (i = 0; s[i] != '\0'; i++) {
        if (isletter(s[i])) {
            ret[k] = tolower(s[i]);
            k++;
        }
    }
    ret[k] = '\0';
    return ret;
}

bool is_palindrome(char *s)
{
    long i = 0;
    long j = strlen(s) - 1;

    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main()
{
    char *s = malloc(BUFSIZE);
    scanf("%[^\n]", s);

    char *t = clean_up(s);

    if (is_palindrome(t)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
}
