#include <stdio.h>

long difference(long a, long b)
{
    if (a == 0 || b == 0) {
        return 0;
    }

    long digit_a = a % 10;
    long digit_b = b % 10;

    if (digit_a == 0 && digit_b == 9) {
        return -1 + difference(a / 10, b / 10);
    } else if (digit_a == 9 && digit_b == 0) {
        return 1 + difference(a / 10, b / 10);
    } else if (digit_a < digit_b) {
        return 1 + difference(a / 10, b / 10);
    } else if (digit_a > digit_b) {
        return -1 + difference(a / 10, b / 10);
    } else {
        return 0 + difference(a / 10, b / 10);
    }
}

int main()
{
    long a;
    long b;
    scanf("%ld %ld", &a, &b);
    long diff = difference(a, b);

    if (diff < 0) {
        printf("A wins.\n");
    } else if (diff > 0) {
        printf("B wins.\n");
    } else {
        printf("No one wins.\n");
    }

    printf("%ld\n", diff > 0 ? diff : -diff);
}
