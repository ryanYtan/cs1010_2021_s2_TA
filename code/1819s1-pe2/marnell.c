#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// O(sqrt(n))
long is_prime(long n)
{
    if (n <= 1)
        return false;
    for (long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return i;
        }
    }
    return -1;
}

// O(sqrt(n))
bool is_semiprime(long n)
{
    if (n <= 1)
        return false;

    long div = is_prime(n);
    if (div == -1) {
        return false;
    }

    div = is_prime(n / div);

    if (div == -1) {
        return true;
    }
    return false;
}

int main()
{
    long n;
    scanf("%ld", &n);

    long i = 1;
    long j = n;
    long counter = 0;

    for (long i = 2; i <= n; i++) {
        long j = n - i;

        if (is_prime(i) == -1 && is_semiprime(j)) {
            counter++;
        }
    }

    printf("%ld\n", counter);
}
