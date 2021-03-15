#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(long n)
{
    if (n <= 1) {
        return false;
    }

    long until = sqrt(n);

    for (long i = 2; i <= until; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    long n;
    scanf("%ld", &n);

    long count = 0;

    long until = n / 2;

    for (long i = 0; i <= until; i++) {
        for (long j = n; j >= until; j--) {
            if (i + j == n && is_prime(i) && is_prime(j)) {
                count++;
            }
        }
    }

    printf("%ld\n", count);
}
