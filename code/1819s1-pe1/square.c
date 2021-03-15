#include <stdio.h>
#include <stdlib.h>
#define HEX "#"
#define SPC " "

void draw_square(long row, long width)
{
    if (width == 1) {
        printf(HEX);
    } else if (row == 0 || row == width - 1) {
        for (long i = 0; i < width; i++) {
            printf(HEX);
        }
    } else if (row == 1 || row == width - 2) {
        printf(HEX);
        for (long i = 0; i < width - 2; i++) {
            printf(SPC);
        }
        printf(HEX);
    } else {
        printf(HEX);
        printf(SPC);
        draw_square(row - 2, width - 4);
        printf(SPC);
        printf(HEX);
    }
}

int main()
{
    long n;
    scanf("%ld", &n);

    for (long i = 0; i < n; i++) {
        draw_square(i, n);
        printf("\n");
    }
}
