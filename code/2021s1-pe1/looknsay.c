/**
 * CS1010 Semester 1 AY20/21
 * Practical Exam 1: LookNSay
 *
 * @file: looknsay.c
 * @author: Ryan
 */
#include "cs1010.h"

long strip_trailing_digits(long n)
{
        long digit = n % 10;
        while (n % 10 == digit) {
                n /= 10;
        }
        return n;
}

// If d is the last digit of n, count the number of trailing digits that
// are d
long count_trailing_digits(long n)
{
        long digit = n % 10;
        long counter = 0;
        while (n % 10 == digit) {
                n /= 10;
                counter++;
        }
        return counter;
}

/**
 * Returns the last 8 digits of n if n has more than 8 digits,
 * otherwise return n itself. Note that I don't handle the case where
 * n contains 0s since the question disallows it.
 */
long get_last_eight_numbers(long n)
{
        if (n < 100000000) {
                return n;
        }
        long result = 0;
        long mult = 1;
        for (long i = 0; i < 8; i++) {
                long digit = n % 10;
                result += (digit * mult);
                n /= 10;
                mult *= 10;
        }
        return result;
}

long get_next_in_sequence(long n)
{
        long result = 0;

        long mult = 1;

        while (n > 0) {
                long digit = n % 10;
                long count = count_trailing_digits(n);

                result += (digit * mult);
                mult *= 10;

                result += (count * mult);
                mult *= 10;

                n = strip_trailing_digits(n);
        }

        return result;
}

long sequence(long n, long k)
{
        for (long i = 0; i < k - 1; i++) {
                long last_eight = get_last_eight_numbers(n);
                long next = get_next_in_sequence(last_eight);
                n = next;
        }
        return n;
}

int main()
{
        long n = cs1010_read_long();
        long k = cs1010_read_long();

        cs1010_println_long(sequence(n, k));
}
