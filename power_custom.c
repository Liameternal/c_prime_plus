//
// Created by liam on 8/24/21.
//
#include <stdio.h>
#include <math.h>

double PowerLoop(double n, int exp);

double PowerRecursive(double n, int exp);

int main(void) {
    double n;
    int exp;
    double pow;
    printf("Enter a number and a exponent(q to exit):");
    while (scanf("%lf %d", &n, &exp)) {
        pow = PowerRecursive(n, exp);
        printf("%.2f to the power of %d is %.2f.\n", n, exp, pow);
        printf("Enter a number and a exponent(q to exit):");
    }
    return 0;
}

double PowerLoop(double n, int exp) {
    if (n == 0) {
        if (exp != 0)
            return 0;
        else {
            printf("0 to the power of 0 is not defined. "
                   "Treat as 1.\n");
            return 1;
        }
    }
    if (exp == 0)
        return 1;
    double pow = 1;
    for (int i = 1; i <= fabs(exp); ++i) {
        pow *= n;
    }
    if (exp < 0)
        return 1 / pow;
    else
        return pow;
}

double PowerRecursive(double n, int exp) {
    if (n == 0) {
        if (exp != 0)
            return 0;
        else {
            printf("0 to the power of 0 is not defined. "
                   "Treat as 1.\n");
            return 1;
        }
    }
    if (exp == 0)
        return 1;
    double pow;
    pow = n * PowerRecursive(n, fabs(exp) - 1);
    if (exp < 0)
        return 1 / pow;
    else
        return pow;
}
