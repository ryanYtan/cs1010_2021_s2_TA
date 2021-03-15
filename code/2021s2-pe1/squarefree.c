#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_square_free(long n)
{
    for (long i = 2; i <= sqrt(n); i++) {
        long sqr = i * i;
        if (n % sqr == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    long lower;
    long upper;
    scanf("%ld %ld", &lower, &upper);

    long counter = 0;
    for (long i = lower; i <= upper; i++) {
        if (is_square_free(i)) {
            counter++;
        }
    }
    printf("%ld\n", counter);
}
