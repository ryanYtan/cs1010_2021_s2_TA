#include <stdio.h>
#include <stdlib.h>

long search_rotated(long *arr, long i, long j, long q)
{
    long mid = (i + j) / 2;

    if (i > j) {
        return -1;
    }

    if (arr[mid] == q) {
        return mid;
    }

    if (arr[mid] > q) {
        if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1]) {

        } else {

        }
    }

    if (arr[mid] < q) {
        if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1]) {

        } else {

        }
    }
}

int main()
{
    long n;
    scanf("%ld", &n);

    long *arr = malloc(n * sizeof(long));

    for (long i = 0; i < n; i++) {
        scanf("%ld", &arr[i]);
    }

    long q;
    scanf("%ld", &q);
}
