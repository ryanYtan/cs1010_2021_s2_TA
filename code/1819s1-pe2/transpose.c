#include <stdio.h>
#include <stdlib.h>

double **transpose(double **mat, long m, long n)
{
    double **transposed = malloc(n * sizeof(double*));
    for (long i = 0; i < n; i++) {
        transposed[i] = malloc(m * sizeof(double));
    }

    for (long i = 0; i < m; i++) {
        for (long j = 0; j < n; j++) {
            transposed[j][i] = mat[i][j];
        }
    }
    return transposed;
}

int main()
{
    long m;
    long n;
    scanf("%ld %ld", &m, &n);

    double **mat = malloc(m * sizeof(double*));
    for (long i = 0; i < m; i++) {
        mat[i] = malloc(n * sizeof(double));
    }

    for (long i = 0; i < m; i++) {
        for (long j = 0; j < n; j++) {
            scanf("%lf", &mat[i][j]);
        }
    }

    double **transposed = transpose(mat, m, n);

    for (long i = 0; i < n; i++) {
        printf("%.4lf", transposed[i][0]);
        for (long j = 1; j < m; j++) {
            printf(" %.4lf", transposed[i][j]);
        }
        printf("\n");
    }

    for (long i = 0; i < m; i++) {
        free(mat[i]);
    }
    for (long i = 0; i < n; i++) {
        free(transposed[i]);
    }
    free(mat);
    free(transposed);
}
