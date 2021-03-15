#include <stdio.h>

long strip_trailing_digits(long n, long digit)
{
    if (n % 10 == digit) {
        return strip_trailing_digits(n / 10, digit);
    }
    return n;
}

long count_trailing_digits(long n, long digit)
{
    if (n % 10 == digit) {
        return 1 + count_trailing_digits(n / 10, digit);
    }
    return 0;
}

int main()
{
    long n;
    scanf("%ld", &n);

    long mco;
    long cnt = 0;

    while (n > 0) {
        long curr_mco = n % 10;
        long count = count_trailing_digits(n, n % 10);

        if (count > cnt) {
            cnt = count;
            mco = curr_mco;
        }

        n = strip_trailing_digits(n, n % 10);
    }

    printf("%ld %ld\n", mco, cnt);
}
