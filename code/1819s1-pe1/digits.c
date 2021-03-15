#include <stdio.h>
#include <stdlib.h>

void get_next_subsequence(long *n, long *digit, long *count)
{
    long d = *n % 10;
    long cnt = 1;
    *n /= 10;

    while (*n > 0 && *n % 10 == d) {
        cnt++;
        *n /= 10;
    }

    *digit = d;
    *count = cnt;
}

int main()
{
    long n;
    scanf("%ld", &n);

    long current_longest;
    long current_longest_cnt;

    get_next_subsequence(&n, &current_longest, &current_longest_cnt);

    while (n > 0) {
        long current;
        long current_cnt;

        get_next_subsequence(&n, &current, &current_cnt);

        if (current_cnt == current_longest_cnt && current < current_longest) {
            current_longest = current;
        } else if (current_cnt > current_longest_cnt) {
            current_longest = current;
            current_longest_cnt = current_cnt;
        }
    }

    printf("%ld [%ld] %ld\n", n, current_longest, current_longest_cnt);
}
