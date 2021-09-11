//
// Created by liam on 8/29/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double PowerLoop(double n, int exp);

double PowerRecursive(double n, int exp);

int main(int args, char **argv) {
    double pow;
    double n = strtod(argv[1],NULL);
    long exp = strtol(argv[2],NULL,10);
    pow = PowerRecursive(n, exp);
    printf("%.2f to the power of %d is %.2f.\n", n, exp, pow);
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

