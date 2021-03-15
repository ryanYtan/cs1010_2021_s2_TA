#include <stdio.h>
#include <math.h>

double f(double a, double b, double c, double d, double x)
{
    return a*x*x*x + b*x*x + c*x + d;
}

double df(double a, double b, double c, double x)
{
    return 3*a*x*x + 2*b*x + c;
}

int main()
{
    double a, b, c, d;
    double x;

    scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &x);

    double fx = f(a,b,c,d,x);

    while (fabs(fx) >= 0.000000001) {
        x = x - ((fx) / (df(a, b, c, x)));
        fx = f(a,b,c,d,x);
    }

    while ((fx = fabs(f(a,b,c,d,x))) >= 0.000000001) {
    }

    printf("%.4lf\n", x);
}
