#include <stdio.h>

int main()
{
    long n, m;
    scanf("%ld %ld", &n, &m);

    long total = n + m;

    printf("%.4lf ", ((double)n / total) * 100.0);
    printf("%.4lf\n", ((double)m / total) * 100.0);
}
