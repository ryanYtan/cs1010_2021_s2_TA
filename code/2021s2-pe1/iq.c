#include <stdio.h>

double iq(long verbal, long math)
{
    return (0.003 * (double)verbal) + (0.095 * (double)math) + 50.241;
}

int main()
{
    long verbal;
    long math;
    scanf("%ld %ld", &verbal, &math);

    printf("%ld\n", (long)iq(verbal, math));
}
