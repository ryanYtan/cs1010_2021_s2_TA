/**
 * CS1010 Semester 1 AY20/21
 * Practical Exam 1: Factors
 *
 * @file: factors.c
 * @author: Ryan Tan Yu
 */
#include "cs1010.h"
#include <math.h>
#include <stdbool.h>

// prints in the format "{num} {count}" to stdout
void print_num_and_count(long num, long count)
{
        cs1010_print_long(num);
        cs1010_print_string(" ");
        cs1010_println_long(count);
}

// checks if a number n is prime
// any negative number and 0 is not prime
// 1 is not prime
bool is_prime(long n)
{
        if (n <= 1) {
                return false;
        }
        long until = lrint(sqrt(n));
        for (long i = 2; i <= until; i++) {
                if (n % i == 0) {
                        return false;
                }
        }
        return true;
}

// returns the number of times n is divisible by div
long number_of_times_divisible_by(long n, long div)
{
        long ctr = 0;
        while (n % div == 0) {
                ctr++;
                n /= div;
        }
        return ctr;
}

// returns the result of dividing n by div until n cannot be divided by
// div
long divide_by(long n, long div)
{
        while (n % div == 0) {
                n /= div;
        }
        return n;
}

void print_factors(long n)
{
        if (is_prime(n)) {
                print_num_and_count(n, 1);
                return;
        }

        for (long i = 2; i <= n; i++) {
                if (!is_prime(i)) {
                        continue;
                }

                long div_num = number_of_times_divisible_by(n, i);
                if (div_num > 0) {
                        print_num_and_count(i, div_num);
                        n = divide_by(n, i);
                }
        }
}

int main()
{
        long n = cs1010_read_long();

        print_factors(n);
}
