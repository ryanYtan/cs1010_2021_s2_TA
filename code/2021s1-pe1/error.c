/**
 * CS1010 Semester 1 AY20/21
 * Practical Exam 1: Error
 *
 * @file: error.c
 * @author: Ryan
 */
#include "cs1010.h"
#include <assert.h>

// calculates base^k for positive k
long ipow(long base, long k)
{
        assert(k >= 0);

        if (k > 0) {
                return base * ipow(base, k - 1);
        }

        return 1;
}

int main()
{
        long k = cs1010_read_long();
        long n = cs1010_read_long();

        long mult = ipow(10, k);

        long err = n % mult;

        cs1010_println_double(((double)err / n) * 100.0);
}
