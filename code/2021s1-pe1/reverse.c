/**
 * CS1010 Semester 1 AY20/21
 * Practical Exam 1: Reverse
 *
 * @file: reverse.c
 * @author: Ryan
 */
#include "cs1010.h"
#include <assert.h>

long strip_trailing_zeroes(long n)
{
        if (n % 10 ==0) {
                return strip_trailing_zeroes(n / 10);
        }
        return n;
}

// calculates base^k for positive k
long ipow(long base, long k)
{
        assert(k >= 0);

        if (k > 0) {
                return base * ipow(base, k - 1);
        }

        return 1;
}

// returns the number of digits in n
long ndigits(long n)
{
        if (n > 0) {
                return 1 + ndigits(n / 10);
        }
        return 0;
}

long reverse(long n, long ndigits)
{
        if (n > 0) {
                long digit = n % 10;
                long sum = digit * ipow(10, ndigits - 1);
                return sum + reverse(n / 10, ndigits - 1);
        }
        return 0;
}

int main()
{
        long n = cs1010_read_long();
        n = strip_trailing_zeroes(n);
        n = reverse(n, ndigits(n));
        n = n * n;
        cs1010_println_long(n);
}
